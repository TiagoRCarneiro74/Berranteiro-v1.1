#include "Pistola.h"
#include "Arma.h"
using namespace Itens;

Pistola::Pistola(Jogador* jo, float sx, float sy) : Item(jo, sx, sy) {
	if (!textura.loadFromFile("Midia/Imagens/Pistola.png")) std::cout << "ERRO.\n";
	corpo.setTextureRect(sf::IntRect(0, 0, 288, 158));
	corpo.setTexture(textura);
	corpo.setPosition(sx, sy);
	corpo.setScale(0.18f, 0.18f);
	nome = "pistola";
}

Pistola::~Pistola() {}

void Pistola::pegar() {
	bool chk = 0;
	int i = 1;
	for (i = 1; i <= j->getl_arma()->getTam(); i++) {
		if (j->getl_arma()->getElX(i)->getInfo()->getNome() == "pistola") {
			chk = 1;
			break;
		}
	}

	if (chk == 0) {
		Arma* sk = new Arma("pistola");
		j->getl_arma()->incluirEl(sk);
	}

	else {
		Arma* x = j->getl_arma()->getElX(i)->getInfo();
		x->setAmmo(x->getAmmo() + 120);
		x->setCad(x->getCad() * 2);
		x->setRec(x->getRec() * 3);
		x->setMag(x->getMag() * 2);
		x->setMagvar(x->getMagvar() + 12);
		x->setNome("pistola_d");
		x->setAesq("Midia/Imagens/2Pistolas-AE.png");
		x->setTesq("Midia/Imagens/2Pistolas-E.png");
		x->setAdir("Midia/Imagens/2Pistolas-AD.png");
		x->setTdir("Midia/Imagens/2Pistolas-D.png");
	}
	
	setVidas(0);
}