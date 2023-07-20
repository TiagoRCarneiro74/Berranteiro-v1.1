#include "Caixa.h"
#include "Arma.h"
#include "Fase.h"
using namespace Fases;
using namespace Itens;

Caixa::Caixa(Jogador* jo, float sx, float sy) : Item(jo, sx, sy) {
	if (!textura.loadFromFile("Midia/Imagens/Caixa.png")) std::cout << "ERRO.\n";
	corpo.setTextureRect(sf::IntRect(0, 0, 260, 264));
	corpo.setTexture(textura);
	corpo.setPosition(sx, sy);
	corpo.setScale(0.25f, 0.25f);
	numVidas = 10;
	nome = "caixa";
}

Caixa::~Caixa() {}

void Caixa::pegar() {}

void Caixa::findar() {
	srand(time(NULL));
	int x = rand() % 10;
	if (x == 0) f->geraItem(pos.x - 50, pos.y - 20, "skorpion");
	else if (x == 1) f->geraItem(pos.x - 50, pos.y - 20, "medpack");
	else if (x == 2) f->geraItem(pos.x - 50, pos.y - 20, "pistola");
	else if (x == 3) f->geraItem(pos.x - 50, pos.y - 20, "mp5");

	x = rand() % 10;
	if (x == 0) f->geraItem(pos.x + 50, pos.y - 20, "skorpion");
	else if (x == 1) f->geraItem(pos.x + 50, pos.y - 20, "medpack");
	else if (x == 2) f->geraItem(pos.x + 50, pos.y - 20, "pistola");
	else if (x == 3) f->geraItem(pos.x + 50, pos.y - 20, "mp5");
}

void Caixa::setI1(Item* i) { i1 = i; }

void Caixa::setI2(Item* i) { i2 = i; }

void Caixa::setFase(Fase* k) { f = k; }

Item* Caixa::getI1() { return i1; }

Item* Caixa::getI2() { return i2; }
