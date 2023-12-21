//
// Created by schro on 12/2/2023.
//

#include "CanvasItem.hpp"

#include "core/SceneTree.hpp"


namespace bcake {
  bool CanvasItem::ZSort::operator()(const CanvasItem *const &lhs, const CanvasItem *const &rhs) const noexcept {
    return lhs->global_z_index >= rhs->global_z_index;
  }

  void CanvasItem::register_to_tree() {
    get_tree()->to_render.push_back(this);
  }

  void CanvasItem::unregister_to_tree() {
    auto &to_render = get_tree()->to_render;
    to_render.erase(std::ranges::find(to_render, this));
  }

  void CanvasItem::render() const {}

  const char *CanvasItem::type_id() const noexcept {
    return "CanvasItem";
  }
}
