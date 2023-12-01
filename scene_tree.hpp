//
// Created by bishan_ on 12/1/23.
//

#ifndef SCENE_TREE_HPP
#define SCENE_TREE_HPP

#include <set>

#include "node.h"


class SceneTree final {
  std::unique_ptr<Node> root;

  std::set<Node *> queued_to_delete;

  SceneTree();

public:
  static std::unique_ptr<SceneTree> build_singleton();
};


#endif //SCENE_TREE_HPP
