//
// Created by bishan_ on 12/1/23.
//

#ifndef SCENE_TREE_HPP
#define SCENE_TREE_HPP

#include <chrono>
#include <functional>
#include <queue>
#include <set>

#include "Node.hpp"
#include "nodes/CanvasItem.hpp"


class SceneTree final {
  friend class Engine;
  friend class Node;

  std::unique_ptr<Node> root;

  std::queue<std::unique_ptr<Node>> queued_to_delete;
  std::set<const CanvasItem *, CanvasItem::ZSort> to_render{};

  const f32 target_frame_rate = 60.f;
  std::chrono::duration<f64> last_process_frame{};

  bool should_exit = false;


  SceneTree();

  void update();
  void render() const;

  void post_frame();

  void full_shutdown() const;

  void free_root();

  void register_node(const Node *node);
  void unregister_node(const Node *node);

public:
  static std::unique_ptr<SceneTree> build_singleton();

};


#endif //SCENE_TREE_HPP
