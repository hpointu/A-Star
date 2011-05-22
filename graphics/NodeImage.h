#ifndef NODEIMAGE_H
#define NODEIMAGE_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "Drawable.h"

#include "Utils.h"

#include "model/Cell.h"
#include "model/ModelObserver.h"

class NodeImage : public Drawable, public ModelObserver
{
public:
	NodeImage(Cell *model);

	virtual void draw(SDL_Surface *target);

	void update();

private:
	Cell *model;

	SDL_Surface *imageNeural;
	SDL_Surface *imageActive;
	SDL_Surface *imageMarked;
	SDL_Surface *imagePined;
	SDL_Surface *imageStart;
	SDL_Surface *imageEnd;

	Utils::Marker mark;

};

#endif // NODEIMAGE_H
