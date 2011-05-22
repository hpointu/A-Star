#include "Cell.h"

Cell::Cell(unsigned int x, unsigned int y, Cell::Type type)
{
	coord.x = x;
	coord.y = y;

	type = type;
}

Cell::Type Cell::getType() const
{
	return type;
}

Cell::Coord Cell::getCoord() const
{
	return coord;
}
