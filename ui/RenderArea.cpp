#include "RenderArea.h"

RenderArea::RenderArea(unsigned int width, unsigned int height) :
	window(0),
	width(width),
	height(height)
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

	drawables = new std::vector<Drawable*>();

}

void RenderArea::init()
{
	this->window = SDL_SetVideoMode(this->width,
											  this->height,
											  32,
											  SDL_HWSURFACE | SDL_DOUBLEBUF);
}

void RenderArea::display()
{
	Uint32 bgColor = SDL_MapRGB(window->format, 255, 255, 255);
	SDL_FillRect(window, NULL, bgColor);

	for(int i=0; i<drawables->size(); i++)
	{
		Drawable *obj = drawables->at(i);
		obj->draw();
	}

	SDL_Flip(window);
}

RenderArea::~RenderArea()
{
	SDL_Quit();
}
