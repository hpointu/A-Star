#include "Line.h"
#include "graphics/Graphics.h"

Line::Line(Cell::Coord p1, Cell::Coord p2) :
	p1(p1),
	p2(p2)
{
	r = 255;
	g = 255;
	b = 255;
	a = 255;
}

void Line::draw(SDL_Surface *target)
{
	lineRGBA(target,
				p1.x*CELLSIZE + CELLSIZE/2 + 8, p1.y*CELLSIZE + CELLSIZE/2 + 8,
				p2.x*CELLSIZE + CELLSIZE/2 + 8, p2.y*CELLSIZE + CELLSIZE/2 + 8,
				r,g,b,a);
}


void Line::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}
