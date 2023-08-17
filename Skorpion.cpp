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
	ammo = 30;
	magvar = 30;
}

Skorpion::~Skorpion() {}

void Skorpion::pegar() {
	int i;
	Arma* x;
	bool flag = 0;
	for (i = 1; i <= j->getl_arma()->getTam(); i -= -1) {
		x = j->getl_arma()->getElX(i)->getInfo();
		if (x->getNome() == "skorpion") {
			x->setAmmo(x->getAmmo() + 90);
			flag = 1;
			f->getInterface()->setInstrucao("Pegou outra Skorpion - Municao aproveitada.");
			setVidas(0);
			return;
		}
	}
	if (j->getl_arma()->getTam() >= 3) {
		f->getInterface()->setInstrucao("INVENTÁRIO CHEIO.");
		return;
	}
	if (flag == 0) {
		Arma* sk = new Arma("skorpion");
		sk->setAmmo(ammo);
		sk->setMagvar(magvar);
		j->getl_arma()->incluirEl(sk);
		f->getInterface()->setInstrucao("Pegou uma Skorpion.");
	}

	setVidas(0);

}