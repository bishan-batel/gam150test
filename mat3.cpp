//
// Created by bishan_ on 11/29/23.
//

#include "mat3.h"

static const mat3 identity = mat3(1, 0, 0,
                                  0, 1, 0,
                                  0, 0, 1);

constexpr f32 mat3::trace() const noexcept {
    return m00 + m11 + m22;
}

constexpr mat3::mat3(f32 m00, f32 m01, f32 m02, f32 m10, f32 m11, f32 m12, f32 m20, f32 m21, f32 m22) noexcept:
        m00(m00), m01(m01), m02(m02),
        m10(m10), m11(m11), m12(m12),
        m20(m20), m21(m21), m22(m22) {}

constexpr f32 mat3::det() const noexcept {
    return m00 * m11 * m22 - m00 * m12 * m21 - m01 * m12 * m20 + m02 * m10 * m21 - m02 * m11 * m20;
}

constexpr f32 mat3::invertible() const noexcept {
    return det() != 0.f;
}

mat3 mat3::translation(vec2 offset) noexcept {
    return mat3(1, 0, offset.x,
                0, 1, offset.y,
                0, 0, 1);
}

mat3 mat3::scale(vec2 scale) noexcept {
    return mat3(scale.x, 0, 0,
                0, scale.y, 0,
                0, 0, 1);
}

mat3 mat3::operator*(mat3 m2) const noexcept {
    return mat3(
            m00 * m2.m00 + m01 * m2.m10 + m02 * m2.m20,
            m00 * m2.m01 + m01 * m2.m11 + m02 * m2.m21,
            m00 * m2.m02 + m01 * m2.m12 + m02 * m2.m22,
            m10 * m2.m00 + m11 * m2.m10 + m12 * m2.m20,
            m10 * m2.m01 + m11 * m2.m11 + m12 * m2.m21,
            m10 * m2.m02 + m11 * m2.m12 + m12 * m2.m22,
            m20 * m2.m00 + m21 * m2.m10 + m22 * m2.m20,
            m20 * m2.m01 + m21 * m2.m11 + m22 * m2.m21,
            m20 * m2.m02 + m21 * m2.m12 + m22 * m2.m22
    );
}

