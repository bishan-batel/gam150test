//
// Created by bishan_ on 12/5/23.
//

#ifndef SPRITE_NODE_HPP
#define SPRITE_NODE_HPP

#include "CanvasItem.hpp"

#include "core/resource/texture.hpp"
#include "math/vec2.hpp"
#include "renderer/shader.hpp"

namespace bcake {
  class Sprite : public CanvasItem {
    std::unique_ptr<gl::Program> program;
    gl::id buffer = 0, vao = 0;

  public:
    // const signal<void(vec3 bruh)> on_move = _create_event<f32>("bruh");
    // SIGNAL(on_render, vec3 bruh);

    const handle<const Texture> texture;
    vec3 position;

  protected:
    void render() const override;

  public:
    explicit Sprite(const handle<const Texture> &texture);
  };
}

#endif //SPRITE_NODE_HPP
