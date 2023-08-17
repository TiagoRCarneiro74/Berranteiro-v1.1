#include "Caixa.h"
#include "Arma.h"
#include "Fase.h"
#include "Chave.h"
using namespace Fases;
using namespace Itens;

Caixa::Caixa(Jogador* jo, float sx, float sy) : Item(jo, sx, sy) {
	if (!textura.loadFromFile("Midia/Imagens/Caixa.png")) std::cout << "ERRO.\n";
	corpo.setTextureRect(sf::IntRect(0, 0, 260, 264));
	corpo.setTexture(textura);
	corpo.setPosition(sx, sy);
	corpo.setScale(0.2f, 0.2f);
	numVidas = 10;
	nome = "caixa";
	db.loadFromFile("Midia/Musicas/bustcrate1.wav");
	d.setBuffer(db);
	i1 = "\n";
	i2 = "\n";
}

Caixa::~Caixa() {}

void Caixa::pegar() {
	j->colisaoMapaObs(this);
}

void Caixa::findar() {
	d.play();
	srand(time(NULL));
	int x=0;
	Item* i = NULL;
	if (i1 != "\n") {
		//f->geraItem(pos.x - 50, pos.y - 20, i1);
		if (i1[0] == 'c' && i1[1] == 'h') {
			string aux, aux2;
			for (int x = 0; x < 5; x++) aux.push_back(i1[x]);
			i = f->geraItem(pos.x - 50, pos.y - 20, aux);
			aux2.push_back(i1[6]);
			aux2.push_back(i1[7]);
			static_cast <Chave*> (i)->setString(aux2);
		}
		else f->geraItem(pos.x - 50, pos.y - 20, i1);
	}
	

	else {
		int x = rand() % 10;
		if (x == 0) f->geraItem(pos.x - 50, pos.y - 20, "municaoskorpion");
		else if (x == 1) f->geraItem(pos.x - 50, pos.y - 20, "medpack");
		else if (x == 2) f->geraItem(pos.x - 50, pos.y - 20, "pistola");
		else if (x == 3) f->geraItem(pos.x - 50, pos.y - 20, "municaomp5");
	}
	
	if (i2 != "\n") f->geraItem(pos.x + 50, pos.y - 20, i2);

	else {
		x = rand() % 10;
		if (x == 0) f->geraItem(pos.x + 50, pos.y - 20, "municaoskorpion");
		else if (x == 1) f->geraItem(pos.x + 50, pos.y - 20, "medpack");
		else if (x == 2) f->geraItem(pos.x + 50, pos.y - 20, "pistola");
		else if (x == 3) f->geraItem(pos.x + 50, pos.y - 20, "municaomp5");
	}
	
}

void Caixa::setI1(string s) { i1 = s; }

void Caixa::setI2(string s) { i2 = s; }

void Caixa::setFase(Fase* k) { f = k; }

string Caixa::getI1() { return i1; }

string Caixa::getI2() { return i2; }
