#include "Mapa.h"
#include <iostream>

Mapa::Mapa() : lista(), colidiveis() {
	//inicializaAuto();
	//std::cout << "inicializaAuto executada.\n";
}

Mapa::~Mapa() {
	lista.~Lista();
	colidiveis->~Lista();
}

Mapa::Mapa(sf::Vector2f ini, sf::Vector2f fim) : lista() {
	len = fim.x - ini.x;
	this->ini = ini.x;
	inicializaAuto(ini, fim);
}

void Mapa::inicializaAuto(sf:: Vector2f ini, sf::Vector2f fim) {
	bool chk = 0;
	float len = fim.x - ini.x;
	for (float i = ini.x; i <= fim.x; i = i + 32) {
		chk = 0;
		for (float j = ini.y; j <= fim.y; j = j + 32) {
			Plataforma* p = new Plataforma(sf::Vector2f(i, j));
			if (p->getNula() == false) {
				chk = 1;
				cout << "Item adicionado a lista.\n";
				//p->setGerente(graf);
				lista.incluirEl(p);
				if (p->verifNula(sf::Vector2f(i + 32, j)) || p->verifNula(sf::Vector2f(i - 32, j)) ||
					p->verifNula(sf::Vector2f(i, j + 32)) || p->verifNula(sf::Vector2f(i, j - 32))) {
					if (i <= ini.x + len / 3) {
						c1.incluirEl(p);
						cout << "ADICAO A C1.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
					}
					if (i > ini.x + len / 6 && i < ini.x + len / 2) c1b.incluirEl(p);
					if (i > ini.x + len / 3 && i < ini.x + 2 * len / 3) c2.incluirEl(p);
					if (i > ini.x + len / 2 && i < ini.x + 5 * len / 6) c2b.incluirEl(p);
					if (i > ini.x + 2 * len / 3 && i <= ini.x + len) c3.incluirEl(p);
				}
			}
			//else if (chk == 1) break;
		}
	}
}

Lista<Plataforma>* Mapa::getLista() { return &lista; }

void Mapa::imprimir() {
	Lista<Plataforma>::Elemento<Plataforma>* it = lista.getPrimeiro();
	while (it != NULL) {
		it->getInfo()->imprimir();
		it = it->getProximo();
	}
}

Lista<Plataforma>* Mapa::getColidiveis() { return colidiveis; }

Lista<Plataforma>* Mapa::getC1() { return &c1; }

Lista<Plataforma>* Mapa::getC1b() { return &c1b; }

Lista<Plataforma>* Mapa::getC2() { return &c2; }

Lista<Plataforma>* Mapa::getC2b() { return &c2b; }

Lista<Plataforma>* Mapa::getC3() { return &c3; }

float Mapa::getLen() { return len; }

void Mapa::setColidiveis(Lista<Plataforma>* l) { colidiveis = l; }

float Mapa::getIni() { return ini; }