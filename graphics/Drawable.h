#ifndef IDRAWABLE_H
#define IDRAWABLE_H

#include <SDL/SDL.h>

class Drawable
{
public:
	virtual void draw(SDL_Surface *target);
	virtual void setPosition(Sint16 x, Sint16 y);

	virtual void setRotation(int degree);

private:
	Sint16 x;
	Sint16 y;

	int rot;

protected:
	SDL_Surface *surface;
};

#endif // IDRAWABLE_H
