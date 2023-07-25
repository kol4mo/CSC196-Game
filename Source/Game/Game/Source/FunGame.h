#pragma once
#include "Framework/Game.h"
#include "Renderer/Text.h"

class FunGame : public hop::Game {
public:
	enum class eState
	{
		Title,
		StartGame,
		StartLevel,
		Game,
		PlayerDead,
		GameOver
	};


public:

	// Inherited via Game
	virtual bool Initialize() override;

	virtual void shutdown() override;

	virtual void update(float dt) override;

	virtual void draw(hop::Renderer& renderer) override;

	void SetState(eState state) { m_state = state; }

private:
	eState m_state = eState::Title;
	std::shared_ptr<hop::Font> m_font;
	std::unique_ptr<hop::Text> m_scoreText;
};