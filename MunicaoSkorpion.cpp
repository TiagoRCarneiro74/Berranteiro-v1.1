#include "MunicaoSkorpion.h"

using namespace Itens;

MunicaoSkorpion::MunicaoSkorpion(Jogador* jo, float sx, float sy) : Item(jo, sx, sy) {
	if (!textura.loadFromFile("Midia/Imagens/Municao-Skorpion.png")) std::cout << "ERRO.\n";
	corpo.setTextureRect(sf::IntRect(0, 0, 48, 48));
	corpo.setTexture(textura);
	corpo.setPosition(sx, sy);
	corpo.setScale(0.4f, 0.4f);
	nome = "municaoskorpion";
	valor = 30;
}

MunicaoSkorpion::~MunicaoSkorpion() {}

void MunicaoSkorpion::pegar() {
	int i = 0;
	Arma* x;
	for (i = 1; i <= j->getl_arma()->getTam(); i -= -1) {
		x = j->getl_arma()->getElX(i)->getInfo();
		if (x->getNome() == "skorpion") {
			x->setAmmo(x->getAmmo() + valor);
			setVidas(0);
			f->getInterface()->setInstrucao("Pegou " + to_string(valor) + " munições para Skorpion.");
		}
	}
}