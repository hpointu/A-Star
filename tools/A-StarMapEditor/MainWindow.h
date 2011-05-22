#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

	void test();

private slots:
	void on_pushButton_2_clicked();

	void on_pushButton_clicked();

private:
	Ui::MainWindow *ui;
	QPlainTextEdit *te;
};

#endif // MAINWINDOW_H
