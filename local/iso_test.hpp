#pragma once

#include "core/Node.hpp"
#include "math/vec2.hpp"
#include "nodes/sprite_node.hpp"


class IsoTestScene final : public Node {
  std::vector<std::pair<Sprite *, vec2>> sprites;
  f32 time = 0;

  void ready() override;

  void process(f32 dt) override;
};
