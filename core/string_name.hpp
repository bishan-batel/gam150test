//
// Created by schro on 12/2/2023.
//

#ifndef NODE_STRING_HPP
#define NODE_STRING_HPP
#include <string>


class string_name {
  const std::string name;

public:
  // static constkkk
  // ReSharper disable once CppNonExplicitConvertingConstructor
  string_name(std::string _name); // NOLINT(*-explicit-constructor)

  string_name(const string_name &name);

  [[nodiscard]] bool empty() const noexcept;

  // ReSharper disable once CppNonExplicitConversionOperator
  operator std::string() const noexcept { return name; } // NOLINT(*-explicit-constructor)
};

class bad_name final : std::exception {
  [[nodiscard]] const char *what() const noexcept override {
    return "Invalid String Name";
  }
};


#endif //NODE_STRING_HPP
