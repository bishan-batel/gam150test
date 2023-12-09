//
// Created by bishan_ on 12/1/23.
//

#ifndef SCENE_TREE_HPP
#define SCENE_TREE_HPP

#include <chrono>
#include <functional>
#include <queue>
#include <set>

#include <SDL2/SDL.h>
#include "Node.hpp"
#include "math/color.hpp"
#include "math/vec2i.hpp"
#include "nodes/CanvasItem.hpp"

namespace bcake {
  class SceneTree final {
    friend class Engine;
    friend class Node;
    friend class CanvasItem;

    std::unique_ptr<Node> root;

    std::queue<std::unique_ptr<Node>> queued_to_delete;
    std::queue<Node *> queued_to_initialise;
    std::optional<std::unique_ptr<Node>> queued_next_scene = std::nullopt;

    // std::set<const CanvasItem *, CanvasItem::ZSort> to_render{};
    std::vector<CanvasItem *> to_render{};

    SDL_Window *window = nullptr;
    SDL_GLContext gl_context{};

    vec2i window_size;
    color clear_color = color::rgba(0.3f, 0.2f, 0.2f, 1.f);

    const f32 target_frame_rate = 60.f;
    std::chrono::duration<f64> last_process_frame{};

    bool should_exit = false;


    SceneTree();

    void update();
    void render() const;

    void process_input();
    void post_frame();


    void full_shutdown() const;

  public:
    static std::unique_ptr<SceneTree> build_singleton();


    void change_scene(std::unique_ptr<Node> node);

    template <typename T>
    void change_scene(std::unique_ptr<T> node) {
      change_scene(std::unique_ptr<Node>(dynamic_cast<Node *>(node.release())));
    }
  };

}

#endif //SCENE_TREE_HPP
