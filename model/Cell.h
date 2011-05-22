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

	inline void setActive(bool val) {
		active = val;
		notifyObservers();
	}
	inline bool isActive() { return active; }

private:
	Cell::Type type;
	Cell::Coord coord;

	bool active;
};

#endif // CELL_H
