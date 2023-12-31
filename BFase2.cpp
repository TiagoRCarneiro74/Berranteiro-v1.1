#include "BFase2.h"

BFase2::BFase2(Menu* m) : Opcao() {
	pMenu = m;
	sf::Texture tex;
	tex.loadFromFile("Midia/Imagens/Menu Opc 3.png");
	setTextura(tex);
	setPos(sf::Vector2f(160.0f, 240.0f));
	corpo.setPosition(sf::Vector2f(160.0f, 240.0f));

	m->setBFase2(this);
}

BFase2::~BFase2() {}

void BFase2::atualiza() {
	GerenciadorGrafico* graf = GerenciadorGrafico::getGerenciadorGrafico();
	int tamx = graf->getWindow()->getSize().x;
	int tamy = graf->getWindow()->getSize().y;
	if (tamx == 1360) {
		corpo.setScale(1.45f, 1.45f);
		setPos(448, 0.5 * tamy);
		corpo.setPosition(448, 0.5 * tamy);
	}
	else {
		corpo.setScale(1, 1);
		setPos(0.25 * tamx, 0.5 * tamy);
		corpo.setPosition(0.25 * tamx, 0.5 * tamy);
	}
	if (sf::Mouse::getPosition().x - graf->getWindow()->getPosition().x >= getPos().x && sf::Mouse::getPosition().y - graf->getWindow()->getPosition().y - 30 >= getPos().y && sf::Mouse::getPosition().x - graf->getWindow()->getPosition().x <= getPos().x + getTam().x && sf::Mouse::getPosition().y - graf->getWindow()->getPosition().y - 30 <= getPos().y + getTam().y) {
		selecionada = true;
		cout << "O mouse esta sobre a opcao Fase 2.\n";
		sf::Texture tex;
		tex.loadFromFile("Midia/Imagens/Menu Opc 3-Sel.png");
		setTextura(tex);
	}
	else {
		selecionada = false;
		sf::Texture tex;
		tex.loadFromFile("Midia/Imagens/Menu Opc 3.png");
		setTextura(tex);
	}
}

void BFase2::executar() {
	/*if (pMenu->getFase2()) delete pMenu->getFase2();
	Fase2* f2 = new Fase2();
	pMenu->setFase2(f2);*/

	if (pMenu->getFase3()) delete pMenu->getFase3();
	Fase3* f3 = new Fase3();
	pMenu->setFase3(f3);
}