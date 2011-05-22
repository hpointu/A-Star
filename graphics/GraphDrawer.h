#ifndef GRAPHDRAWER_H
#define GRAPHDRAWER_H


#include <vector>
#include <map>

#include "model/CellGraph.h"
#include "graphics/RenderArea.h"

using namespace std;

class GraphDrawer
{
public:
	GraphDrawer(CellGraph *graph, RenderArea *target);

	void createNodes();

	void createEdges();

private:
	CellGraph *graph;
	unsigned int cellSize;
	RenderArea *target;
};

#endif // GRAPHDRAWER_H
