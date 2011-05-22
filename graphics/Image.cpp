#include "Image.h"
#include <SDL/SDL_image.h>

Image::Image(std::string filename) :
	Drawable(),
	filename(filename)
{

}

void Image::draw(SDL_Surface *target)
{
	surface = IMG_Load(filename.data());
	Drawable::draw(target);
}
