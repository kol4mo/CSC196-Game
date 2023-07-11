#include "Core/core.h"
#include "Renderer/Renderer.h"
#include "Renderer/Model.h"
#include "Input/InputSystem.h"
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
	hop::vec2 m_pos;
	hop::vec2 m_vel;
};

int main(int argc, char* argv[])
{
	hop::seedRandom((unsigned int)time(nullptr));

	vector<Star> stars;
	int r;
	int g;
	int b;

	hop::Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("CSC196", 800, 600);

	hop::InputSystem inputSystem;
	inputSystem.Initialize();

	std::vector<hop::vec2> points {{10, 5}, { 40,60 }, { 20,50 }, { 10, 5 }};
	hop::Model model(points);

	hop::vec2 v{ 5, 5};
	v.Normalize();

	for (int i = 0; i < 10000; i++) {
		hop::Vexctor2 pos(hop::random(renderer.GetWidth()), hop::random(renderer.GetHeight()));
		hop::Vexctor2 vel(hop::randomf(1, 3), 0.0f);

		stars.push_back(Star(pos, vel));
	}
	bool quit = false;
	while (!quit)
	{
		inputSystem.Update();
		if (inputSystem.GetKeyDown(SDL_SCANCODE_ESCAPE))
		{
			quit = true;
		}
		if (inputSystem.GetMouseButtonDown(0)) {
			cout << "mouse pressed" << endl;
		}
		cout << inputSystem.GetMousePosition().x << " " << inputSystem.GetMousePosition().y << endl;

		renderer.SetColor(0, 0, 0, 255); 
		renderer.BeginFrame();
		renderer.SetColor(hop::random(255), hop::random(255), hop::random(255), 255);
		hop::Vexctor2 vel(1.5f, 0.1f);
		model.Draw(renderer, {200, 300}, 2);
		for (auto& star : stars) {

			star.update(renderer.GetWidth(), renderer.GetHeight());
			r = star.m_pos.x / (renderer.GetWidth() / 255); r %= 255; r = 255 - r;
			g = star.m_pos.y / (renderer.GetHeight() / 255); g %= 255;
			b = star.m_pos.x / (renderer.GetWidth() / 255); b %= 255;

			renderer.SetColor(r , b, g, 255);
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