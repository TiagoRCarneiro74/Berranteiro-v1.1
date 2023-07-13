#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "Interface.h"
#include <iostream>
using namespace std;

Interface::Interface() : Ente(sf::Vector2f(0.0f, 0.0f)) {
	sf::Vector2f pos = sf::Vector2f(gerente->getCoorView().x - 320, gerente->getCoorView().y - 240);

	TRosto.loadFromFile("Midia/Imagens/Rosto.png");
	rosto.setTextureRect(sf::IntRect(0, 0, 256, 256));
	rosto.setScale(sf::Vector2f(0.25f, 0.25f));
	rosto.setTexture(TRosto);
	rosto.setPosition(pos);

	CorCheio.loadFromFile("Midia/Imagens/CorCheio.png");
	CorVazio.loadFromFile("Midia/Imagens/CorVazio.png");
	v1.setTexture(CorCheio);
	v2.setTexture(CorCheio);
	v3.setTexture(CorCheio);
	v4.setTexture(CorVazio);
	v5.setTexture(CorVazio);
	v1.setTextureRect(sf::IntRect(0, 0, 16, 16));
	v2.setTextureRect(sf::IntRect(0, 0, 16, 16));
	v3.setTextureRect(sf::IntRect(0, 0, 16, 16));
	v4.setTextureRect(sf::IntRect(0, 0, 16, 16));
	v5.setTextureRect(sf::IntRect(0, 0, 16, 16));

	mag = new Textbox();
	ammo = new Textbox();
	f = new sf::Font();
	f->loadFromFile("Midia/Imagens/FSEX300.ttf");
	mag->setFont(f);
	ammo->setFont(f);

	mag->setText("CAR.: 00");
	ammo->setText("TOTAL: 00");

	//Arma* x = j->getl_arma()->getElX(j->getArmaSel())->getInfo();
	//mag->setText("CAR.: "+to_string(x->getMagvar()));
	//ammo->setText("TOTAL: "+to_string(x->getAmmo()));
}

Interface::~Interface() {
	delete f;
	delete ammo;
	delete mag;
}

void Interface::alteraAmmo(int x) {
	char buf[5];
	_itoa(x, buf, 10);
	ammo->setText(buf);
}

void Interface::alteraMag(int x) {
	char buf[5];
	_itoa(x, buf, 10);
	mag->setText(buf);
}

void Interface::imprimir() {
	gerente->desenhaElemento(rosto);
	gerente->desenhaElemento(v1);
	gerente->desenhaElemento(v2);
	gerente->desenhaElemento(v3);
	gerente->desenhaElemento(v4);
	gerente->desenhaElemento(v5);
	ammo->draw(gerente->getWindow());
	mag->draw(gerente->getWindow());
}

void Interface::atualiza() {
	//I. Corações.

	for (int i = 1; i <= 5; i++) {
		if (i <= j->getVidas()) {
			if (i == 1) v1.setTexture(CorCheio);
			if (i == 2) v2.setTexture(CorCheio);
			if (i == 3) v3.setTexture(CorCheio);
			if (i == 4) v4.setTexture(CorCheio);
			if (i == 5) v5.setTexture(CorCheio);
		}
		else {
			if (i == 1) v1.setTexture(CorVazio);
			if (i == 2) v2.setTexture(CorVazio);
			if (i == 3) v3.setTexture(CorVazio);
			if (i == 4) v4.setTexture(CorVazio);
			if (i == 5) v5.setTexture(CorVazio);
		}
	}


	//II. Munições & Rosto.

	Arma* x = j->getl_arma()->getElX(j->getArmaSel())->getInfo();
	mag->setText("CAR.: "+to_string((int)x->getMagvar()));
	ammo->setText("TOTAL: " + to_string((int)x->getAmmo()));


	//III. Posições

	sf::Vector2f pos = sf::Vector2f(gerente->getCoorView().x - 320, gerente->getCoorView().y - 240);
	rosto.setPosition(pos);
	v1.setPosition(sf::Vector2f(pos.x, pos.y + 68));
	v2.setPosition(sf::Vector2f(pos.x + 18, pos.y + 68));
	v3.setPosition(sf::Vector2f(pos.x + 36, pos.y + 68));
	v4.setPosition(sf::Vector2f(pos.x + 54, pos.y + 68));
	v5.setPosition(sf::Vector2f(pos.x + 72, pos.y + 68));
	ammo->setPosition(sf::Vector2f(pos.x + 68, pos.y));
	mag->setPosition(sf::Vector2f(pos.x + 68, pos.y + 32));
}

void Interface::teste() {
	cout << "Coord. do rosto:\nx = " << rosto.getPosition().x << "\n y = " << rosto.getPosition().y << "\n";
}