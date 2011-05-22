#include "Application.h"

#include <QTime>

#include "EventManager.h"
#include "MapFileReader.h"
#include "graphics/Image.h"
#include "graphics/GraphDrawer.h"

#include "model/Cell.h"

#include "algo/AStar.h"

Application::Application(int argc, char **argv) :
	QApplication(argc, argv),
	running(true)
{
	ra = new RenderArea(1440, 800);
	graph = 0;

	qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
}

void Application::lockRessources()
{
//	_mutex->lock();
}

void Application::unlockRessources()
{
//	_mutex->unlock();
}

void Application::run()
{
	ra->init();

	EventManager::getInstance()->subscribe(this);

	MapFileReader reader("res/map.txt");
	graph = reader.getGraph();

	graph->updateNeighborhood();

	GraphDrawer drawer(graph, ra);

	Cell::Coord p1, p2;
	p1.x = 0;
	p1.y = 0;
	p2.x = graph->getWidth()-1;
	p2.y = graph->getHeight()-1;
	AStar *astar = new AStar(graph, p1, p2);

	drawer.createEdges();
	drawer.createNodes();

	astar->start();

	while (running)
	{
		EventManager::getInstance()->captureEvent();

		Application::lockRessources();
		ra->display();
		Application::unlockRessources();
	}
}

void Application::onEvent(SDL_Event event)
{
	switch(event.type)
	{
	case SDL_QUIT:
		running = false;
		break;
	default:
		break;
	}
}
