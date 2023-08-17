#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "Interface.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

Interface::Interface() : Ente(sf::Vector2f(0.0f, 0.0f)) {
	sf::Vector2f pos = sf::Vector2f(gerente->getCoorView().x - gerente->getView()->getSize().x / 2, gerente->getCoorView().y - gerente->getView()->getSize().y / 2);

	TRosto.loadFromFile("Midia/Imagens/Rosto.png");
	rosto.setTextureRect(sf::IntRect(0, 0, 256, 256));
	rosto.setScale(sf::Vector2f(0.25f, 0.25f));
	rosto.setTexture(TRosto);
	rosto.setPosition(pos);

	CorCheio.loadFromFile("Midia/Imagens/CorCheio.png");
	cor.setTexture(CorCheio);
	cor.setTextureRect(sf::IntRect(0, 0, 16, 16));
	cor.setScale(2, 2);
	cor.setPosition(pos.x, pos.y + 68);

	TFrame.loadFromFile("Midia/Imagens/HealthFrame.png");
	frame.setTexture(TFrame);
	frame.setTextureRect(sf::IntRect(0, 0, 76, 13));
	frame.setPosition(pos.x + 36, pos.y + 68);

	HBar.setFillColor(sf::Color::Green);
	HBar.setPosition(pos.x + 36, pos.y + 84);
	HBar.setSize(sf::Vector2f(100, 12));

	mag = new Textbox();
	ammo = new Textbox();
	instrucao = new Textbox();
	f = new sf::Font();
	f->loadFromFile("Midia/Imagens/FSEX300.ttf");
	mag->setFont(f);
	ammo->setFont(f);
	instrucao->setFont(f);

	mag->setText("CAR.: 00");
	ammo->setText("TOTAL: 00");
	instrucao->setText("");
	tref = 0;

	//Arma* x = j->getl_arma()->getElX(j->getArmaSel())->getInfo();
	//mag->setText("CAR.: "+to_string(x->getMagvar()));
	//ammo->setText("TOTAL: "+to_string(x->getAmmo()));
}

Interface::~Interface() {
	delete f;
	delete ammo;
	delete mag;
	delete instrucao;
}

void Interface::alteraAmmo(int x) {
	//char buf[5];
	//itoa(x, buf, 10);
	string s = to_string(x);
	ammo->setText(s);
}

void Interface::alteraMag(int x) {
	//char buf[5];
	//_itoa(x, buf, 10);
	string s = to_string(x);
	mag->setText(s);
}

void Interface::imprimir() {
	gerente->desenhaElemento(rosto);
	gerente->desenhaElemento(cor);
	ammo->draw(gerente->getWindow());
	mag->draw(gerente->getWindow());
	gerente->imprimeRet(HBar);
	gerente->desenhaElemento(frame);
	instrucao->draw(gerente->getWindow());
}

void Interface::setInstrucao(string s) {
	instrucao->setText("> " + s);
	tref = clock.getElapsedTime().asSeconds();
}

void Interface::atualiza() {
	//I. Health Bar.

	/*for (int i = 1; i <= 5; i++) {
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
	}*/

	float f = (j->getVidas() / (float)j->getMaxVidas()) * 100;
	HBar.setSize(sf::Vector2f(f, 12));


	//II. Munições & Rosto.

	Arma* x = j->getl_arma()->getElX(j->getArmaSel())->getInfo();
	x->verifReload();
	mag->setText("CAR.: "+to_string((int)x->getMagvar()));
	ammo->setText("TOTAL: " + to_string((int)x->getAmmo()));


	//III. Posições

	sf::Vector2f pos = sf::Vector2f(gerente->getCoorView().x - gerente->getView()->getSize().x / 2, gerente->getCoorView().y - gerente->getView()->getSize().y / 2);
	rosto.setPosition(pos);
	cor.setPosition(sf::Vector2f(pos.x, pos.y + 68));
	ammo->setPosition(sf::Vector2f(pos.x + 68, pos.y));
	mag->setPosition(sf::Vector2f(pos.x + 68, pos.y + 32));
	HBar.setPosition(pos.x + 36, pos.y + 84);
	frame.setPosition(pos.x + 36, pos.y + 68);
	instrucao->setPosition(sf::Vector2f(pos.x + 250, pos.y));


	//IV. Instrução
	if (clock.getElapsedTime().asSeconds() - tref > 3) instrucao->setText("");

}

void Interface::teste() {
	cout << "Coord. do rosto:\nx = " << rosto.getPosition().x << "\n y = " << rosto.getPosition().y << "\n";
}