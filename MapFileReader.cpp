#include "MapFileReader.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "model/Cell.h"

MapFileReader::MapFileReader(std::string fileName)
{
	this->fileName = fileName;
	if(!isFileCorrect())
		exit(-1);
}


CellGraph* MapFileReader::getGraph()
{
	std::cout << "Loading map \"" << fileName << "\" ..." << std::endl;

	FILE *file = fopen(fileName.data(), "r");

	CellGraph *graph = new CellGraph(getMapWidth(), getMapHeight());
	unsigned int x = 0 , y = 0;
	char c;
	while(fread(&c, 1, 1, file))
	{
		if(c != '\n')
		{
			int intVal = c-48;
			Cell::Type type = (intVal == 1) ? Cell::WALL : Cell::EMPTY;

			Cell cell(x, y, type);
			graph->addNode(cell);

			// set the coords
			x++;
		}
		if(c == '\n')
		{
			y++;
			x=0;
		}
	}

	return graph;
}

unsigned int MapFileReader::getMapWidth()
{
	FILE *file = fopen(fileName.data(), "r");

	char c;
	unsigned int count = 0;
	while(fread(&c, 1, 1, file) && c != '\n')
	{
		count++;
	}
	return count;
}

unsigned int MapFileReader::getMapHeight()
{
	FILE *file = fopen(fileName.data(), "r");

	char c;
	unsigned int count = 0;
	while(fread(&c, 1, 1, file))
	{
		if(c == '\n')
		{
			count++;
		}
	}
	return count;
}

bool MapFileReader::isFileCorrect()
{
	int width = -1;

	FILE *file = fopen(fileName.data(), "r");

	char c;
	int count = 0;
	while(fread(&c, 1, 1, file))
	{
		count++;
		if(c == '\n')
		{
			if(width<0)
				width = count;
			else
			{
				if(width != count)
				{
					return false;
				}
			}
			count = 0;
		}
	}

	return true;
}
