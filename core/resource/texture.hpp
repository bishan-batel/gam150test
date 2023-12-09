//
// Created by bishan_ on 12/8/23.
//

#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <string>

#include "IManagedResource.hpp"
#include "math/number.hpp"

namespace bcake {
  class Texture : IManagedResource {
    u16 width = 0, height = 0, bytes_per_pixel = 0;
    gl::id renderer_id = 0;

    u8 *local_buffer = nullptr;

  public:
    explicit Texture(const std::string &path);
    ~Texture() override;

    void bind(u32 slot = 0) const;
    static void unbind();

    void load() final;

    [[nodiscard]] u16 get_width() const { return width; }
    [[nodiscard]] u16 get_height() const { return height; }

    const char *type_id() override;
  };
}
#endif //TEXTURE_HPP
