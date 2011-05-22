#ifndef LINE_H
#define LINE_H

#include "Drawable.h"
#include "model/Cell.h"
#include "SDL/SDL_gfxPrimitives.h"


class Line : public Drawable
{
public:
	Line(Cell::Coord p1, Cell::Coord p2);

	virtual void draw(SDL_Surface *target);

	void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

protected:
	Cell::Coord p1;
	Cell::Coord p2;
	Uint8 r,g,b,a;
};

#endif // LINE_H
