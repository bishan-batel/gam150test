//
// Created by bishan_ on 12/1/23.
//

#include "scene_tree.hpp"

#include "root_node.hpp"

SceneTree::SceneTree() {
  root = std::make_unique<RootNode>();
}

std::unique_ptr<SceneTree> SceneTree::build_singleton() {
  auto tree = std::unique_ptr<SceneTree>(new SceneTree());

  return std::move(tree);
}
