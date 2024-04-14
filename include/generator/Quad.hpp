// Added by Ryan Cleven
// Derived from:
// Copyright 2015 Markus Ilmola
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.

#ifndef GENERATOR_QUAD_HPP
#define GENERATOR_QUAD_HPP

#include "math.hpp"

namespace generator {



class Quad {
public:

	/// Zero based indices of the quad vertices in counterclockwise order.
	gml::ivec4 vertices;

	Quad() noexcept :
		vertices{}
	{ }

	explicit Quad(const gml::ivec4& vertices) noexcept :
		vertices{vertices}
	{ }

};

}

#endif
