//
// Created by bishan_ on 12/8/23.
//

#ifndef RESOURCE_HPP
#define RESOURCE_HPP
#include <memory>
#include <string>

#include "math/number.hpp"


namespace bcake {
  class IManagedResource {
  protected:
    const std::string file_path;

  public:
    explicit IManagedResource(std::string file_path);
    virtual ~IManagedResource() = default;

    virtual void load() = 0;

    virtual const char *type_id() = 0;

    [[nodiscard]] const std::string &get_file_path() const { return file_path; }
  };

  template <class T> requires std::is_base_of_v<IManagedResource, T>
  using resource = std::shared_ptr<T>;

}
#endif //RESOURCE_HPP
