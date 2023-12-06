//
// Created by schro on 12/2/2023.
//

#ifndef NODE_PATH_HPP
#define NODE_PATH_HPP
#include <string>
#include <vector>
#include <math/number.hpp>
#include <ostream>


class string_name;

class node_path final {
  friend class Node;
  std::vector<std::string> segments;
  u16 parent_indirection;

public:
  // ReSharper disable once CppNonExplicitConvertingConstructor
  /**
   * \brief
   * \param path
   */
  node_path(const std::string &path); // NOLINT(*-explicit-constructor)


  friend std::ostream &operator <<(std::ostream &os, const node_path &path);
};


#endif //NODE_PATH_HPP
