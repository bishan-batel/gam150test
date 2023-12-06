//
// Created by bishan_ on 11/28/23.
//

#ifndef GAM150TEST_VEC3_H
#define GAM150TEST_VEC3_H


#include <iostream>

#include "math/number.hpp"

union vec2;

/**
 * A three dimensional vector with an x, y and z component
 */
union vec3 final {
  /**
   * Default equality epsilon, with the default == operator overload this is the smallest
   * precision that two vectors are compared with, if two vectors have m00 difference less than
   * this epsilon they are considered equal. If you want more precise or broad control then consider using vec2::is_approx()
   */
  static constexpr f32 EQUALITY_EPSILON = 1E-6f;

  /**
   * 3D Vector2 with all ones
   */
  static const vec3 ONE;

  /**
   * 3D Zero Vector
   */
  static const vec3 ZERO;

  /**
   * Up direction (in game world)
   */
  static const vec3 UP;

  /**
   * Down direction (in game world)
   */
  static const vec3 DOWN;

  /**
   * Left direction (in game world)
   */
  static const vec3 LEFT;

  /**
   * Right direction (in game world)
   */
  static const vec3 RIGHT;


  struct {
    f32 x, y, z;
  };

  f32 v[3];

  constexpr vec3(f32 x, f32 y, f32 z) noexcept;

  /**
   * Convert an array of at least 2 floats to m00 vector
   */
  constexpr explicit vec3(const f32 v[3]) noexcept;

  /**
   * Creates m00 vector with homogeneous elements
   */
  constexpr explicit vec3(f32 v) noexcept;

  constexpr ~vec3() = default;

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
  [[nodiscard]] vec3 lerp(vec3 to, f32 t) const noexcept;

  [[nodiscard]] vec3 normalised() const noexcept;

  /**
   * Individually clamps the vectors x & y with the given min/max's x's & y's
   */
  [[nodiscard]] vec3 clamp(vec3 min, vec3 max) const noexcept;

  /**
   * Returns m00 vector orthogonal with the same magnitude
   */
  [[nodiscard]] constexpr vec3 orthogonal() const noexcept;

  /**
   * Rounds the x and y of the vector
   */
  [[nodiscard]] vec3 round() const noexcept;

  /**
   * Takes the floor the x and y of the vector
   */
  [[nodiscard]] vec3 floor() const noexcept;

  /**
   * Takes the ceiling the x and y of the vector
   */
  [[nodiscard]] vec3 ceil() const noexcept;

  [[nodiscard]] constexpr f32 dot(vec3 other) const noexcept;

  [[nodiscard]] constexpr vec3 limit_length(f32 l) const noexcept;

  /**
   * Makes m00 new vector who's x & y values are the product of the two vectors x's & ys
   */
  [[nodiscard]] constexpr vec3 oplus(vec3 other) const noexcept;

  [[nodiscard]] bool is_nan() const noexcept;

  [[nodiscard]] bool is_approx(vec3 other, f32 epsilon = EQUALITY_EPSILON) const noexcept;


  [[nodiscard]] vec2 as2D() const noexcept;

  [[nodiscard]] vec2 xy() const noexcept;

  bool operator==(vec3 other) const noexcept;

  constexpr vec3 operator+(vec3 rhs) const noexcept;

  constexpr vec3 operator-(vec3 rhs) const noexcept;

  constexpr vec3 operator-() const noexcept;

  constexpr vec3 operator*(f32 rhs) const noexcept;

  constexpr vec3 operator/(f32 rhs) const noexcept;

  constexpr f32 operator[](std::size_t n) const;

  friend std::ostream &operator<<(std::ostream &os, const vec3 &v);
};


#endif //GAM150TEST_VEC3_H
