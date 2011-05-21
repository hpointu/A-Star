#ifndef APPLICATION_H
#define APPLICATION_H

#include "ui/RenderArea.h";

class Application
{
public:
    Application();

	 void run();

private:
	 RenderArea *ra;
};

#endif // APPLICATION_H
