//
// Created by schro on 12/2/2023.
//

#ifndef NODE_2_D_HPP
#define NODE_2_D_HPP

#include "..\core\Node.hpp"


class Node2D : public Node {
public:
	Node2D();

	[[nodiscard]] const char* type_id() const noexcept override;
};


#endif //NODE_2_D_HPP
