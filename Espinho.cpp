#include "Espinho.h"
using namespace Entidades;
#include <time.h>

Espinho::Espinho(float x, float y, int q): Obstaculo(x, y) {
	qtd = q;
	srand(time(NULL));
	//danoso = true;
	afiado = rand() % 10 + 10;
	atacar = true;
	danoso = afiado;
	setTextura("Midia/Imagens/Espinhos.png");
	corpo.setTextureRect(sf::IntRect(0, 0, 16*qtd, 16));
	
	corpo.setScale(2, 2);
}

Espinho::~Espinho() {}

int Espinho::getAfiado() { return afiado; }