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
	int tamx = graf->getWindow()->getSize().x;
	int tamy = graf->getWindow()->getSize().y;
	if (tamx == 1360) {
		corpo.setScale(1.45f, 1.45f);
		setPos(448, 0.33333 * tamy);
		corpo.setPosition(448, 0.33333 * tamy);
	}
	else {
		corpo.setScale(1, 1);
		setPos(0.25 * tamx, 0.33333 * tamy);
		corpo.setPosition(0.25 * tamx, 0.33333 * tamy);
	}
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