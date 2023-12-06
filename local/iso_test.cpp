//
// Created by bishan_ on 12/5/23.
//

#include "iso_test.hpp"

#include <Mouse.hpp>

#include "core/SceneTree.hpp"
#include "math/vec2.hpp"
#include "nodes/sprite_node.hpp"

void IsoTestScene::ready() {
  std::cout << "init" << std::endl;

  constexpr auto size = 8;
  for (auto y = 0; y < size; y++) {
    for (auto x = 0; x < size; x++) {
      auto coord = vec2(static_cast<f32>(x) - size / 2.f, static_cast<f32>(y) - size / 2.f);
      coord = coord * 4.f * 32.f;

      coord = vec2(coord.dot(vec2(0.5f, -0.5f)), coord.dot(vec2(0.25f, 0.25f)));

      const auto sprite = new Sprite("assets/iso.png");
      coord += vec2(500 - 2.f * 32.f, 500.f);
      sprite->position = coord;
      add_child(sprite);
      sprites.emplace_back(sprite, sprite->position);
    }
  }
}

void IsoTestScene::process(const f32 dt) {

  for (const auto &[sprite, pos] : sprites) {
    sprite->position = pos;

    constexpr auto scale = 0.01f;
    sprite->position.y += (std::cos(scale * pos.x + time) + std::sin(scale * pos.y + time)) * 32.f;

    // const auto mouse = vec2(static_cast<f32>(raylib::Mouse::GetX()), static_cast<f32>(raylib::Mouse::GetY()));
    // const auto dist = (-vec2(16.f, 16.f) * 4.f + mouse - pos).len2() * 1E-5f;
    // sprite->position.y += 4.f * 32.f / (dist + 1.f);
    sprite->position = (sprite->position / 2.f).round() * 2.f;
  }
  time += dt * 1.f;

  if (std::fmod(time, 3.f) < dt) {
    sprites.back().first->queue_free();
    sprites.pop_back();

    get_tree()->change_scene(std::make_unique<IsoTestScene>());
  }
}
