#include "Core/Random.h"
#include "Core/FileIO.h"
#include "Core/Memory.h"
#include "Core/Time.h"
#include "Renderer/Renderer.h"
#include <iostream>
#include <chrono>

using namespace std;

int main()	
{
	hop::g_memoryTracker.DisplayInfo();
	int* p = new int;
	hop::g_memoryTracker.DisplayInfo();
	delete p;
	hop::g_memoryTracker.DisplayInfo();

	hop::Time timer;
	for (int i = 0; i < 1000000; i++) {
		for (int i = 0; i < 1000000; i++) {}
	}
	cout << timer.GetElapsedSeconds() << endl;

	//auto start = std::chrono::high_resolution_clock::now();
	//for (int i = 0; i < 2147483647; i++) {}
	//auto end = std::chrono::high_resolution_clock::now();

	//cout << std:: chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << endl;

	//cout << hop::getFilePath() << endl;
	//hop::setFilePath("Assets");
	//cout << hop::getFilePath() << endl;
	//size_t size;
	//hop::getFileSize("game.txt", size);
	//cout << size << endl;

	//std::string s;
	//hop::readFile("game.txt", s);
	//cout << s << endl;

	//hop::seedRandom((unsigned int)time(nullptr));
	//for (int i = 0; i < 3; i++) {
	//	cout << hop::random(10, 20) << endl;
	//}
}