//
// Created by bishan_ on 12/1/23.
//

#ifndef ROOT_HPP
#define ROOT_HPP
#include "Node.hpp"


class RootNode final : public Node {
	friend class SceneTree;
	RootNode();

public:
	[[nodiscard]] const char* type_id() const noexcept override;
};


#endif //ROOT_HPP
