//
// Created by schro on 12/2/2023.
//

#ifndef NODE_PATH_HPP
#define NODE_PATH_HPP
#include <string>
#include <vector>
#include <math/number.hpp>
#include <ostream>


class NodePath final {
	std::vector<std::string> segments;
	u16 parent_indirection;

public:
	// ReSharper disable once CppNonExplicitConvertingConstructor
	/**
	 * \brief 
	 * \param path 
	 */
	NodePath(const std::string&path); // NOLINT(*-explicit-constructor)


	// ReSharper disable once CppNonExplicitConversionOperator
	friend std::ostream& operator <<(std::ostream&os, const NodePath&path); // NOLINT(*-explicit-constructor)
};


#endif //NODE_PATH_HPP
