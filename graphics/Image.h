#ifndef IMAGE_H
#define IMAGE_H

#include <string>

#include "Drawable.h"

class Image : public Drawable
{
public:
	Image(std::string filename);

protected:
	std::string filename;

};

#endif // IMAGE_H
