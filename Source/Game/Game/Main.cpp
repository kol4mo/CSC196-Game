#include "Core/Random.h"
#include "Core/FileIO.h"
#include "Core/Memory.h"
#include <iostream>

using namespace std;

int main()	
{
	int* p = new int;
	delete p;

	cout << hop::getFilePath() << endl;
	hop::setFilePath("Assets");
	cout << hop::getFilePath() << endl;
	size_t size;
	hop::getFileSize("game.txt", size);
	cout << size << endl;

	std::string s;
	hop::readFile("game.txt", s);
	cout << s << endl;

	hop::seedRandom((unsigned int)time(nullptr));
	for (int i = 0; i < 3; i++) {
		cout << hop::random(10, 20) << endl;
	}
}