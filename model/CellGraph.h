#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <map>

#include "ModelEntity.h"
#include "Cell.h"

class CellGraph : public ModelEntity
{
public:
	CellGraph(unsigned int width, unsigned int height);

	void addNode(const Cell &cell);

	void addEdge(Cell::Coord coordNode1, Cell::Coord coordNode2);

	Cell* findNodeByCoord(unsigned int x, unsigned int y);
	Cell* findNodeByCoord(Cell::Coord coord);

	bool areNeighbors(Cell::Coord coordNode1, Cell::Coord coordNode2);

	void updateNeighborhood();

	inline std::vector<Cell*>* getNodeList() { return nodeList; }
	std::map < Cell*, std::vector<Cell*> >* getNeighborhood() { return &neighborhood; }

private:
	void addEdge(Cell *node1, Cell *node2);

	std::vector<Cell*> *nodeList;

	std::map < Cell*, std::vector<Cell*> > neighborhood;

	unsigned int width;
	unsigned int height;
};

#endif // GRAPH_H
