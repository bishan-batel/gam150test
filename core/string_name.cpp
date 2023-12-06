//
// Created by schro on 12/2/2023.
//

#include "string_name.hpp"

#include <regex>
#include <utility>

string_name::string_name(std::string _name) :
  name(std::move(_name)) {
  if (name.contains('.') || name.contains('/')) {
    throw bad_name();
  }
}

string_name::string_name(const string_name &name) :
  string_name(name.name) {}

bool string_name::empty() const noexcept {
  return name.empty();
}
