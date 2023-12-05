//
// Created by schro on 12/2/2023.
//

#include "StringName.hpp"

#include <regex>
#include <utility>

StringName::StringName(std::string _name) :
  name(std::move(_name)) {
  if (name.contains('.') || name.contains('/')) {
    throw bad_name();
  }
}

StringName::StringName(const StringName &name) :
  StringName(name.name) {}

bool StringName::empty() const noexcept {
  return name.empty();
}

StringName::operator std::string() const noexcept {
  return name;
}
