#include "ModelEntity.h"

ModelEntity::ModelEntity()
{
	observers = new std::vector<ModelObserver*>();
}

void ModelEntity::notifyObservers()
{
	std::vector<ModelObserver*>::iterator it;
	for(it = observers->begin();
		 it < observers->end();
		 it++)
	{
		(*it)->update();
	}
}

void ModelEntity::addObserver(ModelObserver *observer)
{
	observers->push_back(observer);
}
