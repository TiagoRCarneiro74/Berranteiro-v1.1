#include "Opcao.h"

Opcao::Opcao(): Ente(sf::Vector2f(0, 0)) {
	selecionada = false;
	corpo.setTextureRect(sf::IntRect(0, 0, 320, 80));
}

Opcao::Opcao(sf::Vector2f ini): Ente(ini) {
	selecionada = false;
	corpo.setTextureRect(sf::IntRect(0, 0, 579, 80));
}

Opcao::~Opcao() {}

void Opcao::setSelecionada(bool sel) { selecionada = sel; }

const bool Opcao::getSelecionada() { return selecionada; }

void Opcao::atualiza() {
	/*if (sf::Mouse::getPosition().x >= getPos().x && sf::Mouse::getPosition().y >= getPos().y && sf::Mouse::getPosition().x <= getPos().x + getPos().x && sf::Mouse::getPosition().y <= getPos().y + getPos().y) {
		selecionada = true;
	}
	else selecionada = false;*/
	GerenciadorGrafico* graf = GerenciadorGrafico::getGerenciadorGrafico();
	int tamx = graf->getWindow()->getSize().x;
	int tamy = graf->getWindow()->getSize().y;
	if (tamx == 1360) {
		corpo.setScale(1.45f, 1.45f);
		setPos(260, 0);
		corpo.setPosition(260, 0);
	}
	else {
		corpo.setScale(1, 1);
		setPos(30, 0);
		corpo.setPosition(30, 0);
	}
}

void Opcao::executar() {}