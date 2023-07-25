#include "Enemy.h"
#include "Renderer/Renderer.h"
#include  "Framework/Scene.h"
#include "Player.h"
#include "Weapon.h"
#include "FunGame.h"

	void Enemy::Update(float dt)
	{
		Actor::Update(dt);
		/*
		Player* player = m_scene->GetActor<Player>();
		if (player)
		{
			hop::Vexctor2 direction = player->m_transform.position - m_transform.position;
			m_transform.rotation = direction.Angle() + hop::halfPi;
		}*/



		hop::vec2 forward = hop::vec2{ 0, -1 }.Rotate(m_transform.rotation);
		m_transform.position += forward * m_speed * hop::g_time.GetDeltaTime();
		//m_transform.position.x = hop::Wrap(m_transform.position.x, (float)hop::g_renderer.GetWidth());
		if (m_transform.position.y >= hop::g_renderer.GetHeight() || m_transform.position.y <= 0 || m_transform.position.x >= hop::g_renderer.GetWidth() || m_transform.position.x <= 0) {
			m_destroyed = true;
		}
		/*
		if (m_fireTimer <= 0) {
			hop::Transform transform{m_transform.position, m_transform.rotation, 1};
			std::unique_ptr<Weapon> weapon = std::make_unique<Weapon>(400.0f, transform, m_model);
			m_scene->Add(std::move(weapon));
			m_fireTimer = m_fireTime;
		}
		else {
			m_fireTimer -= dt;
		}
		*/
	}

	void Enemy::OnCollision(Actor* actor)
	{
	}
