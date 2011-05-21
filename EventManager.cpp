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
	for(unsigned int i=0; i<listeners->size(); i++)
	{
		listeners->at(i)->onEvent(event);
	}
}

