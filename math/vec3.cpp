#include "vec3.hpp"

#include "cmath"
#include "vec2.hpp"

const vec3
  vec3::ONE{1.f},
  vec3::ZERO{0.f},
  vec3::UP{0, 1.f, 0.f},
  vec3::DOWN{0.f, -1.f, 0.f},
  vec3::LEFT{-1.f, 0.f, 0.f},
  vec3::RIGHT{1.f, 0.f, 0.f};

constexpr vec3::vec3(const f32 x, const f32 y, const f32 z) noexcept :
  x(x), y(y), z(z) {}

constexpr vec3::vec3(const f32 v[3]) noexcept :
  x(v[0]), y(v[1]), z(v[2]) {}

constexpr vec3::vec3(const f32 v) noexcept :
  vec3(v, v, v) {}

constexpr f32 vec3::len2() const noexcept {
  return x * x + y * y + z * z;
}

f32 vec3::len() const noexcept {
  return std::sqrt(x * x + y * y + z * z);
}

vec3 vec3::lerp(const vec3 to, const f32 t) const noexcept {
  return *this + (to - *this) * t;
}

vec3 vec3::normalised() const noexcept {
  return *this / len();
}

vec3 vec3::clamp(const vec3 min, const vec3 max) const noexcept {
  f32 x2 = x > max.x ? max.x : x;
  x2 = x2 < min.x ? min.x : x2;

  f32 y2 = y > max.y ? max.y : y;
  y2 = y2 < min.y ? min.y : y2;

  f32 z2 = z > max.z ? max.z : z;
  z2 = z2 < min.z ? min.z : z2;

  return {x2, y2, z2};
}


constexpr vec3 vec3::orthogonal() const noexcept {
  return {x, -z, y};
}


vec3 vec3::round() const noexcept {
  return {std::round(x), std::round(y), std::round(z)};
}

vec3 vec3::floor() const noexcept {
  return {std::floor(x), std::floor(y), std::floor(z)};
}

vec3 vec3::ceil() const noexcept {
  return {std::ceil(x), std::ceil(y), std::ceil(z)};
}

constexpr f32 vec3::dot(const vec3 other) const noexcept {
  return x * other.x + y * other.y + z * other.z;
}

constexpr vec3 vec3::limit_length(const f32 l) const noexcept {
  const f32 len = len2();

  return len > l * l ? *this * l / std::sqrt(len) : *this;
}

constexpr vec3 vec3::oplus(const vec3 other) const noexcept {
  return {x * other.x, y * other.y, z * other.z};
}


bool vec3::is_nan() const noexcept {
  return isnanf(x) || isnanf(y) || isnanf(z);
}

bool vec3::is_approx(const vec3 other, const f32 epsilon) const noexcept {
  return (*this - other).len2() < epsilon;
}

vec2 vec3::as2D() const noexcept {
  return xy() / z;
}

vec2 vec3::xy() const noexcept {
  return {x, y};
}

bool vec3::operator==(const vec3 other) const noexcept {
  return is_approx(other, EQUALITY_EPSILON);
}

constexpr vec3 vec3::operator+(const vec3 rhs) const noexcept {
  return {x + rhs.x, y + rhs.y, z + rhs.z};
}

constexpr vec3 vec3::operator-(vec3 rhs) const noexcept {
  return {x - rhs.x, y - rhs.y, z - rhs.z};
}

constexpr vec3 vec3::operator-() const noexcept {
  return {-x, -y, -z};
}

constexpr vec3 vec3::operator*(const f32 rhs) const noexcept {
  return {x * rhs, y * rhs, z * rhs};
}

constexpr vec3 vec3::operator/(const f32 rhs) const noexcept {
  return *this * (1.f / rhs);
}

constexpr f32 vec3::operator[](const std::size_t n) const {
  return v[n];
}

std::ostream &operator<<(std::ostream &os, const vec3 &v) {
  return os << "(" << v.x << "," << v.y << "," << v.z << ")";
}
