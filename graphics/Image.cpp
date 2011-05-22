#include "Image.h"
#include <SDL/SDL_image.h>

Image::Image(std::string filename) :
	Drawable()
{
	surface = IMG_Load(filename.data());
}
