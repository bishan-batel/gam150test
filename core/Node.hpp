//
// Created by bishan_ on 12/1/23.
//

#ifndef NODE_H
#define NODE_H
#include <map>
#include <memory>
#include <optional>
#include <ranges>
#include <string>
#include <math/number.hpp>

#include "node_path.hpp"
#include "string_name.hpp"


namespace bcake {
  // Forward declaration required for this instance
  class SceneTree;

  class Node {
    friend class SceneTree;

    bool queued_for_deletion = false,
         inside_tree = false,
         is_initialised = false;


    std::map<std::string, std::unique_ptr<Node>> children;
    Node *parent = nullptr;
    SceneTree *tree = nullptr;

    std::string name;

    void initialise();

    virtual void register_to_tree();
    virtual void unregister_to_tree();

    void process_recurse(f32 dt);

  protected:
    virtual void ready();

    virtual void process(f32 dt);

    virtual void physics_process(f32 dt);

    virtual void tree_entered();

    virtual void tree_exited();

    virtual void on_free();

  public:
    Node();
    virtual ~Node() = default;

    void add_child(Node *child);

    template <typename T>
    void add_child(T *child) {
      add_child(dynamic_cast<Node *>(child));
    }

    Node *get_child(const node_path &path);

    template <typename T>
    T *get_child(const node_path &path) {
      return dynamic_cast<T*>(get_child(path));
    }

    std::optional<std::unique_ptr<Node>> remove_child(const Node *child);

    std::optional<Node *> get_child_or_none(const node_path &path);

    [[nodiscard]] std::vector<Node *> get_children();

    void free();

    void queue_free();

    [[nodiscard]] string_name get_name() const noexcept;

    [[nodiscard]] SceneTree *get_tree() const noexcept;

    void set_name(const string_name &name) noexcept;

    [[nodiscard]] bool is_inside_tree() const noexcept;

    [[nodiscard]] virtual const char *type_id() const noexcept;
  };
}
#endif //NODE_H
