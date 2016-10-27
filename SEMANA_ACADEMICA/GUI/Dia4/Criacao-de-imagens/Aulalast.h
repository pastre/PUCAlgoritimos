#ifndef AULALAST_H
#define AULALAST_H

#include <QtWidgets/QMainWindow>
#include "ui_aulalast.h"

#include <QtWidgets\qlabel.h>
#include <QtWidgets\qlayout.h>
#include <QtWidgets\qwidget.h>
#include <QtWidgets\qgridlayout.h>
#include <QtWidgets\qpushbutton.h>
#include <QtGui\qpixmap.h>
#include <qmovie.h>

class Aulalast : public QMainWindow
{
	Q_OBJECT

public:
	Aulalast(QWidget *parent = 0);
	~Aulalast();

private:
	Ui::AulalastClass ui;
	QLabel * label;
	QPixmap pix;
	QPushButton * button;
	QMovie *oTalDoGif;

	private slots:
	void img1();
	void img2();
	void funcao_gif();
};

#endif // AULALAST_H
