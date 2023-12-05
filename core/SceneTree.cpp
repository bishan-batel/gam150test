//
// Created by bishan_ on 12/1/23.
//

#include "core/SceneTree.hpp"

#include <chrono>
#include <ctime>
#include <thread>

std::unique_ptr<SceneTree> SceneTree::build_singleton() {
  auto tree = std::unique_ptr<SceneTree>(new SceneTree());
  return std::move(tree);
}


SceneTree::SceneTree() {
  root = std::make_unique<Node>();
  root->tree = this;
  root->initialise();

  last_process_frame = std::chrono::system_clock::now().time_since_epoch();
}


void SceneTree::update() {
  using namespace std::chrono;

  const auto per_frame = 1s / target_frame_rate;
  const auto now = system_clock::now().time_since_epoch();

  if (now - last_process_frame < per_frame)
    return;

  root->process(duration_cast<duration<f32>>(now - last_process_frame).count());

  last_process_frame = now;
  std::this_thread::sleep_for(per_frame);

  post_frame();
}


void SceneTree::render() const {
  for (const auto &node : to_render) {
    node->render();
  }
}

void SceneTree::post_frame() {

  // process deletion queue

  while (!queued_to_delete.empty()) {
    auto to_delete = std::move(queued_to_delete.front());
    queued_to_delete.pop();
  }
}

void SceneTree::full_shutdown() const {
  root->on_free();
}
