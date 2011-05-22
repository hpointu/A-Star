#include "NodeImage.h"

NodeImage::NodeImage(Cell *model) :
	Image(""),
	active(false),
	model(model)
{
	model->addObserver(this);
}


void NodeImage::draw(SDL_Surface *target)
{
	filename = "res/node.png";
	if(active)
		filename = "res/nodeActive.png";

	Image::draw(target);
}


void NodeImage::update()
{
	this->active = model->isActive();
}
