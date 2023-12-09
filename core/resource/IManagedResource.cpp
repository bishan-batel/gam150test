//
// Created by bishan_ on 12/8/23.
//

#include "IManagedResource.hpp"

#include <utility>

namespace bcake {
  IManagedResource::IManagedResource(std::string file_path) :
    file_path(std::move(file_path)) {}
}
