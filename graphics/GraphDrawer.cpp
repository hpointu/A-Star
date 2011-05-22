#include "GraphDrawer.h"
#include "model/Cell.h"
#include "graphics/Image.h"
#include "SDL/SDL_gfxPrimitives.h"

GraphDrawer::GraphDrawer(CellGraph *graph, RenderArea *target) :
	graph(graph),
	target(target)
{
	cellSize = 50;
}

void GraphDrawer::createNodes()
{
	vector<Cell*>::iterator it;

	for(it = graph->getNodeList()->begin();
		 it < graph->getNodeList()->end();
		 it++ )
	{
		Cell *cell = *it;

		Image *img = new Image("res/node.png");

		Sint16 x = cell->getCoord().x*cellSize + cellSize/2;
		Sint16 y = cell->getCoord().y*cellSize + cellSize/2;
		img->setPosition(x, y);

		target->addDrawable(img);
	}
}

void GraphDrawer::createEdges()
{
	map< Cell*, vector<Cell*> >::iterator it;
}
