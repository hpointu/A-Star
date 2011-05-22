#include "NodeImage.h"

NodeImage::NodeImage(Cell *model) :
	model(model)
{
	model->addObserver(this);
	imageNeural = IMG_Load("res/node.png");
	imageActive = IMG_Load("res/nodeActive.png");
	imageMarked = IMG_Load("res/nodeMarked.png");
	imagePined = IMG_Load("res/nodePined.png");
	imageStart = IMG_Load("res/nodeStart.png");
	imageEnd = IMG_Load("res/nodeEnd.png");

	mark = Utils::NEUTRAL;
}


void NodeImage::draw(SDL_Surface *target)
{
	surface = imageNeural;
	if(mark == Utils::ACTIVE)
		surface = imageActive;
	else if(mark == Utils::MARKED)
		surface = imageMarked;
	else if(mark == Utils::PINED)
		surface = imagePined;
	else if(mark == Utils::END)
		surface = imageEnd;
	else if(mark == Utils::START)
		surface = imageStart;

	Drawable::draw(target);
}


void NodeImage::update()
{
	this->mark = model->getMark();
}
