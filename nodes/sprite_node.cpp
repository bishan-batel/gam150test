//
// Created by bishan_ on 12/5/23.
//

#include "sprite_node.hpp"

#include <Texture.hpp>

Sprite::Sprite(const std::string &path) :
  texture(raylib::Texture(path)), position(vec2::ZERO) {}

void Sprite::render() const {
  const auto pos = vec2(
    position.x,
    position.y
    );
  texture.Draw(pos, 0.f, 4.f);
}
