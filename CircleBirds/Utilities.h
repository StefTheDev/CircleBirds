#pragma once

//Native Includes
#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>

//Dependency Includes
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <windows.h>


struct Vector2
{
	Vector2() {}
	Vector2(float _x, float _y) : x(_x), y(_y) {	}

	Vector2& operator+=(const Vector2& v) { x += v.x; y += v.y; return *this; }
	Vector2& operator-=(const Vector2& v) { x -= v.x; y -= v.y; return *this; }

	friend Vector2 operator+(const Vector2& lhs, const Vector2& rhs) { return Vector2(lhs) += rhs; }
	friend Vector2 operator-(const Vector2& lhs, const Vector2& rhs) { return Vector2(lhs) -= rhs; }

	float x, y;
};
