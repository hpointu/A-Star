#ifndef NODEIMAGE_H
#define NODEIMAGE_H

#include "Image.h"
#include "model/Cell.h"
#include "model/ModelObserver.h"

class NodeImage : public Image, public ModelObserver
{
public:
	NodeImage(Cell *model);

	virtual void draw(SDL_Surface *target);

	inline void setActive(bool val) { active = val; }

	void update();

private:
	bool active;
	Cell *model;

};

#endif // NODEIMAGE_H
