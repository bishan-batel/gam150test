//
// Created by bishan_ on 12/1/23.
//

#include "root_node.hpp"

RootNode::RootNode() :
  Node("Root") {
  is_initialised = true;
}

std::string RootNode::type_id() const {
  return "RootNode";
}
