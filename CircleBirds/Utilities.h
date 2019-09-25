#pragma once

//Native Includes
#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <thread>
#include <condition_variable>

//Dependency Includes
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <windows.h>
#include <Box2D/Box2D.h>

const float METER_TO_PIXEL = 100.0f;
const float PIXEL_TO_METER = (1.0f / METER_TO_PIXEL);

extern float DELTA_TIME;


struct Vector2
{
	Vector2() : x(0.0f), y(0.0f) {}
	Vector2(float _x, float _y) : x(_x), y(_y) {	}

	Vector2& operator+=(const Vector2& v) { x += v.x; y += v.y; return *this; }
	Vector2& operator-=(const Vector2& v) { x -= v.x; y -= v.y; return *this; }
	Vector2& operator+=(const float& scalar) { x += scalar; y += scalar; return *this; }
	Vector2& operator-=(const float& scalar) { x -= scalar; y -= scalar; return *this; }

	friend Vector2 operator+(const Vector2& lhs, const Vector2& rhs) { return Vector2(lhs) += rhs; }
	friend Vector2 operator-(const Vector2& lhs, const Vector2& rhs) { return Vector2(lhs) -= rhs; }

	float x, y;
};
