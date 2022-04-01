#pragma once
#include "Vector2D.h"

Vector2D::Vector2D()
{

}

Vector2D::Vector2D(int eX, int eY)
{
	x = sqrt(eX*eX);
	y = sqrt(eY*eY);
}
