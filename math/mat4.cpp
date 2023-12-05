//
// Created by schro on 12/3/2023.
//

#include "mat4.hpp"


static const mat4 identity(1, 0, 0, 0,
                           0, 1, 0, 0,
                           0, 0, 1, 0,
                           0, 0, 0, 1);


constexpr f32 mat4::trace() const noexcept {
	return m00 + m11 + m22 + m33;
}

// constexpr f32 mat4::det() const noexcept {}
//
// constexpr f32 mat4::invertible() const noexcept {}
mat4::mat4(const f32 m00, const f32 m01, const f32 m02, const f32 m03, const f32 m10, const f32 m11, const f32 m12,
           const f32 m13, const f32 m20, const f32 m21, const f32 m22, const f32 m23,
           const f32 m30, const f32 m31, const f32 m32, const f32 m33) : m00(m00), m01(m01), m02(m02), m03(m03),
                                                                         m10(m10), m11(m11), m12(m12), m13(m13),
                                                                         m20(m20), m21(m21), m22(m22), m23(m23),
                                                                         m30(m30), m31(m31), m32(m32), m33(m33) {}
