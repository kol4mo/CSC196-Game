#include "Core/Random.h"
#include "Core/FileIO.h"
#include <iostream>

using namespace std;

int main()
{
	cout << hop::getFilePath() << endl;


	hop::seedRandom((unsigned int)time(nullptr));
	for (int i = 0; i < 3; i++) {
		cout << hop::random(10, 20) << endl;
	}
}