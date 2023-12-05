//
// Created by schro on 12/2/2023.
//

#include "CanvasItem.hpp"


bool CanvasItem::ZSort::operator()(const CanvasItem *const &lhs, const CanvasItem *const &rhs) const noexcept {
  return lhs->global_z_index <= rhs->global_z_index;
}

void CanvasItem::register_to_tree() const {
}

void CanvasItem::render() const {}

const char *CanvasItem::type_id() const noexcept {
  return "CanvasItem";
}
