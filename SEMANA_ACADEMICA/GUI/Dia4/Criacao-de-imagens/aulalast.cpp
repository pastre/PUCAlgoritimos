#include "aulalast.h"

Aulalast::Aulalast(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QMenu * menu;
	//Cada item no menu é um QAction
		QAction * item1, * item2, * item_gif;
	QVBoxLayout * vbox;
	//Inicializa-se o pixmap, passando o endereco da imagem como parametro
		pix.load("C:/Temp/!Img.jpg");
	//Inicializa-se o gif
		this->oTalDoGif = new QMovie("C:/Temp/opaoba.gif");
	//Inicializa-se a label
		label = new QLabel();
	//Inicializa-se o botao
		button = new QPushButton("Imagens");
	//Define o tamanho do botao
		button->setFixedSize(button->minimumSizeHint());
	//Inicializa-se o menu
		menu = new QMenu(this);
	//Inicializa-se os itens do menu
		item1 = new QAction("Cachoeiras");
		item2 = new QAction("Rio");
		item_gif = new QAction("Gifyyu");
	//Conecta cada funcao ao seu botao
		connect(item1, &QAction::triggered, this, &Aulalast::img1);
		connect(item2, &QAction::triggered, this, &Aulalast::img2);
		connect(item_gif, &QAction::triggered, this, &Aulalast::funcao_gif);
	//Usa essa funcao para colocar a imagem no label. O parametro é o pixmap
		//label->setPixmap(pix);
	//Usa essa funcao pra colocar a imagem no label e redimensiona-la. Keep aspect ratio mantem a proporcao de pixels
		label->setPixmap(pix.scaled(200, 100, Qt::KeepAspectRatio));
	//Inicializacao do layout
		vbox = new QVBoxLayout();
	//Adiciona-se os elementos ao menu
		menu->addAction(item1);
		menu->addAction(item2);
		menu->addAction(item_gif);
	//Adiciona-se o menu ao botao
		button->setMenu(menu);
	//Adicao dos elementos ao layout
		vbox->addWidget(button);
		vbox->addWidget(label);

	ui.centralWidget->setLayout(vbox);

}

void Aulalast::img1() {
	pix.load("C:/Temp/!Img.jpg");
	label->setPixmap(pix.scaled(300, 300, Qt::KeepAspectRatio));
}

void Aulalast::img2() {
	pix.load("C:/Temp/!Img1.jpg");
	label->setPixmap(pix.scaled(300, 300, Qt::KeepAspectRatio));
}

void Aulalast::funcao_gif() {
	label->setMovie(oTalDoGif);
	oTalDoGif->start();
}

Aulalast::~Aulalast()
{

}
