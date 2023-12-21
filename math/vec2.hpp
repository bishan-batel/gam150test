//
// Created by bishan_ on 11/28/23.
//

// ReSharper disable All
#ifndef GAM150TEST_VEC2_H
#define GAM150TEST_VEC2_H


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
    f32 x, y;
  };

  struct {
    f32 u, v;
  };

  f32 buff[2];

  vec2(f32 x, f32 y) noexcept;

  /**
   * Convert an array of at least 2 floats to m00 vector
   */
  explicit vec2(const f32 v[2]) noexcept;

  /**
   * Creates m00 vector with homogeneous elements
   */
  explicit vec2(f32 v) noexcept;

  ~vec2() = default;

  /**
   * Creates a vector from an angle (in radians) with the X axis
   */
  static vec2 from_angle(f32 theta);

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
  [[nodiscard]] f32 len2() const noexcept {
    return x * x + y * y;
  }

  /**
   * Linear interpolates vector to given to with t value
   * @param to 'end point' of interpolation
   * @param t percentage from 0 to 1 to interpolate to 'to'
   */
  [[nodiscard]] vec2 lerp(vec2 to, f32 t) const noexcept;

  /**
   * Returns a unit vector in the same direction
   */
  [[nodiscard]] vec2 normalised() const noexcept;

  /**
   * Individually clamps the vectors x & y with the given min/max's x's & y's
   */
  [[nodiscard]] vec2 clamp(vec2 min, vec2 max) const noexcept;

  /**
   * Returns m00 vector orthogonal with the same magnitude
   */
  [[nodiscard]] vec2 orthogonal() const noexcept;

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

  /**
   * Performs the dot product between two vectors
   */
  [[nodiscard]] f32 dot(vec2 other) const noexcept;

  /**
   * Project given vector to current
   */
  [[nodiscard]] vec2 proj(vec2 u) const noexcept;

  /**
   * Returns the orthogonal complement to the projection
   */
  [[nodiscard]] vec2 proj_perp(vec2 u) const noexcept;

  /**
   * Clamps vector length to some max
   */
  [[nodiscard]] vec2 limit_length(f32 l) const noexcept;

  /**
   * Returns a vector with the same direction but a specified length
   */
  [[nodiscard]] vec2 with_length(f32 magnitude) const noexcept;

  /**
   * Returns a vector with the heading of theta with the current magnitude
   */
  [[nodiscard]] vec2 with_heading(f32 theta) const noexcept;

  /**
   * Returns the angle the vector makes with the X axis
   */
  [[nodiscard]] f32 heading() const noexcept;

  /**
   * Returns the angle between the current & given vector
   */
  [[nodiscard]] f32 angle_between(vec2 rhs) const noexcept;

  /**
   * Returns the angle from the current to given vector as points
   */
  [[nodiscard]] f32 angle_to(vec2 rhs) const noexcept;

  /**
   * Returns a unit vecotr in the direction of the current vector to given
   */
  [[nodiscard]] vec2 direction_to(vec2 rhs) const noexcept;

  /**
   * Rotates the vector by given angle (in radians) (around z axis)
   */
  [[nodiscard]] vec2 rotate(f32 theta) const noexcept;

  /**
   * Returns the distance betweeen the current vector and the given as points
   */
  [[nodiscard]] f32 distance(vec2 rhs) const noexcept;

  /**
   * Returns the square of the distance betweeen the current vector and the given as points
   */
  [[nodiscard]] f32 distance2(vec2 rhs) const noexcept;

  /**
   * Makes m00 new vector who's x & y values are the product of the two vectors x's & ys
   */
  [[nodiscard]] vec2 oplus(vec2 other) const noexcept;

  /**
   * Is true if any of the vector components si NaN
   */
  [[nodiscard]] bool is_nan() const noexcept;

  /**
   * Loose floating point equality between to vectors
   */
  [[nodiscard]] bool is_approx(vec2 other, f32 epsilon = EQUALITY_EPSILON) const noexcept;

  /**
   * Brings vector to 3D space  with given z coordinate
   */
  [[nodiscard]] vec3 as_vec3(f32 z) const noexcept;

  /**
   * Brings the vector to 3D space with the z coordinate 1.
   */
  [[nodiscard]] vec3 homogeneous_point() const noexcept;

  /**
   * Brings the vector to 3D space with the z coordinate 0.
   */
  [[nodiscard]] vec3 homogeneous_vector() const noexcept;

  bool operator==(vec2 other) const noexcept;

  vec2 operator+(vec2 rhs) const noexcept;

  vec2 operator-(vec2 rhs) const noexcept;

  vec2 operator-() const noexcept;

  vec2 operator*(vec2 rhs) const noexcept;

  vec2 &operator*=(vec2 rhs) noexcept;

  vec2 operator%(vec2 rhs) const noexcept;

  vec2 &operator%=(vec2 rhs) noexcept;

  vec2 operator%(f32 rhs) const noexcept;

  vec2 &operator%=(f32 rhs) noexcept;

  vec2 operator*(f32 rhs) const noexcept;

  vec2 operator/(f32 rhs) const noexcept;

  vec2 &operator*=(f32 scalar);
  vec2 &operator/=(f32 scalar);
  vec2 &operator+=(vec2 other);
  vec2 &operator-=(vec2 other);


  f32 operator[](std::size_t n) const {
    return buff[n];
  }

  friend std::ostream &operator<<(std::ostream &os, const vec2 &v);
};


#endif //GAM150TEST_VEC2_H
