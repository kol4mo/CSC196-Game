#include "FunGame.h"
#include "Player.h"
#include "Enemy.h"

#include "Framework//Scene.h"

#include "Audio/AudioSystem.h"
#include "Input/InputSystem.h"
#include "Renderer/Renderer.h"
#include "Renderer/Text.h"
#include "Renderer/ModelManager.h"

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
	case FunGame::eState::Game:
		AddPoints(7);
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
}

void FunGame::draw(hop::Renderer& renderer)
{
	if (m_state == eState::Title) {
		//title text	
	}

	m_scoreText->Draw(renderer, 40, 40);

	m_scene->Draw(renderer);
}
