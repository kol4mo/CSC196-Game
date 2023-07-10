#pragma once
#include "Core/core.h"
#include "Renderer.h"
#include <vector>

namespace hop
{
	class Model
	{
	public:
		Model() = default;
		Model(const std::vector<vec2>& points) : m_points{ points } {}

		void Draw(Renderer& renderer);

	private:
		std::vector<vec2> m_points;
	};
}