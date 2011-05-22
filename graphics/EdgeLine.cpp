#include "EdgeLine.h"

EdgeLine::EdgeLine(Cell::Coord p1, Cell::Coord p2, CellGraph *model) :
	Line(p1, p2),
	active(false),
	model(model)
{
	model->addObserver(this);
}

void EdgeLine::draw(SDL_Surface *target)
{
	if(!active)
	{
		r = 150;
		g = 150;
		b = 0;
		a = 255;
	}
	else
	{
		r = 150;
		g = 0;
		b = 150;
		a = 255;
	}

	Line::draw(target);
}


void EdgeLine::update()
{
	setActive(model->isEdgeActive(p1, p2));
}
