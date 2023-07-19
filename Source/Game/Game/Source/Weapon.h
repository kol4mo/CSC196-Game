#pragma once
#include "Framework/Actor.h"

class Weapon : public hop::Actor
{
public:
	Weapon(float speed, const hop::Transform& transform, const hop::Model& model) :
		Actor{ transform, model },
		m_speed{ speed }
	{
		m_lifespan = 2.0f;
	}
	void Update(float dt) override;

private:
	float m_speed = 0;
};