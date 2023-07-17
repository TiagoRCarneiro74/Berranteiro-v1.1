#include "Medpack.h"
#include "Arma.h"
using namespace Itens;

Medpack::Medpack(Jogador* jo, float sx, float sy) : Item(jo, sx, sy) {
	if (!textura.loadFromFile("Midia/Imagens/CorCheio.png")) std::cout << "ERRO.\n";
	corpo.setTextureRect(sf::IntRect(0, 0, 16, 16));
	corpo.setTexture(textura);
	corpo.setPosition(sx, sy);
	//corpo.setScale(0.4f, 0.4f);
	nome = "coracao";
}

Medpack::~Medpack() {}

void Medpack::pegar() {
	if (j->getVidas() < j->getMaxVidas()) j->setVidas(j->getVidas() + 10);
	if (j->getVidas() > j->getMaxVidas()) j->setVidas(j->getMaxVidas());
	setVidas(0);
}