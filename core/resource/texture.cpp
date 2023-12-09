//
// Created by bishan_ on 12/8/23.
//

#include "texture.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <GL/glew.h>

namespace bcake {
  Texture::Texture(const std::string &path):
    IManagedResource(path) {
    Texture::load();
  }


  void Texture::load() {
    stbi_set_flip_vertically_on_load(true);

    i32 width, height, bpp;
    local_buffer = stbi_load(file_path.c_str(), &width, &height, &bpp, 4);

    this->width = width;
    this->height = height;
    this->bytes_per_pixel = bpp;

    glGenTextures(1, &renderer_id);
    glBindTexture(GL_TEXTURE_2D, renderer_id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, local_buffer);

    if (local_buffer) {
      stbi_image_free(local_buffer);
    }
  }

  Texture::~Texture() {
    glDeleteTextures(1, &renderer_id);
  }

  void Texture::bind(const u32 slot) const {
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, renderer_id);
  }

  void Texture::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
  }


  const char *Texture::type_id() {
    return "Texture";
  }
}
