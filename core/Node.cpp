//
// Created by bishan_ on 12/1/23.
//

#include "Node.hpp"
#include <ranges>
#include <utility>

#include "StringName.hpp"

void Node::initialise() {
	for (const auto&child: std::ranges::views::values(children)) {
		child->inside_tree = child->parent->inside_tree;

		if (!child->is_initialised) {
			child->initialise();
		}

		if (child->parent->inside_tree) {
			child->tree_entered();
		}
	}
	ready();
}

void Node::ready() {}
void Node::process(f32 dt) {}
void Node::physics_process(f32 dt) {}
void Node::tree_entered() {}
void Node::tree_exited() {}
void Node::free() {}

Node::Node() : Node("Node") {}

Node::Node(const std::string&name) : Node(StringName(name)) {}

Node::Node(StringName name) noexcept : name(std::move(name)) {}

void Node::add_child(Node* child) {
	if (child->parent || child->is_inside_tree())
		return;

	std::string name = child->name;

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

Node* Node::get_child(const std::string&path) {
	return children.at(path).get();
}

const Node* Node::get_child(const std::string&path) const {
	return children.at(path).get();
}

std::optional<Node *> Node::get_child_or_none(const std::string&path) {
	return children.contains(path) ? std::optional(children.at(path).get()) : std::nullopt;
}

std::optional<const Node *> Node::get_child_or_none(const std::string&path) const {
	return children.contains(path) ? std::optional(children.at(path).get()) : std::nullopt;
}

void Node::queue_free() {}

StringName Node::get_name() const noexcept {
	return name;
}

bool Node::is_inside_tree() const noexcept {
	return inside_tree;
}

const char* Node::type_id() const noexcept {
	return "Node";
}
