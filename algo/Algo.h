#ifndef ALGO_H
#define ALGO_H

#include "model/CellGraph.h"

#include <QThread>

class Algo : public QThread
{
public:
	Algo(CellGraph *graph);

	virtual void process() = 0;

protected:
	void run();

	CellGraph *graph;

};

#endif // ALGO_H
