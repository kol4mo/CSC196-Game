#include "Enemy.h"
#include "Renderer/Renderer.h"
	void Enemy::Update(float dt)
	{
		hop::vec2 forward = hop::vec2{ 0, -1 }.Rotate(m_transform.rotation);
		m_transform.position += forward * m_speed * hop::g_time.GetDeltaTime();
		m_transform.position.x = hop::Wrap(m_transform.position.x, (float)hop::g_renderer.GetWidth());
		if (m_transform.position.y == hop::g_renderer.GetHeight() || m_transform.position.y == 0 || m_transform.position.x == hop::g_renderer.GetWidth() || m_transform.position.x == 0) {
			m_scene->Remove(this);
		}
	}
