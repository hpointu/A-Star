#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Algo.h"
#include "model/CellGraph.h"
#include "model/Cell.h"

#include <QList>


using namespace std;

class Dijkstra : public Algo
{
public:
	Dijkstra(CellGraph *graph, Cell::Coord startPoint, Cell::Coord endPoint);

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

	Dijkstra::_Point* getCheaper(QList<_Point*> list, int &id);

	bool inList(QList<_Point*> list, _Point *p);
};

#endif // DIJKSTRA_H
