#include "ModelEntity.h"

ModelEntity::ModelEntity()
{
	observers = new std::vector<ModelObserver*>();
}

void ModelEntity::notifyObservers()
{
	for(unsigned int i=0; i<observers->size(); i++)
	{
		ModelObserver *obs = observers->at(i);
		obs->update();
	}
}

void ModelEntity::addObserver(ModelObserver *observer)
{
	observers->push_back(observer);
}
