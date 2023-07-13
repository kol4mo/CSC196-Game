#pragma once
#include <cmath>

namespace hop
{
	constexpr float PI = 3.14159265359f;
	constexpr float TwoPi = PI * 2;
	constexpr float halfPi = PI / 2;

	constexpr float RadToDeg(float radians) { return radians * 180.0f / PI; }
	constexpr float DegToRad(float degrees) { return degrees * PI / 180.0f; }

	constexpr int Wrap(int value, int max) { return (value % max) + ((value < 0) ? max : 0); }
}