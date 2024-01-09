//
// Created by schro on 12/2/2023.
//

#ifndef NODE_2_D_HPP
#define NODE_2_D_HPP

#include "core/Node.hpp"
#include "core/event.hpp"
#include "math/mat3.hpp"


namespace bcake {
  class CanvasItem : public Node {
    friend class SceneTree;

    i64 z_index = 0, global_z_index = z_index;
    bool z_as_relative = false, visible = false;

    struct ZSort {
      bool operator ()(const CanvasItem *const &lhs, const CanvasItem *const &rhs) const noexcept;
    };

  protected:
    void register_to_tree() override;
    void unregister_to_tree() override;

  public:
    event<> on_render{};


    virtual void render() const;

    [[nodiscard]] const char *type_id() const noexcept override;
  };

}

#endif //NODE_2_D_HPP
