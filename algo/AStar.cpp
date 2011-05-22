#include "AStar.h"

#include <iostream>

AStar::AStar(CellGraph *graph, Cell::Coord startPoint, Cell::Coord endPoint) :
	Algo(graph),
	startPoint(startPoint),
	endPoint(endPoint)
{
}

void AStar::process()
{
	// initialisation du point de départ
	_Point *p0 = new _Point(0, 0, graph->findNodeByCoord(startPoint));
	_Point *pAlpha = new _Point(0, 0, graph->findNodeByCoord(endPoint));


	blues.append(p0);
	bool found = false;
	// tant qu'on a un bleu (node à déployer)
	while(!blues.isEmpty() && !found)
	{
		int toDeployId;
		_Point *toDeploy = getCheaper(blues, toDeployId);
		// on déploie
		vector<Cell*> neighbors = graph->getNeighborOf(toDeploy->node);
		vector<Cell*>::iterator _it;
		for(_it = neighbors.begin(); _it < neighbors.end(); _it++)
		{
			_Point *p = new _Point(toDeploy, 1+toDeploy->cost, *_it);
			if(!inList(blues, p) && !inList(reds, p))
			{
				blues.append(p);
				graph->markEdge(p->node->getCoord(), toDeploy->node->getCoord(), Utils::ACTIVE);
			}
			if((*_it)->getCoord().x == endPoint.x && (*_it)->getCoord().y == endPoint.y )
			{
				found = true;
			}
		}
		// on le marque rouge (déjà déployé)
		reds.append(toDeploy);

		// on le vire des bleus
		blues.removeAt(toDeployId);

		// just mark graphically

		for(int i=0; i<blues.size(); i++)
		{
			blues.at(i)->node->mark(Utils::MARKED);
		}
		toDeploy->node->mark(Utils::ACTIVE);
		msleep(10);
		toDeploy->node->mark(Utils::NEUTRAL);
		p0->node->mark(Utils::START);
		pAlpha->node->mark(Utils::END);
	}

	// blues.last() holds the good way by its parent's parent's parent's etc
//	blues.last()->node->mark(Utils::PINED);
	if(!blues.isEmpty())
	{
		_Point *_p = blues.last();
		while(_p->parent != 0)
		{
			_p->node->mark(Utils::PINED);
			graph->markEdge(_p->node->getCoord(), _p->parent->node->getCoord(), Utils::PINED);
			_p = _p->parent;
		}
		p0->node->mark(Utils::START);
		pAlpha->node->mark(Utils::END);
	}
}

AStar::_Point* AStar::getCheaper(QList<_Point *> list, int &id)
{
	int i = 0;
	_Point *cheaper = list.first();
	int tmpId = 0;
	while(i<list.size())
	{
		if(list.at(i)->cost <= cheaper->cost)
		{
			tmpId = i;
			cheaper = list.at(i);
		}
		i++;
	}
	id = tmpId;
	return cheaper;
}

// check by coords
bool AStar::inList(QList<_Point *> list, _Point *p)
{
	for(int i=0; i<list.size(); i++)
	{
		_Point *current = list.at(i);
		if( current->node->getCoord().x == p->node->getCoord().x
			 && current->node->getCoord().y == p->node->getCoord().y )
		{
			return true;
		}
	}
	return false;
}
