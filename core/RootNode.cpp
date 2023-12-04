//
// Created by bishan_ on 12/1/23.
//

#include "RootNode.hpp"

RootNode::RootNode() : Node("Root") {
	is_initialised = true;
}

const char* RootNode::type_id() const noexcept {
	return {"RootNode"};
}
