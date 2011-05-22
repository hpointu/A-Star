#ifndef ASTAR_H
#define ASTAR_H

#include "Algo.h"
#include "model/CellGraph.h"
#include "model/Cell.h"

#include <QList>


using namespace std;

class AStar : public Algo
{

public:
	AStar(CellGraph *graph, Cell::Coord startPoint, Cell::Coord endPoint);

	virtual void process();

private:

	class _Point
	{
	public:
		_Point(_Point *parent, unsigned int cost, Cell *node) :
			parent(parent), cost(cost), node(node)
		{

		}
		_Point *parent;
		unsigned int cost;
		Cell *node;
	};

	Cell::Coord startPoint, endPoint;

	QList<_Point*> blues;
	QList<_Point*> reds;

	AStar::_Point* getCheaper(QList<_Point*> list, int &id);

	bool inList(QList<_Point*> list, _Point *p);

};

#endif // ASTAR_H
