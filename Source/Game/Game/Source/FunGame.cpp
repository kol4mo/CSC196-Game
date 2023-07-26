#include "FunGame.h"
#include "Player.h"
#include "Enemy.h"

#include "Framework//Scene.h"
#include "Core/core.h"
#include "Audio/AudioSystem.h"
#include "Input/InputSystem.h"
#include "Renderer/Renderer.h"
#include "Renderer/Text.h"
#include "Renderer/ModelManager.h"
#include "Framework/Emitter.h"

bool FunGame::Initialize()
{

	m_font = std::make_shared<hop::Font>("Arcade.ttf", 58);

	m_scoreText = std::make_unique<hop::Text>(m_font);
	m_scoreText->Create(hop::g_renderer, "SCORE 0000", hop::Color(1, 1, 1, 1));
	hop::g_audioSystem.AddAudio("explode", "explode.wav");

	m_scene = std::make_unique<hop::Scene>();

	//for (int i = 0; i < (x * x); i++) {
	//	unique_ptr<Enemy> enemy = make_unique<Enemy>(200, 0, hop::Transform{{hop::random(hop::g_renderer.GetWidth()), hop::random(hop::g_renderer.GetHeight())}, hop::randomDir(), 3}, hop::g_modelManager.Get("S.txt"));
	//	enemy->m_tag = "Enemy";
	//	enemy->m_game = this;
	//	scene->Add(std::move(enemy));
	//}
	return true;
}

void FunGame::shutdown()
{
}

void FunGame::update(float dt)
{
	switch (m_state)
	{
	case FunGame::eState::Title:
		if (hop::g_inputSystem.GetKeyDown(SDL_SCANCODE_SPACE))
		{
			m_state = eState::StartGame;
		}
		break;
	case FunGame::eState::StartGame:
		m_score = 0;
		m_lives = 3;
		m_state = eState::StartLevel;
		break;
	case FunGame::eState::StartLevel:
	{	
		m_scene->RemoveAll();
		m_scene->Add(std::move(std::make_unique<Player>(300.0f, 0, hop::Transform{ {400, 300}, 0, 6 }, hop::g_modelManager.Get("S.txt"))));
		//expand and aadd player->m_game = this;
	}
	m_state = eState::Game;
		break;
	case FunGame::eState::Game: {
		hop::EmitterData data;
		data.burst = true;
		data.burstCount = 100;
		data.spawnRate = 200;
		data.angle = 0;
		data.angleRange = hop::PI;
		data.lifetimeMin = 0.5f;
		data.lifetimeMin = 1.5f;
		data.speedMin = 50;
		data.speedMax = 250;
		data.damping = 0.5f;
		data.color = hop::Color{ 1, 0, 0, 1 };
		hop::Transform transform{ { hop::g_inputSystem.GetMousePosition() }, 0, 1 };
		auto emitter = std::make_unique<hop::Emitter>(transform, data);
		emitter->m_lifespan = 1.0f;
		m_scene->Add(std::move(emitter));

		AddPoints(7);
	}
		break;
	case FunGame::eState::PlayerDead:
		if (m_lives == 0) m_state = eState::GameOver;
		else m_state = eState::StartLevel;
		break;
	case FunGame::eState::GameOver:
		break;
	default:
		break;
	}

	m_scoreText->Create(hop::g_renderer, std::to_string(m_score), { 1, 1, 1, 1 });

	m_scene->Update(dt);
	hop::g_particleSystem.Update(dt);
}

void FunGame::draw(hop::Renderer& renderer)
{
	if (m_state == eState::Title) {
		//title text	
	}

	m_scoreText->Draw(renderer, 40, 40);

	hop::g_particleSystem.Draw(renderer);
	m_scene->Draw(renderer);
}
