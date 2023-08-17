#include "Medpack.h"
#include "Arma.h"
using namespace Itens;

Medpack::Medpack(Jogador* jo, float sx, float sy) : Item(jo, sx, sy) {
	if (!textura.loadFromFile("Midia/Imagens/CorCheio.png")) std::cout << "ERRO.\n";
	corpo.setTextureRect(sf::IntRect(0, 0, 16, 16));
	corpo.setTexture(textura);
	corpo.setPosition(sx, sy);
	//corpo.setScale(0.4f, 0.4f);
	nome = "medpack";
	valor = 10;
}

Medpack::~Medpack() {}

void Medpack::pegar() {
	if (j->getVidas() < j->getMaxVidas()) j->setVidas(j->getVidas() + valor);
	if (j->getVidas() > j->getMaxVidas()) j->setVidas(j->getMaxVidas());
	setVidas(0);
	string x;
	x = to_string(valor);
	f->getInterface()->setInstrucao("+"+x+" HP.");
}

void Medpack::setValor(int f0) {
	valor = f0;
}