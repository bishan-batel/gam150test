//
// Created by bishan_ on 11/29/23.
//

#include "mat3.hpp"

#include "vec2.hpp"

const mat3 mat3::identity = mat3(1, 0, 0,
                                 0, 1, 0,
                                 0, 0, 1
  );

f32 mat3::trace() const noexcept {
  return m00 + m11 + m22;
}

mat3::mat3(
  const f32 m00,
  const f32 m01,
  const f32 m02,
  const f32 m10,
  const f32 m11,
  const f32 m12,
  const f32 m20,
  const f32 m21,
  const f32 m22
  ) noexcept:
  m00(m00), m01(m01), m02(m02),
  m10(m10), m11(m11), m12(m12),
  m20(m20), m21(m21), m22(m22) {}

mat3::mat3(const vec3 i, const vec3 j, const vec3 k) :
  mat3(i.x, j.x, k.x,
       i.y, j.y, k.y,
       i.z, j.z, k.z
    ) {}

f32 mat3::det() const noexcept {
  return m00 * m11 * m22 - m00 * m12 * m21 - m01 * m12 * m20 + m02 * m10 * m21 - m02 * m11 * m20;
}

bool mat3::invertible() const noexcept {
  return det() != 0.f;
}

mat3 mat3::translate(const vec2 offset) const noexcept {
  return {
    m00, m01, m02 + offset.x,
    m10, m11, m12 + offset.y,
    m20, m21, m22
  };
}

mat3 mat3::translation(vec2 offset) noexcept {
  return {
    1, 0, offset.x,
    0, 1, offset.y,
    0, 0, 1
  };
}

mat3 mat3::scale(vec2 scale) noexcept {
  return {
    scale.x, 0, 0,
    0, scale.y, 0,
    0, 0, 1
  };
}

mat3 mat3::operator+(const mat3 &other) const noexcept {
  return {
    m00 + other.m00, m01 + other.m01, m02 + other.m02,
    m10 + other.m10, m11 + other.m11, m12 + other.m12,
    m20 + other.m20, m21 + other.m21, m22 + other.m22
  };
}

mat3 mat3::operator-(const mat3 &other) const noexcept {
  return {
    m00 - other.m00, m01 - other.m01, m02 - other.m02,
    m10 - other.m10, m11 - other.m11, m12 - other.m12,
    m20 - other.m20, m21 - other.m21, m22 - other.m22
  };
}

mat3 mat3::operator-() const noexcept {
  return {
    -m00, -m01, -m02,
    -m10, -m11, -m12,
    -m20, -m21, -m22
  };
}

mat3 mat3::operator*(const mat3 &other) const noexcept {
  return {
    m00 * other.m00 + m01 * other.m10 + m02 * other.m20,
    m00 * other.m01 + m01 * other.m11 + m02 * other.m21,
    m00 * other.m02 + m01 * other.m12 + m02 * other.m22,
    m10 * other.m00 + m11 * other.m10 + m12 * other.m20,
    m10 * other.m01 + m11 * other.m11 + m12 * other.m21,
    m10 * other.m02 + m11 * other.m12 + m12 * other.m22,
    m20 * other.m00 + m21 * other.m10 + m22 * other.m20,
    m20 * other.m01 + m21 * other.m11 + m22 * other.m21,
    m20 * other.m02 + m21 * other.m12 + m22 * other.m22
  };
}

mat3 mat3::operator*(const f32 scalar) const noexcept {
  return {
    m00 * scalar, m01 * scalar, m02 * scalar,
    m10 * scalar, m11 * scalar, m12 * scalar,
    m20 * scalar, m21 * scalar, m22 * scalar
  };
}

mat3 mat3::operator/(const f32 divisor) const noexcept {
  return {
    m00 / divisor, m01 / divisor, m02 / divisor,
    m10 / divisor, m11 / divisor, m12 / divisor,
    m20 / divisor, m21 / divisor, m22 / divisor
  };
}

mat3 &mat3::operator+=(const mat3 &other) noexcept {
  return *this = *this + other;
}

mat3 &mat3::operator-=(const mat3 &other) noexcept {
  return *this = *this - other;
}

mat3 &mat3::operator*=(const mat3 &other) noexcept {
  return *this = *this * other;
}

mat3 &mat3::operator*=(const f32 scalar) noexcept {
  return *this = *this * scalar;
}

mat3 &mat3::operator/=(const f32 scalar) noexcept {
  return *this = *this / scalar;
}

vec3 mat3::operator*(const vec3 other) const noexcept {
  return {
    other.x * m00 + other.y * m01 + other.z * m02,
    other.x * m10 + other.y * m11 + other.z * m12,
    other.x * m20 + other.y * m21 + other.z * m22
  };
}

mat3 operator*(const f32 scalar, const mat3 &other) noexcept {
  return other * scalar;
}
