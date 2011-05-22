#include "EventManager.h"

EventManager::EventManager()
{
	listeners = new std::vector<EventListener*>();
}

void EventManager::captureEvent()
{
	SDL_Event event;
	SDL_WaitEvent(&event);
	forward(event);
}

void EventManager::subscribe(EventListener *subscriber)
{
	listeners->push_back(subscriber);
}

void EventManager::forward(SDL_Event event)
{
	std::vector<EventListener*>::iterator it;
	for(it = listeners->begin();
		 it < listeners->end();
		 it++)
	{
		(*it)->onEvent(event);
	}
}

