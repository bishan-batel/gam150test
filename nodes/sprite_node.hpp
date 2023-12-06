//
// Created by bishan_ on 12/5/23.
//

#ifndef SPRITE_NODE_HPP
#define SPRITE_NODE_HPP

#include <Texture.hpp>

#include "CanvasItem.hpp"


class Sprite final : public CanvasItem {

protected:
  void render() const override;

public:
  raylib::Texture texture;
  vec2 position;

  explicit Sprite(const std::string &path);
};


#endif //SPRITE_NODE_HPP
