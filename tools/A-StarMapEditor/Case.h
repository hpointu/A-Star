#ifndef CASE_H
#define CASE_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class Case : public QGraphicsRectItem
{
public:
	explicit Case();

	void setWall(bool v);

	bool isWall(){return wall;}

private:
	bool wall;

};

#endif // CASE_H
