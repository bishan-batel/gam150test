//
// Created by bishan_ on 12/8/23.
//

#include "sdl_test.hpp"

#include "nodes/sprite_node.hpp"

void bcake::SDLTest::ready() {

  const auto texture = std::make_shared<Texture>("assets/wate.png");

  for (auto i = 0; i < 5; i++) {
    add_child(new Bruh(texture, i / 5.f));
  }
}

void bcake::SDLTest::process(const f32 dt) {
  Node::process(dt);
}

bcake::Bruh::Bruh(const resource<Texture> &texture, const f32 offset) :
  Sprite(texture), time(offset), offset(offset) {}

void bcake::Bruh::process(const f32 dt) {
  Sprite::process(dt);
  time += dt;

  position.x = offset - 0.5f;
  position.z = std::sin(time) / 2.f;
}
