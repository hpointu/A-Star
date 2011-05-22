#include "GraphDrawer.h"
#include "model/Cell.h"
#include "graphics/Image.h"
#include <vector>

GraphDrawer::GraphDrawer(CellGraph *graph, RenderArea *target) :
	graph(graph),
	target(target)
{
	cellSize = 50;
}

void GraphDrawer::createNodes()
{
	std::vector<Cell*> *list = graph->getNodeList();

	for(unsigned int i=0; i<list->size(); i++)
	{
		Cell *cell = list->at(i);

		Image *img = new Image("res/node.png");

		Sint16 x = cell->getCoord().x*cellSize + cellSize/2;
		Sint16 y = cell->getCoord().y*cellSize + cellSize/2;
		img->setPosition(x, y);

		target->addDrawable(img);
	}
}
