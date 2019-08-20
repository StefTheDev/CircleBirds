#include "Vector2.h"

Vector2::Vector2(): x(0), y(0)
{

}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::~Vector2()
{
}

float Vector2::GetX() const
{
	return x;
}

float Vector2::GetY() const
{
	return y;
}
