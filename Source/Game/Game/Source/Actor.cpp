#include "Actor.h"

void Actor::Draw(hop::Renderer& renderer)
{
	m_model.Draw(renderer, m_transform);
}
