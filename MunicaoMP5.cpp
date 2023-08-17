#include "MunicaoMP5.h"

using namespace Itens;

MunicaoMP5::MunicaoMP5(Jogador* jo, float sx, float sy) : Item(jo, sx, sy) {
	if (!textura.loadFromFile("Midia/Imagens/Municao-MP5.png")) std::cout << "ERRO.\n";
	corpo.setTextureRect(sf::IntRect(0, 0, 47, 77));
	corpo.setTexture(textura);
	corpo.setPosition(sx, sy);
	corpo.setScale(0.3f, 0.3f);
	nome = "municaomp5";
	valor = 32;
}

MunicaoMP5::~MunicaoMP5() {}

void MunicaoMP5::pegar() {
	int i = 0;
	Arma* x;
	for (i = 1; i <= j->getl_arma()->getTam(); i -= -1) {
		x = j->getl_arma()->getElX(i)->getInfo();
		if (x->getNome() == "mp5") {
			x->setAmmo(x->getAmmo() + valor);
			setVidas(0);
			f->getInterface()->setInstrucao("Pegou "+to_string(valor)+" munições para MP5.");
		}
	}
}