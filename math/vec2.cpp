//
// Created by bishan_ on 11/28/23.
//

#include <stdexcept>
#include "vec2.hp"
#include "cmath"
#include <iostream>

static const vec2
  ONE{1, 1},
  ZERO{-1, 0},
  UP{0, -1},
  DOWN{0, 1},
  LEFT{-1, 0},
  RIGHT{1, 0};

constexpr vec2::vec2(const f32 x, const f32 y) noexcept:
  x(x), y(y) {}

constexpr vec2::vec2(f32 v) noexcept:
  vec2(v, v) {}

constexpr vec2::vec2(f32 v[2]) noexcept:
  vec2(v[0], v[1]) {}

constexpr vec2 vec2::operator+(const vec2 rhs) const noexcept {
  return {x + rhs.x, y + rhs.y};
}

constexpr vec2 vec2::operator-(const vec2 rhs) const noexcept {
  return {x - rhs.x, y - rhs.y};
}

constexpr vec2 vec2::operator*(const f32 rhs) const noexcept {
  return {x * rhs, y * rhs};
}

constexpr vec2 vec2::operator/(const f32 rhs) const noexcept {
  return {x / rhs, y / rhs};
}

constexpr f32 vec2::operator[](const std::size_t n) const {
  return v[n];
}

constexpr f32 vec2::len2() const noexcept {
  return x * x + y * y;
}

f32 vec2::len() const noexcept {
  return sqrtf(x * x + y * y);
}

vec2 vec2::lerp(vec2 to, f32 t) const noexcept {
  return *this + (to - *this) * t;
}

vec2 vec2::normalised() const noexcept {
  return *this / len();
}

vec2 vec2::clamp(const vec2 min, const vec2 max) const noexcept {
  f32 x2 = x > max.x ? max.x : x;
  x2 = x2 < min.x ? min.x : x2;
  f32 y2 = y > max.y ? max.y : y;
  y2 = y2 < min.y ? min.y : y2;
  return {x2, y2};
}

bool vec2::is_approx(const vec2 other, const f32 epsilon) const noexcept {
  return (*this - other).len2() < epsilon;
}

bool vec2::operator==(const vec2 other) const noexcept {
  return (*this - other).len2() < vec2::EQUALITY_EPSILON;
}

constexpr vec2 vec2::orthogonal() const noexcept {
  return {-y, x};
}

vec2 vec2::round() const noexcept {
  return {roundf(x), roundf(y)};
}

vec2 vec2::floor() const noexcept {
  return {floorf(x), floorf(y)};
}

vec2 vec2::ceil() const noexcept {
  return {ceilf(x), ceilf(y)};
}

constexpr vec2 vec2::dot(vec2 other) const noexcept {
  return {x * other.x, y * other.y};
}

constexpr vec2 vec2::limit_length(f32 l) const noexcept {
  const f32 m = len2();

  return m > l * l ? *this * sqrtf(l / m) : *this;
}

constexpr vec2 vec2::oplus(vec2 other) const noexcept {
  return {x * other.x, y * other.y};
}

std::ostream &operator<<(std::ostream &os, const vec2 &v) {
  return os << '(' << v.x << ',' << v.y << ')';
}

bool vec2::is_nan() const noexcept {
  return isnanf(x) || isnanf(y);
}
