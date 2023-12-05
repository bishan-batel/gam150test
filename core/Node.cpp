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
    child->inside_tree = child->parent->inside_tree;
    child->tree = child->parent->tree;

    if (!child->is_initialised) {
      child->initialise();
    }

    if (child->parent->inside_tree) {
      child->tree_entered();
    }
  }
  ready();
}

void Node::register_to_tree() const {}

void Node::unregister_to_tree() const {}

void Node::ready() {}
void Node::process(f32 dt) {}
void Node::physics_process(f32 dt) {}
void Node::tree_entered() {}
void Node::tree_exited() {}
void Node::on_free() {}


void Node::add_child(Node *child) {
  if (child->parent || child->is_inside_tree())
    return;

  std::string name = child->name.empty()
    ? std::string(child->type_id())
    : std::string(child->name);

  while (children.contains(name)) {
    name.append("@");
  }

  child->parent = this;
  children[name] = std::unique_ptr<Node>(child);

  if (is_inside_tree()) {
    child->inside_tree = true;

    if (!child->is_initialised)
      child->initialise();
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
  std::unique_ptr<Node> unique = std::move(parent->children[name]);
  parent->children.erase(name);
  tree->queued_to_delete.push(std::move(unique));
}

void Node::free() {

  // parent = nullptr;
  inside_tree = false;
  on_free();

  for (const auto &child : std::views::values(children)) {
    child->free();
  }
}

StringName Node::get_name() const noexcept {
  return StringName(name);
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
