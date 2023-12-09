//
// Created by schro on 12/3/2023.
//

#ifndef MAT_4_HPP
#define MAT_4_HPP
#include "mat3.hpp"
#include "number.hpp"
#include "vec3.hpp"


union mat4 {
  struct {
    f32 m00, m01, m02, m03;
    f32 m10, m11, m12, m13;
    f32 m20, m21, m22, m23;
    f32 m30, m31, m32, m33;
  };

  struct {
    f32 a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p;
  };

  struct {
    f32 row0[4], row1[4], row2[4], row3[4];
  };

  f32 vals[4 * 4];

  static const mat4 identity;

  mat4(f32 m00, f32 m01, f32 m02, f32 m03,
       f32 m10, f32 m11, f32 m12, f32 m13,
       f32 m20, f32 m21, f32 m22, f32 m23,
       f32 m30, f32 m31, f32 m32, f32 m33);

  static mat4 translation(vec3 offset) noexcept;

  static mat4 scale(vec3 scale) noexcept;

  [[nodiscard]] f32 trace() const noexcept;

  [[nodiscard]] f32 det() const noexcept;

  [[nodiscard]] mat4 inverse() const noexcept;

  mat4 operator +(const mat4 &other) const noexcept;
  mat4 operator -(const mat4 &other) const noexcept;
  mat4 operator -() const noexcept;

  mat4 operator *(const mat4 &v) const noexcept;

  mat4 operator *(f32 scalar) const noexcept;
  friend mat4 operator*(f32 f32, const mat4 &rhs);

  mat4 operator /(f32 divisor) const noexcept;

  vec3 operator *(vec3 other) const noexcept;
};


#endif //MAT_4_HPP
