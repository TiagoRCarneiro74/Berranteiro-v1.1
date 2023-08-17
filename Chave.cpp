#include "Chave.h"
#include "Arma.h"
using namespace Itens;

Chave::Chave(Jogador* jo, float sx, float sy) : Item(jo, sx, sy) {
	if (!textura.loadFromFile("Midia/Imagens/Chave.png")) std::cout << "ERRO.\n";
	corpo.setTextureRect(sf::IntRect(0, 0, 196, 87));
	corpo.setTexture(textura);
	corpo.setPosition(sx, sy);
	corpo.setScale(0.3f, 0.3f);
	nome = "chave";
	s = new string;
	f = NULL;
}

Chave::~Chave() {
	delete s;
}

void Chave::setString(string s0) { *s = s0; };

void Chave::pegar() {
	j->getItens()->incluirEl(s);
	setVivo(false);
	f->getInterface()->setInstrucao("CHAVE " + *s + " OBTIDA!");
}

void Chave::setVidas(int n) {}