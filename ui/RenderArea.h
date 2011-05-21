#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <SDL/SDL.h>
#include <vector>

#include "ui/Drawable.h"

class RenderArea
{
public:
	RenderArea(unsigned int width, unsigned int height);
	~RenderArea();

	void init();

	void display();

private:
	SDL_Surface *window;

	unsigned int width;
	unsigned int height;

	std::vector<Drawable*> *drawables;
};

#endif // RENDERAREA_H
