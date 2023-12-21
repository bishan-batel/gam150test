//
// Created by bishan_ on 12/9/23.
//

#include "shader.hpp"

#include <SDL_video.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <GL/glew.h>

#include "core/SceneTree.hpp"

namespace gl {
  Shader::Shader(const char *const source, const ShaderType type) :
    type(type) {
    shader_id = glCreateShader(type == VERTEX ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER);
    glShaderSource(shader_id, 1, &source, nullptr);
    glCompileShader(shader_id);

    i32 success;
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
    if (not success) {
      char infoLog[512];
      glGetShaderInfoLog(shader_id, std::size(infoLog), nullptr, infoLog);
      std::cerr << "Shader Compilation Failed" << infoLog << std::endl;
    }
  }

  Shader Shader::from_file(const std::string &file_path, const ShaderType type) {
    std::ifstream file(file_path);
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    std::string src = buffer.str();
    return Shader(src.c_str(), type);
  }

  Program::Program(const Shader fragment, const Shader vertex) :
    program_id(glCreateProgram()) {
    glAttachShader(program_id, fragment.get_id());
    glAttachShader(program_id, vertex.get_id());
    glLinkProgram(program_id);


    i32 success;
    glGetProgramiv(program_id, GL_LINK_STATUS, &success);
    if (not success) {
      char infoLog[512];
      glGetProgramInfoLog(program_id, std::size(infoLog), nullptr, infoLog);

      std::cerr << " Program linking Failed\n" << infoLog << std::endl;
    }

    glDeleteShader(fragment.get_id());
    glDeleteShader(vertex.get_id());
  }

  void Program::use() const {
    glUseProgram(program_id);
  }

  i32 Program::uniform(const char *const name) const {
    return glGetUniformLocation(program_id, name);
  }

  void Program::updateScreenSize(const bcake::SceneTree *tree) const {
    const auto size = tree->get_window_size();
    glUniform2f(uniform("screenSize"), static_cast<f32>(size.w), static_cast<f32>(size.h));
  }

} // bcake
