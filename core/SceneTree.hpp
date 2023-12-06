//
// Created by bishan_ on 12/1/23.
//

#ifndef SCENE_TREE_HPP
#define SCENE_TREE_HPP

#include <Window.hpp>
#include <chrono>
#include <functional>
#include <queue>
#include <set>

#include "Node.hpp"
#include "nodes/CanvasItem.hpp"


class SceneTree final {
  friend class Engine;
  friend class Node;
  friend class CanvasItem;

  std::unique_ptr<Node> root;

  std::queue<std::unique_ptr<Node>> queued_to_delete;
  std::queue<Node *> queued_to_initialise;

  // std::set<const CanvasItem *, CanvasItem::ZSort> to_render{};
  std::vector<CanvasItem *> to_render{};

  const f32 target_frame_rate = 60.f;
  std::chrono::duration<f64> last_process_frame{};

  raylib::Window window;

  bool should_exit = false;


  SceneTree();

  void update();
  void render();

  void post_frame();

  void full_shutdown() const;

public:
  static std::unique_ptr<SceneTree> build_singleton();
};


#endif //SCENE_TREE_HPP
