#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <map>

#include "ModelEntity.h"
#include "Cell.h"
#include "Utils.h"

using namespace std;

class CellGraph : public ModelEntity
{

public:
	CellGraph(unsigned int width, unsigned int height);

	void addNode(const Cell &cell);

	void addEdge(Cell::Coord coordNode1, Cell::Coord coordNode2);

	Cell* findNodeByCoord(unsigned int x, unsigned int y);
	Cell* findNodeByCoord(Cell::Coord coord);

	vector<Cell*> getNeighborOf(Cell* node);

	bool areNeighbors(Cell::Coord coordNode1, Cell::Coord coordNode2);

	void updateNeighborhood();

	inline vector<Cell*>* getNodeList() { return nodeList; }

	inline unsigned int getWidth() { return width; }
	inline unsigned int getHeight() { return height; }

	map < Cell*, vector<Cell*> >* getNeighborhood() { return &neighborhood; }

	void markEdge(Cell::Coord coordNode1, Cell::Coord coordNode2, Utils::Marker getMark);
	Utils::Marker getEdgeMark(Cell::Coord coordNode1, Cell::Coord coordNode2);


private:
	void addEdge(Cell *node1, Cell *node2);

	vector<Cell*> *nodeList;

	map < Cell*, vector<Cell*> > neighborhood;

	map < Cell*, map<Cell*, Utils::Marker> > edgeMarkMatrix;

	unsigned int width;
	unsigned int height;
};

#endif // GRAPH_H
