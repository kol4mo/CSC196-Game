#include "Core/core.h"
#include "Renderer/Renderer.h"
#include "Renderer/Model.h"
#include "Input/InputSystem.h"
#include <iostream>
#include <chrono>
#include <vector>
#include <thread>

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
		m_pos += m_vel * hop::g_time.GetDeltaTime();
		if (m_pos.x > width) m_pos.x = 0;
		if (m_pos.y > height) m_pos.y = 0;
		if (m_pos.x < 0) m_pos.x = width;
		if (m_pos.y < 0) m_pos.y = height;
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
	hop::setFilePath("Assets");

	vector<Star> stars;
	int r;
	int g;
	int b;

	hop::Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("CSC196", 1920, 1080);

	hop::InputSystem inputSystem;
	inputSystem.Initialize();

	//std::vector<hop::vec2> points {{5, 0}, { 10,10 }, { 0,10 }, { 5, 0 }};
	//hop::Model model(points);
	hop::Model model;
	model.Load("S.txt");

	for (int i = 0; i < 100000; i++) {
		hop::Vexctor2 pos(hop::random(renderer.GetWidth()), hop::random(renderer.GetHeight()));
		hop::Vexctor2 vel(0.0f, hop::randomf(12, 15));

		stars.push_back(Star(pos, vel));
	}

	hop::vec2 position { 400, 300 };
	float speed = 100;

	//Main game loop
	bool quit = false;
	while (!quit)
	{

		hop::g_time.tick();
		inputSystem.Update();
		if (inputSystem.GetKeyDown(SDL_SCANCODE_ESCAPE))
		{
			quit = true;
		}

		hop::vec2 direction;
		if (inputSystem.GetKeyDown(SDL_SCANCODE_W)) direction.y = -1;
		if (inputSystem.GetKeyDown(SDL_SCANCODE_A)) direction.x = -1;
		if (inputSystem.GetKeyDown(SDL_SCANCODE_S)) direction.y = 1;
		if (inputSystem.GetKeyDown(SDL_SCANCODE_D)) direction.x = 1;

		position += direction * speed * hop::g_time.GetDeltaTime();

		if (inputSystem.GetMouseButtonDown(0)) {
			cout << "left mouse pressed" << endl;
		}
		cout << inputSystem.GetMousePosition().x << " " << inputSystem.GetMousePosition().y << endl;

		renderer.SetColor(0, 0, 0, 255); 
		renderer.BeginFrame();
		renderer.SetColor(hop::random(255), hop::random(255), hop::random(255), 255);


		hop::Vexctor2 vel(1.5f, 0.1f);
		model.Draw(renderer, position, 6);


		for (auto& star : stars) {

			star.update(renderer.GetWidth(), renderer.GetHeight());
			r = sqrt(pow(abs(star.m_pos.x - position.x), 2) + pow(abs(star.m_pos.y - position.y), 2));

			if (r > 255) {
				b = 0;
			}
			else {
				b = 255 - r;
			}

			renderer.SetColor(b , b, b, 255);
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

		//this_thread::sleep_for(chrono::milliseconds(100));
	}

	return 0;
}