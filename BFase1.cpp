#include "BFase1.h"

BFase1::BFase1(Menu* m): Opcao() {
	pMenu = m;
	sf::Texture tex;
	tex.loadFromFile("Midia/Imagens/Menu Opc 2.png");
	setTextura(tex);
	setPos(sf::Vector2f(160.0f, 160.0f));
	corpo.setPosition(sf::Vector2f(160.0f, 160.0f));

	m->setBFase1(this);
}

BFase1::~BFase1() {}

void BFase1::atualiza() {
	GerenciadorGrafico* graf = GerenciadorGrafico::getGerenciadorGrafico();
	if (sf::Mouse::getPosition().x - graf->getWindow()->getPosition().x >= getPos().x && sf::Mouse::getPosition().y - graf->getWindow()->getPosition().y - 30 >= getPos().y && sf::Mouse::getPosition().x - graf->getWindow()->getPosition().x <= getPos().x + getTam().x && sf::Mouse::getPosition().y - graf->getWindow()->getPosition().y - 30 <= getPos().y + getTam().y) {
		selecionada = true;
		sf::Texture tex;
		tex.loadFromFile("Midia/Imagens/Menu Opc 2-Sel.png");
		setTextura(tex);
	}
	else {
		selecionada = false;
		sf::Texture tex;
		tex.loadFromFile("Midia/Imagens/Menu Opc 2.png");
		setTextura(tex);
	}
}

void BFase1::executar() {
	if (pMenu->getFase1()) delete pMenu->getFase1();
	Fase1* f1 = new Fase1();
	pMenu->setFase1(f1);
}