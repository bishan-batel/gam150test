//
// Created by bishan_ on 12/8/23.
//

#ifndef COLOR_HPP
#define COLOR_HPP
#include "number.hpp"


union color {
  struct {
    f32 x, y, z, w;
  };

  struct {
    f32 r, g, b, a;
  };

  constexpr static color rgba(const f32 r, const f32 g, const f32 b, const f32 a = 1.f) {
    return {r, g, b, a};
  }

  /**
   * Converts colors with integer range 0-255 to floating point 0-1
   */
  constexpr static color normalise(const u8 r, const u8 g, const u8 b, const u8 a = 255) {
    return {
      static_cast<f32>(r) / 255.f,
      static_cast<f32>(g) / 255.f,
      static_cast<f32>(b) / 255.f,
      static_cast<f32>(a) / 255.f
    };
  }

  constexpr static color hex(const u32 hex) {
    return normalise(
      hex >> 12 & 0xf,
      hex >> 8 & 0xf,
      hex >> 4 & 0xf,
      hex & 0xf
      );
  }
};


#endif //COLOR_HPP
