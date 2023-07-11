#pragma once
#include <cmath>
#include <sstream>

namespace hop
{
	class Vexctor2
	{
	public:
		float x, y;
	
	public:
		Vexctor2() : x{ 0 }, y{ 0 } {}
		Vexctor2(float v) : x{ v }, y{ v } {}
		Vexctor2(float x, float y) : x{ x }, y{ y } {}
		Vexctor2(int x, int y) : x{ (float)x }, y{ (float)y } {}

		Vexctor2 operator + (const Vexctor2& v) const { return Vexctor2(x + v.x, y + v.y); }
		Vexctor2 operator - (const Vexctor2& v) const { return Vexctor2(x - v.x, y - v.y); }
		Vexctor2 operator / (const Vexctor2& v) const { return Vexctor2(x / v.x, y / v.y); }
		Vexctor2 operator * (const Vexctor2& v) const { return Vexctor2(x * v.x, y * v.y); }

		Vexctor2 operator + (float s) const { return Vexctor2(x + s, y + s); }
		Vexctor2 operator - (float s) const { return Vexctor2(x - s, y - s); }
		Vexctor2 operator / (float s) const { return Vexctor2(x / s, y / s); }
		Vexctor2 operator * (float s) const { return Vexctor2(x * s, y * s); }

		Vexctor2& operator += (const Vexctor2& v) { x += v.x; y += v.y; return *this; }
		Vexctor2& operator -= (const Vexctor2& v) { x -= v.x; y -= v.y; return *this; }
		Vexctor2& operator /= (const Vexctor2& v) { x /= v.x; y /= v.y; return *this; }
		Vexctor2& operator *= (const Vexctor2& v) { x *= v.x; y *= v.y; return *this; }


		float lengthSqr() { return (x * x) + (y * y); }
		float length() { return sqrt(lengthSqr()); }

		Vexctor2 Normalized() { return *this / length();}
		void Normalize() { *this /= length(); }
	};

	inline std::istream& operator >> (std::istream& stream, Vexctor2& v)
	{
		std::string line;
		std::getline(stream, line);

		// { ##, ## }
		std::string xs = line.substr(line.find("{") + 1, line.find(",") - (line.find("{") + 1));
		v.x = std::stof(xs);

		std::string ys = line.substr(line.find(",") + 1, line.find("}") - (line.find(",") + 1));
		v.y = std::stof(ys);

		return stream;
	}

	using vec2 = Vexctor2;
}