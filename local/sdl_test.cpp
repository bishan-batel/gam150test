//
// Created by bishan_ on 12/8/23.
//

#include "sdl_test.hpp"

#include <queue>

#include "core/SceneTree.hpp"
#include "math/vec2i.hpp"
#include "nodes/sprite_node.hpp"

void bcake::SDLTest::ready() {

  const auto texture = std::make_shared<Texture>("assets/wate_bruh.png");
  // const auto texture = std::make_shared<Texture>("assets/test.png");

  constexpr auto size = 5.f;

  // const auto screen = get_tree()->get_window_size();
  // const auto offset = (vec2(screen.x, screen.y) / 10. / 2.).to3D(0.);
  // const auto offset = (vec2(100.f) / 4.f).to3D(0.f);
  // const auto offset = vec2::ZERO.to3D(0.);
  const auto offset = vec3(0., 100., 0.);

  std::queue<Bruh *> bruh;
  for (auto x = 0.f; x < size; x++) {
    for (auto y = 0.f; y < size; y++) {
      const auto node = new Bruh(texture, 0.f);

      constexpr auto tile_size = 0.f;
      node->position = vec3(x - size / 2 - tile_size, y - size / 2 - tile_size, 0.f);
      node->position *= 16.f;
      node->position += offset;
      bruh.emplace(node);
    }
  }

  while (not bruh.empty()) {
    const auto child = bruh.front();
    bruh.pop();

    if (std::rand() % 1 == 0) {
      add_child(child);
      continue;
    }
    bruh.emplace(child);
  }
}

void bcake::SDLTest::process(const f32 dt) {
  Node::process(dt);
}

bcake::Bruh::Bruh(const handle<Texture> &texture, const f32 offset) :
  Sprite(texture), time(offset), offset(offset) {}

void bcake::Bruh::process(const f32 dt) {
  Sprite::process(dt);
  time += dt * .5f;

  // position.x = offset - 0.5f;
  constexpr auto scale = 50.f;
  position.z = -1.f;
  position.z -= std::max(0.f, std::sin(time + position.x / scale) * std::cos(time + position.y / scale) * 16.f);
  // position.z = std::round(position.z * 32.f) / 32.f;
}
