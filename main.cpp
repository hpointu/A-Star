#include <iostream>

#include "Application.h"

int main(int argc, char **argv)
{
	std::cout << "Launching..." << std::endl;

	Application app(argc, argv);
	app.run();

	return 0;
}
