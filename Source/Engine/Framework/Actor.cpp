#include "Actor.h"

namespace hop
{
	void Actor::Draw(hop::Renderer& renderer)
	{
		m_model.Draw(renderer, m_transform);
	}
}
