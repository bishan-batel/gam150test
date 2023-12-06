//
// Created by bishan_ on 12/1/23.
//

#include "core/SceneTree.hpp"

#include <Texture.hpp>
#include <chrono>
#include <thread>
#include <utility>

#include "local/iso_test.hpp"
#include "nodes/sprite_node.hpp"

std::unique_ptr<SceneTree> SceneTree::build_singleton() {
  auto tree = std::unique_ptr<SceneTree>(new SceneTree());
  return std::move(tree);
}


SceneTree::SceneTree() {
  window.Init(1000, 1000, "bruh");
  window.SetTargetFPS(static_cast<i32>(target_frame_rate));

  to_render.clear();

  root = std::make_unique<IsoTestScene>();


  root->tree = this;
  std::cout << root->tree << std::endl;
  root->inside_tree = true;

  root->initialise();

  last_process_frame = std::chrono::system_clock::now().time_since_epoch();
}


void SceneTree::update() {
  using namespace std::chrono;

  const auto per_frame = 1s / target_frame_rate;
  const auto now = system_clock::now().time_since_epoch();

  should_exit = window.ShouldClose();

  if (now - last_process_frame < per_frame)
    return;

  root->process(duration_cast<duration<f32>>(now - last_process_frame).count());

  last_process_frame = now;
  std::this_thread::sleep_for(per_frame);

  post_frame();

  render();
}


void SceneTree::render() {
  window.BeginDrawing();
  window.ClearBackground(RAYWHITE);

  for (const auto &node : to_render) {
    node->render();
  }

  window.EndDrawing();
  window.DrawFPS();
}

void SceneTree::post_frame() {
  while (!queued_to_initialise.empty()) {
    queued_to_initialise.front()->initialise();
    queued_to_initialise.pop();
  }

  // process deletion queue
  while (!queued_to_delete.empty()) {
    const std::unique_ptr<Node> to_delete = std::move(queued_to_delete.front());
    to_delete->free();
    queued_to_delete.pop();
  }

  if (not queued_next_scene)
    return;

  root->free();
  root = std::move(*queued_next_scene);
  queued_next_scene = std::nullopt;

  root->tree = this;
  std::cout << root->tree << std::endl;
  root->inside_tree = true;

  root->initialise();
}

void SceneTree::full_shutdown() const {
  root->free();
}


void SceneTree::change_scene(std::unique_ptr<Node> node) {
  queued_next_scene = std::move(node);
}
