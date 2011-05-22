#ifndef MODELENTITY_H
#define MODELENTITY_H

#include <vector>
#include "ModelObserver.h"

class ModelEntity
{
public:
    ModelEntity();

	 void addObserver(ModelObserver *observer);

	 void notifyObservers();

private:
	 std::vector<ModelObserver*> *observers;
};

#endif // MODELENTITY_H
