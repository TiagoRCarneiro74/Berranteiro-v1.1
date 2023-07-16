#include "Skorpion.h"
#include "Arma.h"
using namespace Itens;

Skorpion::Skorpion(Jogador* jo, float sx, float sy): Item(jo, sx, sy) {
	if (!textura.loadFromFile("Midia/Imagens/Skorpion.png")) std::cout << "ERRO.\n";
	corpo.setTextureRect(sf::IntRect(0, 0, 300, 76));
	corpo.setTexture(textura);
	corpo.setPosition(sx, sy);
	corpo.setScale(0.4f, 0.4f);
	nome = "skorpion";
}

Skorpion::~Skorpion() {}

void Skorpion::pegar() {
	Arma* sk = new Arma("skorpion");
	j->getl_arma()->incluirEl(sk);
	setVidas(0);
}