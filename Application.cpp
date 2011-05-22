#include "Application.h"
#include "EventManager.h"
#include "graphics/Image.h"

#include "MapFileReader.h"

#include "model/CellGraph.h"
#include "graphics/GraphDrawer.h"

Application::Application() :
	running(true)
{
	ra = new RenderArea(800, 600);
}

void Application::run()
{
	ra->init();

	EventManager::getInstance()->subscribe(this);

	MapFileReader reader("res/map.txt");
	CellGraph *graph = reader.getGraph();

	graph->updateNeighborhood();

	GraphDrawer drawer(graph, ra);

	drawer.createEdges();
	drawer.createNodes();


	while (running)
	{
		EventManager::getInstance()->captureEvent();
		ra->display();

	}
}

void Application::onEvent(SDL_Event event)
{
	switch(event.type)
	{
	case SDL_QUIT:
		running = false;
	}
}
