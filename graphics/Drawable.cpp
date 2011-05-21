#include "Drawable.h"

void Drawable::setPosition(Sint16 x, Sint16 y)
{
	this->x = x;
	this->y = y;
}


void Drawable::setRotation(int degree)
{
	this->rot = degree;
}
