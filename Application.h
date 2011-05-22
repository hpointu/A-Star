#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>

#include <SDL/SDL.h>
#include <QMutex>

#include "graphics/RenderArea.h"
#include "EventListener.h"
#include "model/CellGraph.h"


class Application : public QApplication, public EventListener
{
public:
	Application(int argc, char **argv);

	void run();

	void onEvent(SDL_Event event);

	static void lockRessources();
	static void unlockRessources();

private:
	RenderArea *ra;
	bool running;

	CellGraph *graph;

};



#endif // APPLICATION_H
