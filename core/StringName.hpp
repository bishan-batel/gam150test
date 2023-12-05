//
// Created by schro on 12/2/2023.
//

#ifndef NODE_STRING_HPP
#define NODE_STRING_HPP
#include <string>


class StringName {
  const std::string name;

public:
  // static constkkk
  // ReSharper disable once CppNonExplicitConvertingConstructor
  StringName(std::string _name); // NOLINT(*-explicit-constructor)

  StringName(const StringName &name);

  [[nodiscard]] bool empty() const noexcept;

  // ReSharper disable once CppNonExplicitConversionOperator
  operator std::string() const noexcept; // NOLINT(*-explicit-constructor)
};

class bad_name final : std::exception {
  [[nodiscard]] const char *what() const noexcept override {
    return "Invalid String Name";
  }
};


#endif //NODE_STRING_HPP
