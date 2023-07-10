#include "Core/core.h"
#include "Renderer/Renderer.h"
#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

class Star
{
public:
	Star(const hop::Vexctor2 pos, const hop::Vexctor2 vel) :
		m_pos{ pos },
		m_vel{ vel }
	{}

	void update(int width, int height)
	{
		m_pos += m_vel;
		if (m_pos.x >= width) m_pos.x = 0;
		if (m_pos.y >= height) m_pos.y = 0;
	}

	void Draw(hop::Renderer& renderer)
	{
		renderer.DrawPoint(m_pos.x, m_pos.y);
	}
public :
	hop::Vexctor2 m_pos;
	hop::Vexctor2 m_vel;
};

int main(int argc, char* argv[])
{
	hop::seedRandom((unsigned int)time(nullptr));

	vector<Star> stars;


	hop::Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("CSC196", 800, 600);

	for (int i = 0; i < 10000; i++) {
		hop::Vexctor2 pos(hop::random(renderer.GetWidth()), hop::random(renderer.GetHeight()));
		hop::Vexctor2 vel(hop::randomf(1, 5), 0.0f);

		stars.push_back(Star(pos, vel));
	}

	while (true)
	{
		renderer.SetColor(0, 0, 0, 255);
		renderer.BeginFrame();
		hop::Vexctor2 vel(2.5f, 0.1f);
		for (auto& star : stars) {

			star.update(renderer.GetWidth(), renderer.GetHeight());


			renderer.SetColor(hop::random(255), hop::random(255), hop::random(255), 255);
			star.Draw(renderer);
		}
		//draw
		//for (int i = 0; i < 1000; i++) {
		//	hop::Vexctor2 pos(hop::randomf(renderer.GetWidth()), hop::randomf(renderer.GetHeight()));
		//	renderer.SetColor(hop::random(255), hop::random(255), hop::random(255), hop::random(255));
		//	renderer.DrawPoint(pos.x, pos.y);
		//	//renderer.DrawLine(hop::random(renderer.GetWidth()), hop::random(renderer.GetHeight()), hop::random(renderer.GetWidth()), hop::random(renderer.GetHeight()));
		//}
		renderer.EndFrame();
	}

	return 0;
}