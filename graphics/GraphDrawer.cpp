#include "GraphDrawer.h"
#include "model/Cell.h"
#include "graphics/NodeImage.h"
#include "graphics/EdgeLine.h"

#include "graphics/Graphics.h"

GraphDrawer::GraphDrawer(CellGraph *graph, RenderArea *target) :
	graph(graph),
	target(target)
{
}

void GraphDrawer::createNodes()
{
	vector<Cell*>::iterator it;

	for(it = graph->getNodeList()->begin();
		 it < graph->getNodeList()->end();
		 it++ )
	{
		Cell *cell = *it;

		NodeImage *img = new NodeImage(cell);

		Sint16 x = cell->getCoord().x*CELLSIZE + CELLSIZE/2;
		Sint16 y = cell->getCoord().y*CELLSIZE + CELLSIZE/2;
		img->setPosition(x, y);

		target->addDrawable(img);
	}
}

void GraphDrawer::createEdges()
{
	vector<Cell*> added;

	map< Cell*, vector<Cell*> >::iterator it;
	for(it = graph->getNeighborhood()->begin();
		 it != graph->getNeighborhood()->end();
		 it++)
	{
		Cell* node = it->first;
		vector<Cell*> neighbors = it->second;
		vector<Cell*>::iterator nit;
		for(nit = neighbors.begin(); nit < neighbors.end(); nit++)
		{
			Cell* neighbor = (*nit);

			//search in added
			vector<Cell*>::iterator addedIt;
			bool alreadyAdded = false;
			for(addedIt = added.begin(); addedIt < added.end(); addedIt++)
			{
				if((*addedIt) == neighbor)
				{
					alreadyAdded = true;
					addedIt = added.end();
					continue;
				}
			}

			if(!alreadyAdded)   // skip reflexive edges
			{
				EdgeLine *line = new EdgeLine(node->getCoord(), neighbor->getCoord(), graph);
				added.push_back(node);

				target->addDrawable(line);
			}

		}
	}
}
