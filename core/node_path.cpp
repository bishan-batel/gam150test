//
// Created by schro on 12/2/2023.
//

#include "node_path.hpp"

#include <iostream>

#include "string_name.hpp"

namespace bcake {
  node_path::node_path(const std::string &path) :
    parent_indirection(0) {
    // if (path.find('/') == std::string::npos) {
    //   segments.emplace_back(path);
    //   return;
    // }


    std::string str = path;
    usize pos = str.find('/');

    while (pos != std::string::npos) {
      if (const std::string token = str.substr(0, pos); token == ".") {}
      else if (token == "..") {
        if (segments.empty())
          parent_indirection++;
        else
          segments.pop_back();
      }
      else {
        segments.emplace_back(token);
      }
      str.erase(0, pos + 1);

      pos = str.find('/');
    }

    if (str == ".") {}
    else if (str == "..") {
      if (segments.empty())
        parent_indirection++;
      else
        segments.pop_back();
    }
    else {
      segments.emplace_back(str);
    }
  }

  std::ostream &operator<<(std::ostream &os, const node_path &path) {
    if (path.parent_indirection > 0) {
      os << "..";
      for (u32 i = 1; i < path.parent_indirection; i++)
        os << "/..";
    }
    else
      os << ".";

    for (const auto &segment : path.segments) {
      os << "/" << segment;
    }

    return os;
  }
}
