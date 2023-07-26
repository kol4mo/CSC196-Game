#pragma once
#include "Core/core.h"
#include "Renderer/Model.h"
#include <memory>

namespace hop
{
	class Actor
	{
	public:
		Actor() = default;
		Actor(const hop::Transform& transform, std::shared_ptr<Model> model) :
			m_transform{ transform },
			m_model{ model }
		{}
		Actor(const hop::Transform & transform) :
			m_transform{ transform }
		{}


		virtual void Update(float dt);
		virtual void Draw(hop::Renderer& renderer);

		float GetRadius() { return (m_model) ? m_model->getRadius() * m_transform.scale : 0; }
		virtual void OnCollision(Actor* other) {};

		friend class Scene;

		class game* m_game = nullptr;

		class Scene* m_scene = nullptr;
		hop::Transform m_transform;
		std::string m_tag;

		float m_lifespan = -1.0f;
	protected:
		bool m_destroyed = false;

		std::shared_ptr<hop::Model> m_model;
	};
}