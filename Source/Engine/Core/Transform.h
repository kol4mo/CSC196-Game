#pragma once
#include "core.h"

namespace hop
{
	class Transform
	{
	public:
		vec2 position;
		float rotation;
		float scale;

	public:
		Transform(const vec2& position, float  rotation, float scale = 1) :
			position{ position },
			rotation{ rotation },
			scale{ scale } {}

	};
}