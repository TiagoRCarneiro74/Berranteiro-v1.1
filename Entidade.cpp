#include "Entidade.h"
#include <iostream>
using namespace std;

using namespace Entidades;

Entidade::Entidade(const int v, sf::Vector2f xy, int i):
Ente(xy)
{
	pos = xy;
	//corpo.setFillColor(sf::Color::Blue);
	vel.x = 0.0;
	vel.y = 0.0;
	vivo = true;
	atacar = false;
	obstaculo = false;
	item = false;
	numVidas = v;
}

Entidade::~Entidade() {}

/*void Ente::move() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) if (pos.y > 0) pos.y = pos.y - vel.y;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) if (pos.y < 480) pos.y = pos.y + vel.y;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		vel.x = vel.x - 0.25;
		if (pos.x > 0) pos.x = pos.x + vel.x;
		vel.x = vel.x + 0.25;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		vel.x = vel.x + 0.25;
		if (pos.x < 640) pos.x = pos.x + vel.x;
		vel.x = vel.x - 0.25;
	}
	
	//cout << "(x, y) = (" << pos.x << ", " << pos.y << ")" << endl;
	corpo.setPosition(pos.x, pos.y);
}*/


void Entidade::setVelX(float x) { vel.x = x; }

void Entidade::setVelY(float y) { vel.y = y; }

void Entidade::cair() {
//if (vel.y != 0) {
	/*if (pos.y < 480 - getTam().y) {
		vel.y = vel.y + 300.0 / (CLOCKS_PER_SEC);
	}
	else if (pos.y >= 480 - getTam().y) {
		vel.y = 0;
		pos.y = 480 - getTam().y;
	}*/
	vel.y = vel.y + 300.0 / CLOCKS_PER_SEC;
}

bool Entidade::getVivo() { return vivo; }

void Entidade::setVivo(bool v) { vivo = v; }

bool Entidade::getAtacar() { return atacar; }

void Entidade::setAtacar(bool a) { atacar = a; }

void Entidade::operator++()
{
	numVidas++;
}
void Entidade::operator--()
{
	numVidas--;
	if(numVidas<=0)
		setVivo(false);
}

void Entidade::setVidas(int n) { 
	numVidas = n;
	if (numVidas <= 0) setVivo(false);
	else setVivo(true);
}

bool Entidade::getObstaculo()
{
	return obstaculo;
}