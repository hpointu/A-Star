#ifndef CELL_H
#define CELL_H

#include "ModelEntity.h"

class Cell : public ModelEntity
{
public:
	enum Type
	{
		EMPTY,
		WALL
	};

	typedef struct
	{
		unsigned int x;
		unsigned int y;
	} Coord;

	Cell(unsigned int x, unsigned int y, Cell::Type type);

	Cell::Type getType() const;
	Cell::Coord getCoord() const;

private:
	Cell::Type type;
	Cell::Coord coord;

};

#endif // CELL_H
