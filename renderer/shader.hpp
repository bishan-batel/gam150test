//
// Created by bishan_ on 12/9/23.
//

#ifndef SHADER_HPP
#define SHADER_HPP
#include <string_view>
#include <unordered_map>
#include <GL/glew.h>

#include "math/number.hpp"

namespace bcake {
  class SceneTree;
}

namespace gl {

  enum ShaderType : bool {
    FRAGMENT,
    VERTEX
  };

  class Shader {
    id shader_id;
    ShaderType type;

  public:
    explicit Shader(const char *source, ShaderType type);

    static Shader from_file(const std::string &file_path, ShaderType type);

    [[nodiscard]] id get_id() const { return shader_id; }
  };

  class Program {
    const id program_id;

  public:
    Program(Shader fragment, Shader vertex);

    void use() const;

    i32 uniform(const char *name) const;
    void updateScreenSize(const bcake::SceneTree *tree) const;

    [[nodiscard]] id get_id() const { return program_id; }
  };

} // bcake

#endif //SHADER_HPP
