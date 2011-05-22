#include "Line.h"
#include "SDL/SDL_gfxPrimitives.h"
#include "graphics/Graphics.h"

Line::Line(Cell::Coord p1, Cell::Coord p2) :
	p1(p1),
	p2(p2)
{

}

void Line::draw(SDL_Surface *target)
{
	lineRGBA(target,
				p1.x*CELLSIZE + CELLSIZE/2 + 8, p1.y*CELLSIZE + CELLSIZE/2 + 8,
				p2.x*CELLSIZE + CELLSIZE/2 + 8, p2.y*CELLSIZE + CELLSIZE/2 + 8,
				150, 150, 0, 200);
}
