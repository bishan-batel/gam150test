//
// Created by bishan_ on 12/8/23.
//

#ifndef VEC_2_I_HPP
#define VEC_2_I_HPP
#include "number.hpp"
#include "vec2.hpp"


union vec2i {
  struct {
    i32 x, y;
  };

  struct {
    i32 w, h;
  };

  vec2i(i32 x, i32 y) noexcept;
  explicit vec2i(i32 v) noexcept;
  explicit vec2i(vec2 vec) noexcept;
  explicit operator vec2() const noexcept;


  [[nodiscard]] f32 aspect_ratio() const noexcept;

  /**
   * Magnitude of the vector
   */
  [[nodiscard]] f32 len() const noexcept;

  /**
   * The square of the magnitude of the vector
   */
  [[nodiscard]] i32 len2() const noexcept;

  vec2i operator +(vec2i other) const noexcept;
  vec2i operator -(vec2i other) const noexcept;
  vec2i operator *(vec2i other) const noexcept;
  vec2i operator /(vec2i other) const noexcept;


  vec2i operator *(i32 scalar) const noexcept;
  friend vec2i operator *(i32 scalar, vec2i other) noexcept;

  vec2 operator *(f32 scalar) const noexcept;
  friend vec2 operator *(f32 scalar, vec2i other) noexcept;

  vec2i operator /(i32 scalar) const noexcept;

  vec2i &operator *=(i32 scalar) noexcept;

  vec2i &operator /=(i32 dividend) noexcept;

  vec2i &operator +=(vec2i rhs) noexcept;
  vec2i &operator -=(vec2i rhs) noexcept;
  vec2i &operator *=(vec2i rhs) noexcept;
  vec2i &operator /=(vec2i rhs) noexcept;

  template <typename T> requires std::is_integral_v<T>
  T get_x() {
    return static_cast<T>(x);
  }

  template <typename T> requires std::is_integral_v<T>
  T get_y() {
    return static_cast<T>(y);
  }

};


#endif //VEC_2_I_HPP
