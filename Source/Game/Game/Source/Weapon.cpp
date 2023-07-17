#include "Weapon.h"

void Weapon::Update(float dt)
{
	hop::vec2 forward = hop::vec2{ 0, -1 }.Rotate(m_transform.rotation);
	m_transform.position += forward * m_speed * hop::g_time.GetDeltaTime();
	m_transform.position.x = hop::Wrap(m_transform.position.x, (float)hop::g_renderer.GetWidth());
	m_transform.position.y = hop::Wrap(m_transform.position.y, (float)hop::g_renderer.GetHeight());
}
