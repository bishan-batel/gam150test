//
// Created by bishan_ on 12/8/23.
//

#ifndef SDL_TEST_HPP
#define SDL_TEST_HPP
#include "core/Node.hpp"
#include "nodes/sprite_node.hpp"


namespace bcake {
  class SDLTest final : public Node {

    void ready() override;
    void process(f32 dt) override;
  };

  class Bruh final : public Sprite {
    f32 time, offset;

  public:
    explicit Bruh(const handle<Texture> &texture, f32 offset);

    void process(f32 dt) override;
  };
}


#endif //SDL_TEST_HPP
