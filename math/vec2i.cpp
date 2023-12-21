//
// Created by bishan_ on 12/8/23.
//

#include "vec2i.hpp"

#include <cmath>

vec2i::vec2i(const i32 x, const i32 y) noexcept:
  x(x), y(y) {}

vec2i::vec2i(const i32 v) noexcept :
  vec2i(v, v) {}

vec2i::vec2i(const vec2 vec) noexcept :
  vec2i(static_cast<i32>(vec.x), static_cast<i32>(vec.y)) {}

vec2i::operator vec2() const noexcept {
  return {static_cast<f32>(x), static_cast<f32>(y)};
}

f32 vec2i::aspect_ratio() const noexcept {
  return static_cast<f32>(x) / static_cast<f32>(y);
}

f32 vec2i::len() const noexcept {
  return std::sqrt(static_cast<f32>(x * x + y * y));
}

i32 vec2i::len2() const noexcept {
  return x * x + y * y;
}

vec2i vec2i::operator+(const vec2i other) const noexcept {
  return {x + other.x, y + other.y};
}

vec2i vec2i::operator-(const vec2i other) const noexcept {
  return {x - other.x, y - other.y};
}

vec2i vec2i::operator*(const vec2i other) const noexcept {
  return {x * other.x, y * other.y};
}

vec2i vec2i::operator/(const vec2i other) const noexcept {
  return {x / other.x, y / other.y};
}

vec2i vec2i::operator*(const i32 scalar) const noexcept {
  return {x * scalar, y * scalar};
}

vec2 vec2i::operator*(const f32 scalar) const noexcept {
  return vec2(*this) * scalar;
}

vec2i vec2i::operator/(const i32 scalar) const noexcept {
  return {x / scalar, y / scalar};
}

vec2i &vec2i::operator*=(const i32 scalar) noexcept {
  return *this = *this * scalar;
}

vec2i &vec2i::operator/=(const i32 dividend) noexcept {
  return *this = *this / dividend;
}

vec2i &vec2i::operator+=(const vec2i rhs) noexcept {
  return *this = *this + rhs;
}

vec2i &vec2i::operator-=(const vec2i rhs) noexcept {
  return *this = *this - rhs;
}

vec2i &vec2i::operator*=(const vec2i rhs) noexcept {
  return *this = *this * rhs;
}

vec2i &vec2i::operator/=(const vec2i rhs) noexcept {
  return *this = *this / rhs;
}

vec2i operator*(const i32 scalar, const vec2i other) noexcept {
  return other * scalar;
}

vec2 operator*(const f32 scalar, const vec2i other) noexcept {
  return other * scalar;
}
