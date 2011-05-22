#include "CellGraph.h"
#include <iostream>
#include <stdlib.h>
#include <QtGlobal>

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


			// TEST

//			if( (int(cc.x)-1) > -1 && (int(cc.y)-1) > -1)
//			{
//				nc.x = cc.x-1;
//				nc.y = cc.y-1;
//				Cell *neighbor = findNodeByCoord(nc);
//				if(neighbor->getType() == Cell::EMPTY)
//					addEdge(cc, nc);
//			}
//			if( (int(cc.x)-1) > -1 && (int(cc.y)+1) < height)
//			{
//				nc.x = cc.x-1;
//				nc.y = cc.y+1;
//				Cell *neighbor = findNodeByCoord(nc);
//				if(neighbor->getType() == Cell::EMPTY)
//					addEdge(cc, nc);
//			}
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

			edgeMarkMatrix[node1][node2] = Utils::NEUTRAL;
			edgeMarkMatrix[node2][node1] = Utils::NEUTRAL;
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

vector<Cell*> CellGraph::getNeighborOf(Cell *node)
{
	vector<Cell*> result;
	if(node != 0)
	{
		vector<Cell*> list = neighborhood[node];
		for(unsigned int i=0; i<list.size(); i++)
		{
			result.push_back(list.at(i));
		}
	}
	return result;
}

Cell* CellGraph::findNodeByCoord(unsigned int x, unsigned int y)
{
	Cell::Coord coord;
	coord.x = x;
	coord.y = y;
	return findNodeByCoord(coord);
}


void CellGraph::markEdge(Cell::Coord coordNode1, Cell::Coord coordNode2, Utils::Marker mark)
{
	Cell *node1 = findNodeByCoord(coordNode1);
	Cell *node2 = findNodeByCoord(coordNode2);

	edgeMarkMatrix[node1][node2] = mark;
	edgeMarkMatrix[node2][node1] = mark;

	notifyObservers();
}

Utils::Marker CellGraph::getEdgeMark(Cell::Coord coordNode1, Cell::Coord coordNode2)
{
	Cell *node1 = findNodeByCoord(coordNode1);
	Cell *node2 = findNodeByCoord(coordNode2);

	return edgeMarkMatrix[node1][node2];
}



