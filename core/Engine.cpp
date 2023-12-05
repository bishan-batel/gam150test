//
// Created by schro on 12/2/2023.
//

#include "Engine.hpp"

#include <thread>

void Engine::run() {
  const auto tree = SceneTree::build_singleton();

  std::thread thread([] {
    std::cout << "bruh" << std::endl;
  });

  while (!tree->should_exit) {
    tree->update();
  }
  tree->full_shutdown();

  thread.join();
}
