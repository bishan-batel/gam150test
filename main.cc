#include <iostream>
#include "node.h"
#include "vec2.h"


class Bdsfllsdjfu : public Node {
  [[nodiscard]] std::string type_id() const override { return "Bruh"; };

  void ready() override {}

public:
  Bdsfllsdjfu() :
    Node(typeid(this).name()) {}
};

int main() {


  auto root = new Node();
  auto huh = new Bdsfllsdjfu();
  root->add_child(huh);

  std::cout << root->get_name() << std::endl;
  std::cout << huh->get_name() << std::endl;


  const vec2 v(420, 0);


  const vec2 u(0, 69);

  const vec2 output = v + u;

  std::cout << typeid(output).name() << std::endl;


  return 0;
}
