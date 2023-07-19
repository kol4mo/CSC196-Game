#include "Scene.h"

namespace hop
{
	void Scene::Update(float dt)
	{
		for (auto& actor : m_actors) actor->Update(dt);
	}

	void Scene::Draw(Renderer& renderer)
	{
		for (auto& actor : m_actors) actor->Draw(renderer);
	}

	void Scene::Add(std::unique_ptr<Actor> actor)
	{
		actor->m_scene = this;
		m_actors.push_back(std::move(actor));
	}

	void Scene::Remove(std::unique_ptr<Actor> actor)
	{
		m_actors.remove(actor);
	}

	void Scene::RemoveAll()
	{
		m_actors.clear();
	}
}