#include "Scene.h"
#include "Case.h"

#include <QGraphicsView>
Scene::Scene(QObject *parent) :
	QGraphicsScene(parent)
{
	mode = -1;
}


void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	QPointF pos = event->scenePos();
	if(QGraphicsItem *i = this->itemAt(pos))
	{
		Case* c = static_cast<Case*>(i);
		mode = c->isWall() ? 0 : 1;
		c->setWall(!c->isWall());
	}
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	mode = -1;
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	if(mode != -1)
	{
		bool v = mode == 1 ? true : false;
		QPointF pos = event->scenePos();
		if(QGraphicsItem *i = this->itemAt(pos))
		{
			Case* c = static_cast<Case*>(i);
			c->setWall(v);
		}
	}
}
