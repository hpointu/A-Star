#include "CellGraph.h"
#include <iostream>
#include <stdlib.h>

CellGraph::CellGraph(unsigned int width, unsigned int height) :
	width(width),
	height(height)
{
	nodeList = new vector<Cell*>();

	cout << "Map loaded : " << width << "," << height << endl;
}

void CellGraph::updateNeighborhood()
{

	for(unsigned int i=0; i<nodeList->size(); i++)
	{
		Cell *cell = nodeList->at(i);
		if(cell->getType() == Cell::EMPTY)
		{
			Cell::Coord cc = cell->getCoord();
			Cell::Coord nc;
			if( (int(cc.x)-1) > -1)
			{
				nc.x = cc.x-1;
				nc.y = cc.y;
				Cell *neighbor = findNodeByCoord(nc);
				if(neighbor->getType() == Cell::EMPTY)
					addEdge(cc, nc);
			}

			if( (cc.x+1) < width)
			{
				nc.x = cc.x+1;
				nc.y = cc.y;
				Cell *neighbor = findNodeByCoord(nc);
				if(neighbor->getType() == Cell::EMPTY)
					addEdge(cc, nc);
			}

			if( (int(cc.y)-1) > -1)
			{
				nc.x = cc.x;
				nc.y = cc.y-1;
				Cell *neighbor = findNodeByCoord(nc);
				if(neighbor->getType() == Cell::EMPTY)
					addEdge(cc, nc);
			}

			if( (cc.y+1) < height)
			{
				nc.x = cc.x;
				nc.y = cc.y+1;
				Cell *neighbor = findNodeByCoord(nc);
				if(neighbor->getType() == Cell::EMPTY)
					addEdge(cc, nc);
			}
		}
	}

}

void CellGraph::addNode(const Cell &cell)
{
	if(!findNodeByCoord(cell.getCoord()))
	{
		Cell *myCell = new Cell(cell.getCoord().x, cell.getCoord().y, cell.getType());
		nodeList->push_back(myCell);

		neighborhood.insert( pair<Cell*,vector<Cell*> >(myCell, vector<Cell*>()) );
	}
}

bool CellGraph::areNeighbors(Cell::Coord coordNode1, Cell::Coord coordNode2)
{
	Cell* node1 = findNodeByCoord(coordNode1);
	Cell* node2 = findNodeByCoord(coordNode2);

	for(unsigned int i=0; i<neighborhood[node1].size(); i++)
	{
		if(neighborhood[node1].at(i) == node2)
		{
			return true;
		}
	}

	return false;
}

void CellGraph::addEdge(Cell *node1, Cell *node2)
{
	if(node1 && node2)
	{
		if(!areNeighbors(node1->getCoord(), node2->getCoord()))
		{
			neighborhood[node1].push_back(node2);
			neighborhood[node2].push_back(node1);

			activeEdgeMat[node1][node2] = false;
			activeEdgeMat[node2][node1] = false;
		}
	}
}

void CellGraph::addEdge(Cell::Coord coordNode1, Cell::Coord coordNode2)
{
	Cell *node1, *node2;

	node1 = findNodeByCoord(coordNode1);
	node2 = findNodeByCoord(coordNode2);

	addEdge(node1, node2);
}

Cell* CellGraph::findNodeByCoord(Cell::Coord coord)
{
	Cell *node = 0;
	for(unsigned int i=0; i<nodeList->size(); i++)
	{
		Cell *currentNode = nodeList->at(i);
		if(currentNode->getCoord().x == coord.x
				&& currentNode->getCoord().y == coord.y)
			node = currentNode;
	}
	return node;
}

Cell* CellGraph::findNodeByCoord(unsigned int x, unsigned int y)
{
	Cell::Coord coord;
	coord.x = x;
	coord.y = y;
	return findNodeByCoord(coord);
}


void CellGraph::activeEdge(Cell::Coord coordNode1, Cell::Coord coordNode2, bool val)
{
	Cell *node1 = findNodeByCoord(coordNode1);
	Cell *node2 = findNodeByCoord(coordNode2);

	activeEdgeMat[node1][node2] = val;
	activeEdgeMat[node2][node1] = val;

	notifyObservers();
}

bool CellGraph::isEdgeActive(Cell::Coord coordNode1, Cell::Coord coordNode2)
{
	Cell *node1 = findNodeByCoord(coordNode1);
	Cell *node2 = findNodeByCoord(coordNode2);

	return activeEdgeMat[node1][node2];
}

// test

void CellGraph::makeActive(bool val)
{
	unsigned int x = 1;
	unsigned int y = 2;

	Cell *winner = findNodeByCoord(x, y);
	winner->setActive(val);

	Cell::Coord c1, c2;
	c1.x = 3;
	c1.y = 3;
	c2 = c1;
	c2.x+=1;

	activeEdge(c1, c2, val);
}


