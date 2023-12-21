//
// Created by bishan_ on 12/8/23.
//

#ifndef COLOR_HPP
#define COLOR_HPP
#include <bits/stl_algo.h>

#include "number.hpp"


union color {
  struct {
    f32 r, g, b, a;
  };

  f32 bytes[4];

  static color rgba(const f32 r, const f32 g, const f32 b, const f32 a = 1.f) {
    return {r, g, b, a};
  }


  /**
   * Converts colors with integer range 0-255 to floating point 0-1
   */
  static color rgba_u8(const u8 r, const u8 g, const u8 b, const u8 a = 255) {
    return {
      static_cast<f32>(r) / 255.f,
      static_cast<f32>(g) / 255.f,
      static_cast<f32>(b) / 255.f,
      static_cast<f32>(a) / 255.f
    };
  }

  static color hex(const u32 hex) {
    return rgba_u8(
      hex >> 12 & 0xf,
      hex >> 8 & 0xf,
      hex >> 4 & 0xf,
      hex & 0xf
      );
  }

  /**
   * Simple linear interporlation from current color to other
   */
  [[nodiscard]] color mix(const color &to, f32 t) const noexcept;

  [[nodiscard]] u32 as_hex() const noexcept;

  [[nodiscard]] color with_opacity(f32 opacity) const noexcept;

  /**
   * Gets red aluye
   */
  [[nodiscard]] u8 get_red() const noexcept {
    return static_cast<u8>(std::clamp(r * 255, 0.f, 255.f));
  }

  [[nodiscard]] u8 get_green() const noexcept {
    return static_cast<u8>(std::clamp(g * 255, 0.f, 255.f));
  }

  [[nodiscard]] u8 get_blue() const noexcept {
    return static_cast<u8>(std::clamp(b * 255, 0.f, 255.f));
  }

  [[nodiscard]] u8 get_alpha() const noexcept {
    return static_cast<u8>(std::clamp(a * 255, 0.f, 255.f));
  }

};


#endif //COLOR_HPP
