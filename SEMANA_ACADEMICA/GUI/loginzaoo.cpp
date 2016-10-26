#include "loginzaoo.h"

Loginzaoo::Loginzaoo(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	//Iniciacao das variaveis
	label_usuario = new QLabel("Digite um usuario");
	label_senha = new QLabel("Digite uma senha");
	label_confirma_senha = new QLabel("Confirme sua senha");
	line_usuario = new QLineEdit();
	line_senha = new QLineEdit();
	line_confirma_senha = new QLineEdit();
	botao = new QPushButton();
	botao->setAccessibleName("Envia");
	botao->setObjectName("Envia");
	QVBoxLayout * vbox = new QVBoxLayout();
	QWidget * wTela = new QWidget();
	QGridLayout * wGrid = new QGridLayout();
	vbox->addWidget(label_usuario);
	vbox->addWidget(line_usuario);
	vbox->addWidget(label_senha);
	vbox->addWidget(line_senha);
	vbox->addWidget(label_confirma_senha);
	vbox->addWidget(line_confirma_senha);
	vbox->addWidget(botao);
	wTela->setLayout(vbox);
	wGrid->addWidget(wTela);


	//FAZER ESSE CONNECT connect(botao, SIGNAL(valueChanged(this)), this, checa());
	ui.centralWidget->setLayout(wGrid);
}

Loginzaoo::~Loginzaoo()
{

}

void Loginzaoo::checa() {

}
