#pragma once
#include <list>
#include "Actor.h"

namespace hop
{
	class Renderer;

	class Scene
	{
	public:
		Scene() = default;

		void Update(float dt);
		void Draw(Renderer& renderer);

		int getLength() { return m_actors.size(); }

		template<typename T>
		T* GetActor();

		void Add(std::unique_ptr<Actor> actor);
		void RemoveAll();


	private:
		std::list<std::unique_ptr<Actor>> m_actors;
	};

	template<typename T>
	inline T* Scene::GetActor()
	{
		for (auto& actor : m_actors) {
			T* result = dynamic_cast<T*> (actor.get());
			if (result) return result;
		}
		return nullptr;
	}
}