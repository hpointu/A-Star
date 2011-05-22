#ifndef APPLICATION_H
#define APPLICATION_H

#include <SDL/SDL.h>

#include "graphics/RenderArea.h"
#include "EventListener.h"
#include "model/CellGraph.h"


class Application : public EventListener
{
public:
    Application();

	 void run();

	 void onEvent(SDL_Event event);

private:
	 RenderArea *ra;
	 bool running;

	 CellGraph *graph;
};

#endif // APPLICATION_H
