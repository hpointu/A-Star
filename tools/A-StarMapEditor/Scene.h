#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class Scene : public QGraphicsScene
{
	Q_OBJECT
public:
	explicit Scene(QObject *parent = 0);

	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

private:
	int mode;

};

#endif // SCENE_H
