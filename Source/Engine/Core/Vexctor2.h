#pragma once
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
	};

	using vec2 = Vexctor2;
}