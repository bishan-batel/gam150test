//
// Created by bishan_ on 12/8/23.
//

#include "vec2i.hpp"

vec2i::vec2i(const i32 x, const i32 y) noexcept:
  x(x), y(y) {}

vec2i::vec2i(const i32 v) noexcept :
  vec2i(v, v) {}

vec2i::vec2i(const vec2 vec) noexcept :
  vec2i(static_cast<i32>(vec.x), static_cast<i32>(vec.y)) {}
