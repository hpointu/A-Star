#include "Application.h"

#include <stdlib.h>

#include "EventManager.h"
#include "MapFileReader.h"
#include "graphics/Image.h"
#include "graphics/GraphDrawer.h"

Application::Application() :
	running(true)
{
	ra = new RenderArea(800, 600);
	graph = 0;

	srand(time(0));
}

void Application::run()
{
	ra->init();

	EventManager::getInstance()->subscribe(this);

	MapFileReader reader("res/map.txt");
	graph = reader.getGraph();

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
		break;
	case SDL_KEYDOWN:
		graph->makeActive(true);
		break;
	case SDL_KEYUP:
		graph->makeActive(false);
		break;

	default:
		break;
	}
}
