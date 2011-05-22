#ifndef MODELENTITY_H
#define MODELENTITY_H

#include <vector>
#include "ModelObserver.h"
#include "Utils.h"

class ModelEntity
{
public:
	ModelEntity();

	void addObserver(ModelObserver *observer);

	void notifyObservers();

	inline void mark(Utils::Marker m)
	{
		_mark = m;
		notifyObservers();
	}

	inline Utils::Marker getMark() { return _mark; }


private:
	std::vector<ModelObserver*> *observers;
	Utils::Marker _mark;
};

#endif // MODELENTITY_H
