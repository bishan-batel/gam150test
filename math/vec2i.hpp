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
};


#endif //VEC_2_I_HPP
