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


		virtual void Update(float dt);
		virtual void Draw(hop::Renderer& renderer);

		friend class Scene;
		class Scene* m_scene = nullptr;
		hop::Transform m_transform;

	protected:
		bool m_destroyed = false;
		float m_lifespan = -1.0f;

		hop::Model m_model;
	};
}