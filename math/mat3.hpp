//
// Created by bishan_ on 11/29/23.
//

#ifndef GAM150TEST_MAT3_H
#define GAM150TEST_MAT3_H


#include "vec2.hpp"

union mat3 final {
  static constexpr std::size_t SIZE = 3;

  static const mat3 identity;

  struct {
    f32 m00, m01, m02;
    f32 m10, m11, m12;
    f32 m20, m21, m22;
  };

  f32 m[SIZE][SIZE];

  constexpr mat3(
    f32 m00, f32 m01, f32 m02,
    f32 m10, f32 m11, f32 m12,
    f32 m20, f32 m21, f32 m22
    ) noexcept;

  constexpr static mat3 translation(vec2 offset) noexcept;

  constexpr static mat3 scale(vec2 scale) noexcept;

  [[nodiscard]] constexpr f32 trace() const noexcept;

  [[nodiscard]] constexpr f32 det() const noexcept;

  [[nodiscard]] constexpr f32 invertible() const noexcept;

  constexpr mat3 operator +(const mat3 &other) const noexcept;
  constexpr mat3 operator -(const mat3 &other) const noexcept;
  constexpr mat3 operator -() const noexcept;

  constexpr mat3 operator *(const mat3 &other) const noexcept;
  constexpr mat3 operator *(f32 scalar) const noexcept;
  constexpr mat3 operator /(f32 divisor) const noexcept;
};

using affine2D = mat3;


#endif //GAM150TEST_MAT3_H
