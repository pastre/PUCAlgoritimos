#ifndef LOGINZAOO_H
#define LOGINZAOO_H

#include <QtWidgets/QMainWindow>
#include "ui_loginzaoo.h"

#include <QtWidgets\qpushbutton.h>
#include <qlabel.h>

#include <QtWidgets\qslider.h>
#include <QtWidgets\qlayout.h>
#include <QtWidgets\qlabel.h>
#include <QtWidgets\qgridlayout.h>
#include <QtWidgets\qaction.h>
#include <QtWidgets\qmenu.h>
#include <QtWidgets\qmessagebox.h>
#include <QtWidgets\qplaintextedit.h>
#include <QtWidgets\qtextedit.h>
#include <QtWidgets\qlineedit.h>
class Loginzaoo : public QMainWindow
{
	Q_OBJECT

public:
	Loginzaoo(QWidget *parent = 0);
	~Loginzaoo();

private:
	void checa();
	QLabel * label_usuario;
	QLabel * label_senha;
	QLabel * label_confirma_senha;
	QLineEdit * line_usuario;
	QLineEdit * line_senha;
	QLineEdit * line_confirma_senha;
	QPushButton * botao;
	Ui::LoginzaooClass ui;
};

#endif // LOGINZAOO_H
