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

		bool Load(const std::string& filename);

		void Draw(Renderer& renderer, const vec2& position, float rotation, float scale);

	private:
		std::vector<vec2> m_points;
	};
}