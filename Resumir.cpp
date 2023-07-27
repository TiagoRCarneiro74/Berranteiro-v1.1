#include "Resumir.h"
#include <iostream>
using namespace std;

Resumir::Resumir(Menu* m) : Opcao() {
	pMenu = m;
	//sf::Texture tex;
	//tex.loadFromFile("Midia/Imagens/Menu Opc 1a.png");
	//setTextura(tex);
	//setTextura("Midia/Imagens/Menu Opc 1a.png");
	if(!textura.loadFromFile("Midia/Imagens/Menu Opc 1a.png")) cout << "Erro na abertura da imagem";
	float x = GerenciadorGrafico::getGerenciadorGrafico()->getCoorView().x - 160;
	float y = GerenciadorGrafico::getGerenciadorGrafico()->getCoorView().y - 160;
	setPos(sf::Vector2f(x, y));
	corpo.setPosition(sf::Vector2f(x, y));
	cout << "Resumir criado.\npos.x = " << getPos().x << "\npos.y = " << getPos().y << endl;

	m->setResumir(this);
}

Resumir::~Resumir() {}

void Resumir::executar() 
{

	GerenciadorGrafico* graf = GerenciadorGrafico::getGerenciadorGrafico();
	Jogador* j1=NULL;
	Jogador* j2=NULL;
	if (pMenu->getFase2()) 
	{
		j2 = pMenu->getFase2()->getJogador2();
		j1 = pMenu->getFase2()->getJogador1();

		pMenu->getFase2()->getMusica()->play();
	}
	else if (pMenu->getFase1()) 
	{
		j2 = pMenu->getFase1()->getJogador2();
		j1 = pMenu->getFase1()->getJogador1();

		pMenu->getFase1()->getMusica()->play();
	}

	j1->setVidas(50);
	j2->setVidas(50);

	if(j1->getSegue()==1)
	{
		graf->setView(sf::Vector2f(j1->getPos().x, j1->getPos().y));
		j2->setPos(j1->getPos().x, j1->getPos().y);
	}
	else
	{
		graf->setView(sf::Vector2f(j2->getPos().x, j2->getPos().y));
		j1->setPos(j2->getPos().x, j2->getPos().y);
		j1->setSegue(1);
	}
	
}

void Resumir::atualiza() {
	GerenciadorGrafico* graf = GerenciadorGrafico::getGerenciadorGrafico();
	cout << "Posicao do mouse:\npos.x = " << sf::Mouse::getPosition().x - graf->getWindow()->getPosition().x << "\npos.y = " << sf::Mouse::getPosition().y - graf->getWindow()->getPosition().y << endl;
	if (sf::Mouse::getPosition().x - graf->getWindow()->getPosition().x >= getPos().x && sf::Mouse::getPosition().y - graf->getWindow()->getPosition().y - 30 >= getPos().y && sf::Mouse::getPosition().x - graf->getWindow()->getPosition().x <= getPos().x + getTam().x && sf::Mouse::getPosition().y - graf->getWindow()->getPosition().y - 30 <= getPos().y + getTam().y) {
		cout << "Mouse na opcao Resumir.\n";
		selecionada = true;
		textura.loadFromFile("Midia/Imagens/Menu Opc 1a-Sel.png");
	}
	else {
		selecionada = false;
		sf::Texture tex;
		tex.loadFromFile("Midia/Imagens/Menu Opc 1a.png");
		setTextura(tex);
	}
}