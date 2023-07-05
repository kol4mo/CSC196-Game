#include "Core/Random.h"
#include "Core/FileIO.h"
#include "Core/Memory.h"
#include "Core/Time.h"
#include "Renderer/Renderer.h"
#include <iostream>
#include <chrono>

using namespace std;

int main(int argc, char* argv[])
{
	hop::Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("CSC196", 800, 600);

	while (true)
	{
		renderer.SetColor(0, 0, 0, 255);
		renderer.BeginFrame();
		//draw
		for (int i = 0; 1 < 10000; i++) {
			renderer.SetColor(hop::random(256), hop::random(256), hop::random(256), hop::random(256));
			renderer.DrawPoint(hop::random(renderer.GetWidth()), hop::random(renderer.GetHeight()));
		}
		renderer.EndFrame();
	}

	return 0;
}