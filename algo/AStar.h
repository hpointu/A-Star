#ifndef ASTAR_H
#define ASTAR_H

#include "Algo.h"
#include "model/CellGraph.h"
#include "model/Cell.h"

#include <QList>


using namespace std;

class AStar : public Algo
{

public:
	AStar(CellGraph *graph);

	virtual void process();

private:


};

#endif // ASTAR_H
