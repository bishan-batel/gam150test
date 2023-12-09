//
// Created by bishan_ on 12/5/23.
//

#include "iso_test.hpp"

#include <stb_image.h>
#include <core/resource/texture.hpp>
#include "core/SceneTree.hpp"
#include "math/vec2.hpp"
#include "nodes/sprite_node.hpp"

constexpr auto TILE_WIDTH = 16.f;
constexpr auto SPRITE_SCALE = 4.f;

namespace bcake {
  void IsoTestScene::ready() {

    stbi_set_flip_vertically_on_load(1);
    texture = std::make_shared<bcake::Texture>("assets/wate.png");

    constexpr auto size = 44;
    for (auto y = 0; y < size; y++) {
      for (auto x = 0; x < size; x++) {
        auto coord = vec2(static_cast<f32>(x) - size / 2.f, static_cast<f32>(y) - size / 2.f);
        coord = coord * SPRITE_SCALE * TILE_WIDTH;

        coord = vec2(coord.dot(vec2(0.5f, -0.5f)), coord.dot(vec2(0.25f, 0.25f)));

        coord += vec2(500 - TILE_WIDTH * SPRITE_SCALE / 2, 500.f);
        add_child(new TestSprite(texture, coord));
      }
    }
  }


  TestSprite::TestSprite(const std::shared_ptr<const bcake::Texture> &texture, const vec2 pos) :
    Sprite(texture),
    time(0.f), real_position(pos), og_position(pos) {}

  const char *TestSprite::type_id() const noexcept {
    return "TestSprite";
  }

  void TestSprite::ready() {}

  void TestSprite::process(const f32 dt) {

    vec2 target = og_position;

    constexpr auto scale = 0.014f;
    target.y += (std::cos(scale * og_position.x + time) + std::sin(scale * og_position.y + time)) * 16.f;


    // if (raylib::Mouse::IsButtonDown(0)) {
    //   const auto mouse = vec2(static_cast<f32>(raylib::Mouse::GetX()), static_cast<f32>(raylib::Mouse::GetY()));
    //   const auto dist = (-vec2(TILE_WIDTH) / 2 * SPRITE_SCALE + mouse - og_position).len();
    //   target.y -= SPRITE_SCALE * 8.f / (dist * 1E-3f + 1.f);
    //   // target.y -= std::sin(dist * 1E-2f + time * 3.f) * 4.f * 16.f * std::exp(-dist * dist * 1E-5f);
    //   target -= (mouse - og_position).normalised() * std::exp(-dist * dist * 1E-5f) * TILE_WIDTH / 2 * SPRITE_SCALE;
    // }

    // position = position.lerp(target, dt * 1.f);

    constexpr auto coeff = 100.f;
    constexpr auto friction = 0.93f;

    vel += (target - real_position) * dt * coeff;
    vel *= friction;
    real_position += vel * dt;
    constexpr auto a = SPRITE_SCALE / 2;
    position = ((real_position / a).floor() * a).to3D(1); // position = target;
    time += dt * 3.f;
  }
}
