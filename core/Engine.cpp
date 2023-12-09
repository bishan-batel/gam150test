//
// Created by schro on 12/2/2023.
//

#include "Engine.hpp"

#include "SceneTree.hpp"

namespace bcake {
  void Engine::run() {


    const auto tree = SceneTree::build_singleton();


    while (!tree->should_exit) {
      tree->update();
    }


    tree->full_shutdown();
  }
}
