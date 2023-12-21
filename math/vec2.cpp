//
// Created by bishan_ on 11/28/23.
//

#include "vec2.hpp"
#include <iostream>
#include <stdexcept>
#include "cmath"

const vec2
  vec2::ONE{1, 1},
  vec2::ZERO{-1, 0},
  vec2::UP{0, -1},
  vec2::DOWN{0, 1},
  vec2::LEFT{-1, 0},
  vec2::RIGHT{1, 0};

vec2::vec2(const f32 x, const f32 y) noexcept:
  x(x), y(y) {}

vec2::vec2(const f32 v) noexcept:
  vec2(v, v) {}

vec2::vec2(const f32 v[2]) noexcept:
  vec2(v[0], v[1]) {}

vec2 vec2::operator+(const vec2 rhs) const noexcept {
  return {x + rhs.x, y + rhs.y};
}

vec2 vec2::operator-(const vec2 rhs) const noexcept {
  return {x - rhs.x, y - rhs.y};
}

vec2 vec2::operator-() const noexcept {
  return {-x, -y};
}

vec2 vec2::operator*(const vec2 rhs) const noexcept {
  return {x * rhs.x, y * rhs.y};
}

vec2 &vec2::operator*=(const vec2 rhs) noexcept {
  return *this = *this * rhs;
}


vec2 vec2::operator%(const vec2 rhs) const noexcept {
  return {std::fmod(x, rhs.x), std::fmod(y, rhs.y)};
}

vec2 &vec2::operator%=(const vec2 rhs) noexcept {
  return *this = *this % rhs;
}

vec2 vec2::operator%(const f32 rhs) const noexcept {
  return {std::fmod(x, rhs), std::fmod(y, rhs)};
}

vec2 &vec2::operator%=(const f32 rhs) noexcept {
  return *this = *this % rhs;
}

vec2 vec2::operator*(const f32 rhs) const noexcept {
  return {x * rhs, y * rhs};
}

vec2 vec2::operator/(const f32 rhs) const noexcept {
  return {x / rhs, y / rhs};
}

vec2 &vec2::operator*=(const f32 scalar) {
  *this = *this * scalar;
  return *this;
}

vec2 &vec2::operator/=(const f32 scalar) {
  *this = *this / scalar;
  return *this;
}

vec2 &vec2::operator+=(const vec2 other) {
  *this = *this + other;
  return *this;
}

vec2 &vec2::operator-=(const vec2 other) {
  *this = *this - other;
  return *this;
}

vec3 vec2::as_vec3(f32 z) const noexcept {
  return {x, y, z};
}

vec3 vec2::homogeneous_point() const noexcept {
  return as_vec3(1.f);
}

vec3 vec2::homogeneous_vector() const noexcept {
  return as_vec3(0.f);
}


vec2 vec2::from_angle(const f32 theta) {
  return RIGHT.rotate(theta);
}

f32 vec2::len() const noexcept {
  return sqrtf(len2());
}

vec2 vec2::lerp(const vec2 to, const f32 t) const noexcept {
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
  return (*this - other).len2() < EQUALITY_EPSILON;
}

vec2 vec2::orthogonal() const noexcept {
  return {-y, x};
}

vec2 vec2::round() const noexcept {
  return {std::round(x), std::round(y)};
}

vec2 vec2::floor() const noexcept {
  return {std::floor(x), std::floor(y)};
}

vec2 vec2::ceil() const noexcept {
  return {std::ceil(x), std::ceil(y)};
}

f32 vec2::dot(const vec2 other) const noexcept {
  return x * other.x + y * other.y;
}

vec2 vec2::proj(const vec2 u) const noexcept {
  return normalised() * dot(u);
}

vec2 vec2::proj_perp(const vec2 u) const noexcept {
  return u - proj(u);
}

vec2 vec2::limit_length(const f32 l) const noexcept {
  const f32 m = len2();

  return m > l * l ? *this * sqrtf(l / m) : *this;
}

vec2 vec2::with_length(const f32 magnitude) const noexcept {
  return *this * std::sqrt(magnitude / len2());
}

vec2 vec2::with_heading(const f32 theta) const noexcept {
  return from_angle(theta) * len();
}

f32 vec2::heading() const noexcept {
  return angle_between(RIGHT);
}

f32 vec2::angle_between(const vec2 rhs) const noexcept {
  return std::acos(dot(rhs) / std::sqrt(rhs.len2() * len2()));
}

f32 vec2::angle_to(const vec2 rhs) const noexcept {
  return (rhs - *this).heading();
}

vec2 vec2::direction_to(const vec2 rhs) const noexcept {
  return (rhs - *this).normalised();
}

vec2 vec2::rotate(const f32 theta) const noexcept {
  const f32 cos = std::cos(theta), sin = std::sin(theta);
  return {cos * x - sin * y, sin * x + cos * y};
}

f32 vec2::distance(const vec2 rhs) const noexcept {
  return (*this - rhs).len();
}

f32 vec2::distance2(const vec2 rhs) const noexcept {
  return (*this - rhs).len2();
}

vec2 vec2::oplus(const vec2 other) const noexcept {
  return {x * other.x, y * other.y};
}

std::ostream &operator<<(std::ostream &os, const vec2 &v) {
  return os << '(' << v.x << ',' << v.y << ')';
}

bool vec2::is_nan() const noexcept {
  return isnanf(x) || isnanf(y);
}
