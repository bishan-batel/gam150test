//
// Created by bishan_ on 12/8/23.
//

#include "color.hpp"

color color::mix(const color &to, const f32 t) const noexcept {
  return {
    r + (to.r - r) * t,
    g + (to.g - g) * t,
    b + (to.b - b) * t,
    a + (to.a - a) * t,
  };
}

u32 color::as_hex() const noexcept {
  const auto r_byte = static_cast<u8>(r * 255.f);
  const auto g_byte = static_cast<u8>(g * 255.f);
  const auto b_byte = static_cast<u8>(b * 255.f);
  const auto a_byte = static_cast<u8>(a * 255.f);

  return r_byte << 12 | g_byte << 8 | b_byte << 4 | a_byte;
}

color color::with_opacity(const f32 opacity) const noexcept {
  return rgba(r, g, b, opacity);
}
