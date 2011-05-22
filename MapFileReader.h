#ifndef MAPFILEREADER_H
#define MAPFILEREADER_H

#include "model/CellGraph.h"
#include <string>

class MapFileReader
{
public:
	 MapFileReader(std::string fileName);

	 CellGraph* getGraph();

	 unsigned int getMapWidth();
	 unsigned int getMapHeight();

private:
	 bool isFileCorrect();

	 std::string fileName;
};

#endif // MAPFILEREADER_H
