#include "MP5.h"
#include "Arma.h"
using namespace Itens;

MP5::MP5(Jogador* jo, float sx, float sy) : Item(jo, sx, sy) {
	if (!textura.loadFromFile("Midia/Imagens/MP5.png")) std::cout << "ERRO.\n";
	corpo.setTextureRect(sf::IntRect(0, 0, 400, 140));
	corpo.setTexture(textura);
	corpo.setPosition(sx, sy);
	corpo.setScale(0.2f, 0.2f);
	nome = "mp5";
}

MP5::~MP5() {}

void MP5::pegar() {
	Arma* sk = new Arma("mp5");
	j->getl_arma()->incluirEl(sk);
	setVidas(0);
}