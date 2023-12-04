//
// Created by bishan_ on 12/1/23.
//

#ifndef NODE_H
#define NODE_H
#include <math\number.hpp>
#include <map>
#include <memory>
#include <optional>
#include <string>

#include "StringName.hpp"


class StringName;

class Node {
	friend class RootNode;

private:
	bool queued_for_deletion = true,
			inside_tree = false,
			is_initialised = false;


	std::map<std::string, std::unique_ptr<Node>> children;
	Node* parent = nullptr;

	StringName name = {type_id()};

	void initialise();

protected:
	virtual void ready();

	virtual void process(f32 dt);

	virtual void physics_process(f32 dt);

	virtual void tree_entered();

	virtual void tree_exited();

	virtual void free();

public:
	Node();

	explicit Node(const std::string&name);

	explicit Node(StringName name) noexcept;

	virtual ~Node() = default;

	void add_child(Node* child);

	template<typename T>
	void add_child(T* child) {
		add_child(dynamic_cast<Node *>(child));
	}

	Node* get_child(const std::string&path);

	std::optional<Node *> get_child_or_none(const std::string&path);

	[[nodiscard]] const Node* get_child(const std::string&path) const;

	[[nodiscard]] std::optional<const Node *> get_child_or_none(const std::string&path) const;

	void queue_free();

	[[nodiscard]] StringName get_name() const noexcept;

	[[nodiscard]] bool is_inside_tree() const noexcept;

	[[nodiscard]] virtual const char* type_id() const noexcept;
};

#endif //NODE_H
