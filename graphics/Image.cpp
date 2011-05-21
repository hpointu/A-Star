#include "Image.h"
#include <SDL/SDL_image.h>

Image::Image(char *filename) :
	Drawable()
{
	surface = IMG_Load(filename);
}
