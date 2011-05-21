#include "Application.h"

#include <SDL/SDL.h>

Application::Application()
{
	ra = new RenderArea(800, 600);
}

void Application::run()
{
	ra->init();

	bool running = true;
	SDL_Event event;

	while (running)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
		case SDL_QUIT:
			running = false;
		}
	}
}
