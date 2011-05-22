#include "Algo.h"

Algo::Algo(CellGraph *graph) :
	graph(graph)
{
}

void Algo::run()
{
	process();
	exec();
}
