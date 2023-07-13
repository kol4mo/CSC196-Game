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
	constexpr float a = hop::DegToRad(180.0f);

	hop::seedRandom((unsigned int)time(nullptr));
	hop::setFilePath("Assets");

	vector<Star> stars;
	int r;
	int g;
	int b;
	int d;
	int o;

	hop::Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("CSC196", 1080, 540);

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

	hop::Transform transform{ {400, 300}, 0, 3};
	float turnrate = hop::DegToRad(180);
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

		float rotate = 0;
		if (inputSystem.GetKeyDown(SDL_SCANCODE_A)) rotate = -1;
		if (inputSystem.GetKeyDown(SDL_SCANCODE_D)) rotate = 1;
		transform.rotation += rotate * turnrate * hop::g_time.GetDeltaTime();

		float thrust = 0;
		if (inputSystem.GetKeyDown(SDL_SCANCODE_W)) thrust = 1;

		hop::vec2 forward = hop::vec2{ 0, -1 }.Rotate(transform.rotation);
		transform.position += forward * speed * thrust * hop::g_time.GetDeltaTime();
		transform.position.x = hop::Wrap(transform.position.x, renderer.GetWidth());
		transform.position.y = hop::Wrap(transform.position.y, renderer.GetHeight());

		/*hop::vec2 direction;
		if (inputSystem.GetKeyDown(SDL_SCANCODE_W)) direction.y = -1;
		if (inputSystem.GetKeyDown(SDL_SCANCODE_A)) direction.x = -1;
		if (inputSystem.GetKeyDown(SDL_SCANCODE_S)) direction.y = 1;
		if (inputSystem.GetKeyDown(SDL_SCANCODE_D)) direction.x = 1;

		transform.position += direction * speed * hop::g_time.GetDeltaTime();*/

		if (inputSystem.GetMouseButtonDown(0)) {
			cout << "left mouse pressed" << endl;
		}
		cout << inputSystem.GetMousePosition().x << " " << inputSystem.GetMousePosition().y << endl;

		renderer.SetColor(0, 0, 0, 255); 
		renderer.BeginFrame();
		renderer.SetColor(hop::random(255), hop::random(255), hop::random(255), 255);


		hop::Vexctor2 vel(1.5f, 0.1f);
		model.Draw(renderer, transform.position,transform.rotation, transform.scale);


		for (auto& star : stars) {

			star.update(renderer.GetWidth(), renderer.GetHeight());
			d = sqrt(pow(abs(star.m_pos.x - transform.position.x), 2) + pow(abs(star.m_pos.y - transform.position.y), 2));
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

			renderer.SetColor(o,o,o, 255);
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