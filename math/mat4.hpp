//
// Created by schro on 12/3/2023.
//

#ifndef MAT_4_HPP
#define MAT_4_HPP
#include "number.hpp"


union mat4 {
  struct {
    f32 m00, m01, m02, m03;
    f32 m10, m11, m12, m13;
    f32 m20, m21, m22, m23;
    f32 m30, m31, m32, m33;
  };

  static const mat4 identity;

  mat4(f32 m00, f32 m01, f32 m02, f32 m03,
       f32 m10, f32 m11, f32 m12, f32 m13,
       f32 m20, f32 m21, f32 m22, f32 m23,
       f32 m30, f32 m31, f32 m32, f32 m33);

  [[nodiscard]] constexpr f32 trace() const noexcept;

  [[nodiscard]] constexpr f32 det() const noexcept;

  [[nodiscard]] constexpr f32 invertible() const noexcept;

  mat4 operator *(mat4 other) const noexcept;
};


#endif //MAT_4_HPP
