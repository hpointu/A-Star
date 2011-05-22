#include "Cell.h"

Cell::Cell(unsigned int x, unsigned int y, Cell::Type type)
{
	this->coord.x = x;
	this->coord.y = y;

	this->type = type;
	this->active = false;
}

Cell::Type Cell::getType() const
{
	return type;
}

Cell::Coord Cell::getCoord() const
{
	return coord;
}
