//
// Created by schro on 12/3/2023.
//

#include "mat4.hpp"

#include "mat3.hpp"


const mat4 mat4::identity(1, 0, 0, 0,
                          0, 1, 0, 0,
                          0, 0, 1, 0,
                          0, 0, 0, 1);


mat4::mat4(const f32 m00, const f32 m01, const f32 m02, const f32 m03, const f32 m10, const f32 m11, const f32 m12,
           const f32 m13, const f32 m20, const f32 m21, const f32 m22, const f32 m23,
           const f32 m30, const f32 m31, const f32 m32, const f32 m33) :
  m00(m00), m01(m01), m02(m02), m03(m03),
  m10(m10), m11(m11), m12(m12), m13(m13),
  m20(m20), m21(m21), m22(m22), m23(m23),
  m30(m30), m31(m31), m32(m32), m33(m33) {}

mat4 mat4::translation(vec3 offset) noexcept {
  return {
    1, 0, 0, offset.x,
    0, 1, 0, offset.y,
    0, 0, 1, offset.z,
    0, 0, 0, 1,
  };
}

mat4 mat4::scale(vec3 scale) noexcept {
  return {
    scale.x, 0, 0, 0,
    0, scale.y, 0, 0,
    0, 0, scale.z, 0,
    0, 0, 0, 1,
  };
}

f32 mat4::trace() const noexcept {
  return m00 + m11 + m22 + m33;
}


f32 mat4::det() const noexcept {
  return
    a * mat3(f, g, h, j, k, l, n, o, p).det()
    - b * mat3(e, g, h, j, k, l, n, o, p).det()
    + c * mat3(e, f, h, i, j, l, m, n, p).det()
    - d * mat3(e, f, g, i, j, k, m, n, o).det();
}

mat4 mat4::inverse() const noexcept {
  auto &m = *this;

  const auto A2323 = m.m22 * m.m33 - m.m23 * m.m32;
  const auto A1323 = m.m21 * m.m33 - m.m23 * m.m31;
  const auto A1223 = m.m21 * m.m32 - m.m22 * m.m31;
  const auto A0323 = m.m20 * m.m33 - m.m23 * m.m30;
  const auto A0223 = m.m20 * m.m32 - m.m22 * m.m30;
  const auto A0123 = m.m20 * m.m31 - m.m21 * m.m30;
  const auto A2313 = m.m12 * m.m33 - m.m13 * m.m32;
  const auto A1313 = m.m11 * m.m33 - m.m13 * m.m31;
  const auto A1213 = m.m11 * m.m32 - m.m12 * m.m31;
  const auto A2312 = m.m12 * m.m23 - m.m13 * m.m22;
  const auto A1312 = m.m11 * m.m23 - m.m13 * m.m21;
  const auto A1212 = m.m11 * m.m22 - m.m12 * m.m21;
  const auto A0313 = m.m10 * m.m33 - m.m13 * m.m30;
  const auto A0213 = m.m10 * m.m32 - m.m12 * m.m30;
  const auto A0312 = m.m10 * m.m23 - m.m13 * m.m20;
  const auto A0212 = m.m10 * m.m22 - m.m12 * m.m20;
  const auto A0113 = m.m10 * m.m31 - m.m11 * m.m30;
  const auto A0112 = m.m10 * m.m21 - m.m11 * m.m20;

  auto det = m.m00 * (m.m11 * A2323 - m.m12 * A1323 + m.m13 * A1223)
    - m.m01 * (m.m10 * A2323 - m.m12 * A0323 + m.m13 * A0223)
    + m.m02 * (m.m10 * A1323 - m.m11 * A0323 + m.m13 * A0123)
    - m.m03 * (m.m10 * A1223 - m.m11 * A0223 + m.m12 * A0123);
  det = 1 / det;

  return {
    det * (m.m11 * A2323 - m.m12 * A1323 + m.m13 * A1223),
    det * -(m.m01 * A2323 - m.m02 * A1323 + m.m03 * A1223),
    det * (m.m01 * A2313 - m.m02 * A1313 + m.m03 * A1213),
    det * -(m.m01 * A2312 - m.m02 * A1312 + m.m03 * A1212),
    det * -(m.m10 * A2323 - m.m12 * A0323 + m.m13 * A0223),
    det * (m.m00 * A2323 - m.m02 * A0323 + m.m03 * A0223),
    det * -(m.m00 * A2313 - m.m02 * A0313 + m.m03 * A0213),
    det * (m.m00 * A2312 - m.m02 * A0312 + m.m03 * A0212),
    det * (m.m10 * A1323 - m.m11 * A0323 + m.m13 * A0123),
    det * -(m.m00 * A1323 - m.m01 * A0323 + m.m03 * A0123),
    det * (m.m00 * A1313 - m.m01 * A0313 + m.m03 * A0113),
    det * -(m.m00 * A1312 - m.m01 * A0312 + m.m03 * A0112),
    det * -(m.m10 * A1223 - m.m11 * A0223 + m.m12 * A0123),
    det * (m.m00 * A1223 - m.m01 * A0223 + m.m02 * A0123),
    det * -(m.m00 * A1213 - m.m01 * A0213 + m.m02 * A0113),
    det * (m.m00 * A1212 - m.m01 * A0212 + m.m02 * A0112),
  };

}

mat4 mat4::operator+(const mat4 &other) const noexcept {
  return {
    a + other.a,
    b + other.b,
    c + other.c,
    d + other.d,
    e + other.e,
    f + other.f,
    g + other.g,
    h + other.h,
    i + other.i,
    j + other.j,
    k + other.k,
    l + other.l,
    m + other.m,
    n + other.n,
    o + other.o,
    p + other.p
  };
}

mat4 mat4::operator-(const mat4 &other) const noexcept {
  return {
    a - other.a,
    b - other.b,
    c - other.c,
    d - other.d,
    e - other.e,
    f - other.f,
    g - other.g,
    h - other.h,
    i - other.i,
    j - other.j,
    k - other.k,
    l - other.l,
    m - other.m,
    n - other.n,
    o - other.o,
    p - other.p
  };
}

mat4 mat4::operator-() const noexcept {
  return {-a, -b, -c, -d, -e, -f, -g, -h, -i, -j, -k, -l, -m, -n, -o, -p};
}

mat4 mat4::operator*(const mat4 &v) const noexcept {
  return {
    m00 * v.m00 + m10 * v.m01 + m20 * v.m02 + m30 * v.m03,
    m00 * v.m10 + m10 * v.m11 + m20 * v.m12 + m30 * v.m03,
    m00 * v.m20 + m10 * v.m21 + m20 * v.m22 + m30 * v.m03,
    m00 * v.m30 + m10 * v.m31 + m20 * v.m32 + m30 * v.m03,
    m01 * v.m00 + m11 * v.m01 + m21 * v.m02 + m31 * v.m03,
    m01 * v.m10 + m11 * v.m11 + m21 * v.m12 + m31 * v.m03,
    m01 * v.m20 + m11 * v.m21 + m21 * v.m22 + m31 * v.m03,
    m01 * v.m30 + m11 * v.m31 + m21 * v.m32 + m31 * v.m03,
    m02 * v.m00 + m12 * v.m01 + m22 * v.m02 + m32 * v.m03,
    m02 * v.m10 + m12 * v.m11 + m22 * v.m12 + m32 * v.m03,
    m02 * v.m20 + m12 * v.m21 + m22 * v.m22 + m32 * v.m03,
    m02 * v.m30 + m12 * v.m31 + m22 * v.m32 + m32 * v.m03,
    m03 * v.m00 + m13 * v.m01 + m23 * v.m02 + m33 * v.m03,
    m03 * v.m10 + m13 * v.m11 + m23 * v.m12 + m33 * v.m03,
    m03 * v.m20 + m13 * v.m21 + m23 * v.m22 + m33 * v.m03,
    m03 * v.m30 + m13 * v.m31 + m23 * v.m32 + m33 * v.m03,
  };
}
