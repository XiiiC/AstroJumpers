#pragma once
#include "SDL.h"
class Sprite
{
public:
	Sprite(int x, int y, int widthPixels, int heightPixels);
	~Sprite();
	
	void Update(int ticks);
	void Render(SDL_Renderer* renderer);
	void Load(SDL_Renderer* renderer, const char* path, bool bUseColourKey = false);
	void SetNumOfFrames(unsigned int framecount);
	void SetAnimationSpeed(unsigned int speed);

	// x and y position of the sprite in screen space
	int x, y = 0;
	// width and height of the sprite within the source texture
	int frameWidthPixels, frameHeightPixels = 0;
	// scale the destination sprite during rendering
	int xScale, yScale = 1;

protected:
	SDL_Texture* texture = nullptr;	// pointer to an SDL_Texture, always initialize your pointers to either NULL or nullptr
	SDL_Rect srcRect;					// this is the source rectangle where we will copy the sprite from within the texture

	unsigned int numberOfFrames = 1;	// num of frames of animation
	unsigned int animationSpeed = 100;	// milliseconds between each frame of animation
	unsigned int frameIndex = 0;		// frame are we currently on
};

