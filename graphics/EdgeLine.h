#ifndef EDGELINE_H
#define EDGELINE_H

#include "Line.h"
#include "model/Cell.h"
#include "model/CellGraph.h"
#include "model/ModelObserver.h"

class EdgeLine : public Line, public ModelObserver
{
public:
	 EdgeLine(Cell::Coord p1, Cell::Coord p2, CellGraph *model);

	 void draw(SDL_Surface *target);
	 inline void setActive(bool val) { active = val; }

	 void update();

private:
	 bool active;

	 CellGraph *model;

};

#endif // EDGELINE_H
