#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QGraphicsRectItem>

#include "Case.h"
#include "Scene.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	 Scene *scene = new Scene();

	 scene->setBackgroundBrush(QBrush(Qt::black));
	 ui->graphicsView->setScene(scene);

	 te = new QPlainTextEdit();

	 test();
}

void MainWindow::test()
{
	ui->graphicsView->scene()->clear();
	int size = 22;
	for(int i=0; i < ui->hsp->value(); i++)
	{
		for(int j=0; j < ui->wsp->value(); j++)
		{
			qreal x = j*size;
			qreal y = i*size;
			Case *r = new Case();
			r->setRect(x,y,size,size);
			ui->graphicsView->scene()->addItem(r);
		}
	}

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
	 test();
}

void MainWindow::on_pushButton_clicked()
{
	QString text;
	QList<QGraphicsItem*> items = ui->graphicsView->scene()->items();
	for(int i=items.size()-1; i>=0; i--)
	{
		Case *c = static_cast<Case*>(items.at(i));
		text.append( c->isWall() ? '1' : '0' );
		if((i)%ui->wsp->value() == 0)
			text.append('\n');
	}

	te->clear();
	te->setPlainText(text);
	te->resize(800, 600);
	te->show();
}
