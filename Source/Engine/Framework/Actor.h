#pragma once
#include "Core/core.h"
#include "Renderer/Model.h"

namespace hop
{
	class Actor
	{
	public:
		Actor() = default;
		Actor(const hop::Transform& transform, const hop::Model& model) :
			m_transform{ transform },
			m_model{ model }
		{}


		virtual void Update(float dt) = 0;
		virtual void Draw(hop::Renderer& renderer);

		friend class Scene;
		class Scene* m_scene = nullptr;

	protected:
		hop::Transform m_transform;
		hop::Model m_model;
	};
}