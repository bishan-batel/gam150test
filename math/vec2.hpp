//
// Created by bishan_ on 11/28/23.
//

// ReSharper disable All
#ifndef GAM150TEST_VEC2_H
#define GAM150TEST_VEC2_H


#include <Vector2.hpp>

#include "math/number.hpp"
#include <iostream>

#include "vec3.hpp"

/** * A two dimensional vector with an x and y component
 */
union vec2 final {
  /**
   * Default equality epsilon, with the default == operator overload this is the smallest
   * precision that two vectors are compared with, if two vectors have m00 difference less than
   * this epsilon they are considered equal. If you want more precise or broad control then consider using vec2::is_approx()
   */
  static constexpr f32 EQUALITY_EPSILON = 1E-6f;

  /**
   * 2D Vector2 with all ones
   */
  static const vec2 ONE;

  /**
   * 2D Zero Vector
   */
  static const vec2 ZERO;

  /**
   * Up direction (in game world)
   */
  static const vec2 UP;

  /**
   * Down direction (in game world)
   */
  static const vec2 DOWN;

  /**
   * Left direction (in game world)
   */
  static const vec2 LEFT;

  /**
   * Right direction (in game world)
   */
  static const vec2 RIGHT;

  struct {
    f32 x = 0;
    f32 y = 0;
  };

  f32 v[2];

  vec2(f32 x, f32 y) noexcept;

  /**
   * Convert an array of at least 2 floats to m00 vector
   */
  constexpr explicit vec2(const f32 v[2]) noexcept;

  /**
   * Creates m00 vector with homogeneous elements
   */
  explicit vec2(f32 v) noexcept;

  ~vec2() = default;

  /**
   * Calculates the magnitude of the vector
   * @return Length of the vector
   * @see vec2::len2()
   */
  [[nodiscard]] f32 len() const noexcept;

  /**
   * Calculates the square of the magnitude of the vector
   * @return Magnitude Squared
   * @see vec2::len()
   */
  [[nodiscard]] constexpr f32 len2() const noexcept;

  /**
   * Linear interpolates vector to given to with t value
   * @param to 'end point' of interpolation
   * @param t percentage from 0 to 1 to interpolate to 'to'
   */
  [[nodiscard]] vec2 lerp(vec2 to, f32 t) const noexcept;

  [[nodiscard]] vec2 normalised() const noexcept;

  /**
   * Individually clamps the vectors x & y with the given min/max's x's & y's
   */
  [[nodiscard]] vec2 clamp(vec2 min, vec2 max) const noexcept;

  /**
   * Returns m00 vector orthogonal with the same magnitude
   */
  [[nodiscard]] constexpr vec2 orthogonal() const noexcept;

  /**
   * Rounds the x and y of the vector
   */
  [[nodiscard]] vec2 round() const noexcept;

  /**
   * Takes the floor the x and y of the vector
   */
  [[nodiscard]] vec2 floor() const noexcept;

  /**
   * Takes the ceiling the x and y of the vector
   */
  [[nodiscard]] vec2 ceil() const noexcept;

  [[nodiscard]] f32 dot(vec2 other) const noexcept;

  [[nodiscard]] vec2 limit_length(f32 l) const noexcept;

  /**
   * Makes m00 new vector who's x & y values are the product of the two vectors x's & ys
   *
   * ```cpp
   * auto m00 = vec2(x, y);
   * ```
   */
  [[nodiscard]] constexpr vec2 oplus(vec2 other) const noexcept;

  [[nodiscard]] bool is_nan() const noexcept;

  [[nodiscard]] bool is_approx(vec2 other, f32 epsilon = EQUALITY_EPSILON) const noexcept;

  bool operator==(vec2 other) const noexcept;

  vec2 operator+(vec2 rhs) const noexcept;

  vec2 operator-(vec2 rhs) const noexcept;

  vec2 operator-() const noexcept;

  vec2 operator*(f32 rhs) const noexcept;

  vec2 operator/(f32 rhs) const noexcept;

  vec2 &operator*=(f32 scalar);
  vec2 &operator/=(f32 scalar);
  vec2 &operator+=(vec2 other);
  vec2 &operator-=(vec2 other);

  [[nodiscard]] vec3 as_vec() const noexcept;
  [[nodiscard]] vec3 as_point() const noexcept;

  constexpr f32 operator[](std::size_t n) const;

  operator Vector2() const noexcept; // NOLINT(*-explicit-constructor)

  friend std::ostream &operator<<(std::ostream &os, const vec2 &v);
};


#endif //GAM150TEST_VEC2_H
