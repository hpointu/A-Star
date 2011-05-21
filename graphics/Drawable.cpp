#include "Drawable.h"
#include <SDL/SDL_rotozoom.h>

void Drawable::setPosition(Sint16 x, Sint16 y)
{
	this->x = x;
	this->y = y;
}

void Drawable::draw(SDL_Surface *target)
{
	if(surface)
	{
		SDL_Rect position;
		position.x = x;
		position.y = y;

		SDL_Surface *tmp = rotozoomSurface(surface, rot, 1.0, 0);
		SDL_BlitSurface(tmp, NULL, target, &position);
	}
}

void Drawable::setRotation(int degree)
{
	this->rot = degree;
}
