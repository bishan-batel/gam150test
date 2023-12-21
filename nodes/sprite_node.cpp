//
// Created by bishan_ on 12/5/23.
//

#include "sprite_node.hpp"
#include <GL/glew.h>

#include "renderer/shader.hpp"

namespace bcake {
  const auto VERT_SHADER_SOURCE = "assets/shaders/sprite.frag";
  const auto FRAG_SHADER_SOURCE = "assets/shaders/sprite.vert";

  Sprite::Sprite(const handle<const Texture> &texture) :
    program(nullptr), texture(texture), position(vec3::ZERO) {

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // program
    program = std::make_unique<gl::Program>(
      gl::Shader::from_file("assets/shaders/sprite.frag", gl::FRAGMENT),
      gl::Shader::from_file("assets/shaders/sprite.vert", gl::VERTEX)
      );


    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);

    // ReSharper disable once CppVariableCanBeMadeConstexpr
    // const static f32 vertex_data[] = {
    //   -0.5f, -0.5f,
    //   0.5f, -0.5f,
    //   0.5f, 0.5,
    //
    //   0.5f, 0.5f,
    //   -0.5f, 0.5f,
    //   -0.5f, -0.5,
    // };
    // ReSharper disable once CppVariableCanBeMadeConstexpr
    const static f32 vertex_data[] = {
      -0.5f, -0.5f,
      0.5f, -0.5f,
      0.5f, 0.5,

      0.5f, 0.5f,
      -0.5f, 0.5f,
      -0.5f, -0.5,
    };
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_data), vertex_data, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);
    glBindAttribLocation(program->get_id(), 0, "vertexPosition");

    on_render.connect(*this, [] {});
  }

  void Sprite::render() const {
    // Setup shader program
    {
      program->use();

      // const auto transform = mat4::translation(position);
      // glUniformMatrix4fv(program->uniform("model"), 16, true, transform.vals);
      glUniform3f(program->uniform("model"), position.x, position.y, position.z);

      program->updateScreenSize(get_tree());
      const auto size = vec2(texture->get_width(), texture->get_height());
      glUniform2f(program->uniform("spriteSize"), size.x, size.y);
    }

    glBindVertexArray(vao);
    texture->bind();

    glDrawArrays(GL_TRIANGLES, 0, 6);
    texture->unbind();
  }
}
