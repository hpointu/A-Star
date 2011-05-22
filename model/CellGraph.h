#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <map>

#include "ModelEntity.h"
#include "Cell.h"

using namespace std;

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

	inline vector<Cell*>* getNodeList() { return nodeList; }
	map < Cell*, vector<Cell*> >* getNeighborhood() { return &neighborhood; }

	void activeEdge(Cell::Coord coordNode1, Cell::Coord coordNode2, bool val = true);
	bool isEdgeActive(Cell::Coord coordNode1, Cell::Coord coordNode2);

	//test
	void makeActive(bool val);

private:
	void addEdge(Cell *node1, Cell *node2);

	vector<Cell*> *nodeList;

	map < Cell*, vector<Cell*> > neighborhood;

	map < Cell*, map<Cell*, bool> > activeEdgeMat;

	unsigned int width;
	unsigned int height;
};

#endif // GRAPH_H
