//
// Created by bishan_ on 12/1/23.
//

#include "Node.hpp"
#include <ranges>
#include <utility>

#include "SceneTree.hpp"
#include "StringName.hpp"

Node::Node() = default;

void Node::initialise() {
  for (const auto &child : std::ranges::views::values(children)) {
    asm("nop");
    child->inside_tree = inside_tree;
    child->tree = tree;

    if (!child->is_initialised) {
      child->initialise();
    }
  }

  if (is_inside_tree()) {
    register_to_tree();
    tree_entered();
  }
  ready();
  is_initialised = true;
}

void Node::register_to_tree() {}

void Node::unregister_to_tree() {}

void Node::ready() {}

void Node::process(f32 dt) {}

void Node::physics_process(f32 dt) {}

void Node::tree_entered() {}

void Node::tree_exited() {}

void Node::on_free() {}


void Node::add_child(Node *child) {
  if (child->parent || child->is_inside_tree())
    return;

  std::string child_name = child->name.empty()
    ? std::string(child->type_id())
    : std::string(child->name);

  while (children.contains(child_name)) {
    const auto rand = static_cast<char>(std::hash<std::string>()(child_name) % ('z' - 'a') + 'a');
    child_name.append(std::string(1, rand));
  }

  child->name = child_name;
  child->parent = this;
  children[child_name] = std::unique_ptr<Node>(child);

  if (is_inside_tree()) {
    child->inside_tree = true;
    child->tree = tree;

    if (!child->is_initialised) {
      tree->queued_to_initialise.push(child);
    }
  }
}

Node *Node::get_child(const NodePath &path) {
  // path.segments;
  auto node = this;

  for (u16 i = 0; i < path.parent_indirection; i++) {
    node = node->parent;
  }

  for (const auto &segment : path.segments) {
    node = node->children[segment].get();
  }

  return node;
}

std::optional<std::unique_ptr<Node>> Node::remove_child(const Node *child) {
  if (!children.contains(child->name))
    return std::nullopt;


  auto ref = std::move(children.at(child->name));

  children.erase(child->name);
  return ref;
}

std::optional<Node *> Node::get_child_or_none(const NodePath &path) {
  auto node = this;

  for (u16 i = 0; i < path.parent_indirection; i++) {
    node = node->parent;
    if (node == nullptr)
      return std::nullopt;
  }

  for (const auto &segment : path.segments) {
    if (node->children.contains(segment))
      node = node->children.at(segment).get();
    if (node == nullptr)
      return std::nullopt;
  }

  return node;
}

std::vector<Node *> Node::get_children() {
  std::vector<Node *> children_vec;

  for (const auto &child : std::views::values(children))
    children_vec.push_back(child.get());

  return children_vec;
}


void Node::queue_free() {
  if (queued_for_deletion)
    return;

  if (!is_inside_tree()) {
    free();
    return;
  }

  queued_for_deletion = true;

  if (!parent)
    return;

  const auto &a = parent->children;
  const auto &n = name;


  if (const auto unique = parent->children.extract(name); not unique.empty()) {
    tree->queued_to_delete.push(std::move(unique.mapped()));
  }

}

void Node::free() {

  for (const auto &child : std::views::values(children)) {
    child->free();
  }

  inside_tree = false;
  unregister_to_tree();
  on_free();
}

StringName Node::get_name() const noexcept {
  return {name};
}

SceneTree *Node::get_tree() const noexcept {
  return tree;
}

void Node::set_name(const StringName &name) noexcept {
  this->name = StringName(name);
}

bool Node::is_inside_tree() const noexcept {
  return inside_tree;
}

const char *Node::type_id() const noexcept {
  return "Node";
}
