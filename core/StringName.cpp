//
// Created by schro on 12/2/2023.
//

#include "StringName.hpp"

#include <utility>
#include <ranges>
#include <regex>

StringName::StringName(std::string _name) : name(std::move(_name)) {
	if (name.contains('.') || name.contains('/')) {
		throw bad_name();
	}
}

StringName::operator std::string() const noexcept {
	return name;
}
