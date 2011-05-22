#include "Case.h"
#include <QBrush>
#include <QPen>

Case::Case() :
	 QGraphicsRectItem()
{
	setWall(true);
}

void Case::setWall(bool v)
{
	wall = v;
	setPen(QPen(Qt::white));
	setBrush(QBrush(QColor(Qt::white)));
	if(wall)
	{
		setBrush(QBrush(QColor(Qt::darkGray)));
	}
}
