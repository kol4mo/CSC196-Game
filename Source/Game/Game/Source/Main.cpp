#include "Core/core.h"
#include "Renderer/Renderer.h"
#include "Renderer/Model.h"
#include "Input/InputSystem.h"
#include "Enemy.h"
#include "Audio/AudioSystem.h"
#include "Player.h"	
#include "Framework/Scene.h"

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

	void update(float width, float height)
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

	//vector<Star> stars;
	//int r;
	//int g;
	//int b;
	//int d;
	//int o;

	hop::g_renderer.Initialize();
	hop::g_renderer.CreateWindow("CSC196", 1080, 540);
	hop::g_audioSystem.Initialize();
	hop::g_inputSystem.Initialize();
	hop::g_audioSystem.AddAudio("explode", "explode.wav");

	//std::vector<hop::vec2> points {{5, 0}, { 10,10 }, { 0,10 }, { 5, 0 }};
	hop::Model model;
	//hop::Model model({ {0, 0}, { 0,-1 } });
	model.Load("S.txt");

	//for (int i = 0; i < 10000; i++) {
	//	hop::Vexctor2 pos(hop::random(hop::g_renderer.GetWidth()), hop::random(hop::g_renderer.GetHeight()));
	//	hop::Vexctor2 vel(0.0f, hop::randomf(12, 15));

	//	stars.push_back(Star(pos, vel));
	//}

	hop::Scene scene;

	scene.Add(new Player{ 100, hop::PI, {{400, 300}, 0, 20}, model });

	std::vector<Enemy> enemies;
	for (int i = 0; i < 10; i++) {
		scene.Add(new Enemy{ 200, hop::PI, {{hop::random(hop::g_renderer.GetWidth()), hop::random(hop::g_renderer.GetHeight())}, hop::randomf(hop::TwoPi), 3}, model });
	}
	//Main game loop
	bool quit = false;
	while (!quit)
	{



		hop::g_time.tick();
		hop::g_inputSystem.Update();
		hop::g_audioSystem.Update();
		if (hop::g_inputSystem.GetKeyDown(SDL_SCANCODE_ESCAPE))
		{
			quit = true;
		}
		if (hop::g_inputSystem.GetKeyDown(SDL_SCANCODE_SPACE) && !hop::g_inputSystem.GetPreviousKeyDown(SDL_SCANCODE_SPACE))
		{
			hop::g_audioSystem.PlayOneShot("explode");
		}

		scene.Update(hop::g_time.GetDeltaTime());
		
		/*hop::vec2 direction;
		if (inputSystem.GetKeyDown(SDL_SCANCODE_W)) direction.y = -1;
		if (inputSystem.GetKeyDown(SDL_SCANCODE_A)) direction.x = -1;
		if (inputSystem.GetKeyDown(SDL_SCANCODE_S)) direction.y = 1;
		if (inputSystem.GetKeyDown(SDL_SCANCODE_D)) direction.x = 1;

		transform.position += direction * speed * hop::g_time.GetDeltaTime();*/

		if (hop::g_inputSystem.GetMouseButtonDown(0)) {
			cout << "left mouse pressed" << endl;
		}
		cout << hop::g_inputSystem.GetMousePosition().x << " " << hop::g_inputSystem.GetMousePosition().y << endl;

		hop::g_renderer.SetColor(0, 0, 0, 255);
		hop::g_renderer.BeginFrame();


		hop::Vexctor2 vel(1.5f, 0.1f);


		/*for (auto& star : stars) {

			star.update(hop::g_renderer.GetWidth(), hop::g_renderer.GetHeight());
			d = sqrt(pow(abs(star.m_pos.x - player.m_transform.position.x), 2) + pow(abs(star.m_pos.y - player.m_transform.position.y), 2));
			r = hop::random(255);
			b = hop::random(255);
			g= hop::random(255);
			
			if (r - d < 0) {
				r = 0;
			}
			else {
				r - d;
			}
			if (b - d < 0) {
				b= 0;
			}
			else {
				b- d;
			}
			if (g - d < 0) {
				g = 0;
			}
			else {
				g - d;
			}
			if (d < 0) {
				o = 0;
			}
			else {
				o = (100 - d) * 2.55f;
			}

			hop::g_renderer.SetColor(o,o,o, 255);
			star.Draw(hop::g_renderer);
		}*/

		hop::g_renderer.SetColor(hop::random(255), hop::random(255), hop::random(255), 255);
		scene.Draw(hop::g_renderer);
		//draw
		//for (int i = 0; i < 1000; i++) {
		//	hop::Vexctor2 pos(hop::randomf(renderer.GetWidth()), hop::randomf(renderer.GetHeight()));
		//	renderer.SetColor(hop::random(255), hop::random(255), hop::random(255), hop::random(255));
		//	renderer.DrawPoint(pos.x, pos.y);
		//	//renderer.DrawLine(hop::random(renderer.GetWidth()), hop::random(renderer.GetHeight()), hop::random(renderer.GetWidth()), hop::random(renderer.GetHeight()));
		//}
		hop::g_renderer.EndFrame();

		//this_thread::sleep_for(chrono::milliseconds(100));
	}

	return 0;
}