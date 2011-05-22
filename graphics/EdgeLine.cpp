#include "EdgeLine.h"

EdgeLine::EdgeLine(Cell::Coord p1, Cell::Coord p2, CellGraph *model) :
	Line(p1, p2),
	model(model)
{
	model->addObserver(this);
	this->mark = Utils::NEUTRAL;
}

void EdgeLine::draw(SDL_Surface *target)
{
	if(mark == Utils::PINED)
	{
		r = 150;
		g = 0;
		b = 150;
		a = 255;
	}
	else if (mark == Utils::ACTIVE)
	{
		r = 0;
		g = 150;
		b = 0;
		a = 255;
	}
	else
	{
		r = 255;
		g = 255;
		b = 255;
		a = 100;
	}

	Line::draw(target);
}


void EdgeLine::update()
{
	mark = model->getEdgeMark(p1, p2);
}
