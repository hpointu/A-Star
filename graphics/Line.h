#ifndef LINE_H
#define LINE_H

#include "Drawable.h"
#include "model/Cell.h"

class Line : public Drawable
{
public:
	 Line(Cell::Coord p1, Cell::Coord p2);

	 void draw(SDL_Surface *target);

private:
	 Cell::Coord p1;
	 Cell::Coord p2;
};

#endif // LINE_H
