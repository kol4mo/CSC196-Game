#pragma once
#include <random>

namespace hop
{
	void seedRandom(unsigned int seed) { srand(seed); }
	int random() { return rand();}
	int random(unsigned int max) { return rand() % max; }
	int random(unsigned int min, unsigned int max) { return min + random((max - min) + 1); }

	float randomf() { return (float)random() / RAND_MAX; }
	float randomf(float max) { return randomf() * max; }
	float randomf(float min, float max) { return (min + randomf()) * (max-min); }
}