#include "Player.h"
#include "Input/InputSystem.h"

void Player::Update(float dt)
{
	float rotate = 0;
	if (hop::g_inputSystem.GetKeyDown(SDL_SCANCODE_A)) rotate = -1;
	if (hop::g_inputSystem.GetKeyDown(SDL_SCANCODE_D)) rotate = 1;
	m_transform.rotation += rotate * m_turnRate * hop::g_time.GetDeltaTime();

	float thrust = 0;
	if (hop::g_inputSystem.GetKeyDown(SDL_SCANCODE_W)) thrust = 1;

	hop::vec2 forward = hop::vec2{ 0, -1 }.Rotate(m_transform.rotation);
	m_transform.position += forward * m_speed * thrust * hop::g_time.GetDeltaTime();
	m_transform.position.x = hop::Wrap(m_transform.position.x, (float)hop::g_renderer.GetWidth());
	m_transform.position.y = hop::Wrap(m_transform.position.y, (float)hop::g_renderer.GetHeight());
}


