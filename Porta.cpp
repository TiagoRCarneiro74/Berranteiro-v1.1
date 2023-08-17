#include "Porta.h"
#include "Interface.h"

Porta::Porta(Jogador* jo, float sx, float sy): Item(jo, sx, sy) {
	if (!textura.loadFromFile("Midia/Imagens/PortaFechada.png")) std::cout << "ERRO.\n";
	corpo.setTextureRect(sf::IntRect(0, 0, 400, 480));
	corpo.setTexture(textura);
	corpo.setPosition(sx, sy);
	corpo.setScale(0.2f, 0.2f);
	nome = "porta";
	ativ = "\n";
	aberta = 0;
}

Porta::~Porta() {}

void Porta::pegar() {
	if (aberta == 0) for (int i = 1; i <= j->getItens()->getTam(); i++) if (*(j->getItens()->getElX(i)->getInfo()) == ativ) {
		textura.loadFromFile("Midia/Imagens/PortaAberta.png");
		aberta = 1;
		f->getInterface()->setInstrucao("PORTA ABERTA!");
	}
	if (aberta == 0) {
		f->getInterface()->setInstrucao("OBTER A CHAVE " + ativ);
		j->colisaoMapaObs(static_cast <Entidade*> (this));
	}
}

void Porta::setVidas(int n) {}