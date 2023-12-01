//
// Created by bishan_ on 12/1/23.
//

#ifndef ROOT_HPP
#define ROOT_HPP
#include "node.h"


class RootNode final : public Node {
  RootNode();

public:
  [[nodiscard]] std::string type_id() const override;
};


#endif //ROOT_HPP
