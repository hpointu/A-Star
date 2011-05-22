#ifndef GRAPHDRAWER_H
#define GRAPHDRAWER_H

#include "model/CellGraph.h"
#include "graphics/RenderArea.h"

class GraphDrawer
{
public:
	 GraphDrawer(CellGraph *graph, RenderArea *target);

	 void createNodes();

private:
	 CellGraph *graph;
	 unsigned int cellSize;
	 RenderArea *target;
};

#endif // GRAPHDRAWER_H
