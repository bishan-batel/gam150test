//
// Created by bishan_ on 12/1/23.
//

#ifndef NODE_H
#define NODE_H
#include "number.h"
#include <map>
#include <memory>
#include <optional>
#include <string>


class Node {
  friend class RootNode;

public:
  static constexpr std::string PATH_DELIMETER = "/";

private:
  bool queued_for_deletion = true,
       inside_tree = false,
       is_initialised = false;


  std::map<std::string, std::unique_ptr<Node>> children;
  Node *parent = nullptr;

  std::string name = type_id();

  void initialise();

protected:
  virtual void ready();
  virtual void process(f32 dt);
  virtual void physics_process(f32 dt);
  virtual void render() const;

  virtual void tree_entered();
  virtual void tree_exited();

  virtual void free();

public:
  Node();
  explicit Node(std::string name);
  virtual ~Node() = default;

  void add_child(Node *child);

  template <typename T>
  void add_child(T *child) {
    add_child(dynamic_cast<Node *>(child));
  }

  Node *get_child(const std::string &path);

  std::optional<Node *> get_child_or_none(const std::string &path);

  [[nodiscard]] const Node *get_child(const std::string &path) const;

  [[nodiscard]] std::optional<const Node *> get_child_or_none(const std::string &path) const;

  void queue_free();

  [[nodiscard]] std::string get_name() const;

  [[nodiscard]] bool is_inside_tree() const;
  [[nodiscard]] virtual std::string type_id() const;
};

#endif //NODE_H
