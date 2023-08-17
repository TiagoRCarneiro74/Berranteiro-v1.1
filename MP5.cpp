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
	ammo = 32;
	magvar = 32;
}

MP5::~MP5() {}

void MP5::pegar() {
	int i;
	Arma* x;
	bool flag = 0;
	for (i = 1; i <= j->getl_arma()->getTam(); i -= -1) {
		x = j->getl_arma()->getElX(i)->getInfo();
		if (x->getNome() == "mp5") {
			x->setAmmo(x->getAmmo() + 128);
			flag = 1;
			f->getInterface()->setInstrucao("Pegou outra MP5 - Municao aproveitada.");
			setVidas(0);
			return;
		}
	}
	if (j->getl_arma()->getTam() >= 3) {
		f->getInterface()->setInstrucao("INVENTÁRIO CHEIO.");
		return;
	}
	if (flag == 0) {
		Arma* sk = new Arma("mp5");
		sk->setAmmo(ammo);
		sk->setMagvar(magvar);
		j->getl_arma()->incluirEl(sk);
		f->getInterface()->setInstrucao("Pegou uma MP5.");
	}
	
	setVidas(0);
	
}