#include "Application.h"
#include "EventManager.h"

Application::Application() :
	running(true)
{
	ra = new RenderArea(800, 600);
}

void Application::run()
{
	ra->init();

	EventManager::getInstance()->subscribe(this);

	while (running)
	{
		EventManager::getInstance()->captureEvent();
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
