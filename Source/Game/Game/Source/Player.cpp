#include "Player.h"
#include "Input/InputSystem.h"
#include "Weapon.h"
#include "Framework/Scene.h"
#include "FunGame.h"
#include <cmath>

void Player::Update(float dt)
{

	Actor::Update(dt);
	hop::vec2 forward = hop::vec2{ 0,0 };
	if (hop::g_inputSystem.GetKeyDown(SDL_SCANCODE_A)) forward += {-1, 0};
	if (hop::g_inputSystem.GetKeyDown(SDL_SCANCODE_D)) forward += {1, 0};
	if (hop::g_inputSystem.GetKeyDown(SDL_SCANCODE_W)) forward += {0,-1};
	if (hop::g_inputSystem.GetKeyDown(SDL_SCANCODE_S)) forward += {0, 1};

	if ((std::fabs(forward.x) + std::fabs(forward.y)) == 2) {
		forward * 0.707;
	}

	m_transform.position += forward * m_speed * hop::g_time.GetDeltaTime();
	m_transform.position.x = hop::Wrap(m_transform.position.x, hop::g_renderer.GetWidth());
	m_transform.position.y = hop::Wrap(m_transform.position.y, hop::g_renderer.GetHeight());

	if (hop::g_inputSystem.GetKeyDown(SDL_SCANCODE_SPACE) && !hop::g_inputSystem.GetPreviousKeyDown(SDL_SCANCODE_SPACE)) {

		hop::Transform transform{m_transform.position, m_transform.rotation, 1};
		std::unique_ptr<Weapon> weapon = std::make_unique<Weapon>( 400.0f, m_transform, m_model );
		m_scene->Add(std::move(weapon));
	}
}

void Player::OnCollision(Actor* actor)
{
	if (actor->m_tag == "Enemy") {
		//m_game->SetLives(m_game->GetLives() - 1);
		//dynamic_cast<SpaceGame*>(m_game)->SetState(FunGame::)
	}
}


