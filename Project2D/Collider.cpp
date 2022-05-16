#include "Collider.h"


bool AABB::CheckCollision(SDL_Rect a, SDL_Rect b)
{
	//all sides of the two rectangles
	int leftA, leftB, rightA, rightB, topA, topB, bottomA, bottomB;

	//assigns the values of the rectangles

	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	rightB = b.x;
	leftB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	if (bottomA <= topB)
		return false;
	if (topA >= bottomB)
		return false;
	if (rightA <= leftB)
		return false;
	if (leftA >= rightB)
		return false;

	return true;
}