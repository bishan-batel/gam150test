#pragma once

#include "core/Node.hpp"
#include "core/resource/texture.hpp"
#include "math/vec2.hpp"
#include "nodes/sprite_node.hpp"


namespace bcake {
  class IsoTestScene final : public Node {
    f32 time = 0;
    std::shared_ptr<bcake::Texture> texture;

  protected:
    void ready() override;
  };

  class TestSprite final : public Sprite {
    f32 time;
    vec2 vel = vec2::ZERO, real_position;
    const vec2 og_position;

  public:
    explicit TestSprite(const std::shared_ptr<const bcake::Texture> &texture, vec2 pos);

    [[nodiscard]] const char *type_id() const noexcept override;

  protected:
    void ready() override;;
    void process(f32 dt) override;
  };
}
