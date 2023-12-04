//
// Created by bishan_ on 12/1/23.
//

#include "core/SceneTree.hpp"
#include "RootNode.hpp"

SceneTree::SceneTree() {
	root = std::unique_ptr<RootNode>(new RootNode());
}

std::unique_ptr<SceneTree> SceneTree::build_singleton() {
	auto tree = std::unique_ptr<SceneTree>(new SceneTree());

	return std::move(tree);
}
