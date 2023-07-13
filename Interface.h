#pragma once
#include "Ente.h"
#include "Textbox.h"
#include "Jogador.h"
using namespace Personagens;
#include <string>
#include <SFML/Graphics.hpp>
#define _CRT_SECURE_NO_WARNINGS

class Interface : public Ente {
private:
	sf::Sprite rosto;
	sf::Sprite v1, v2, v3, v4, v5;
	sf::Texture TRosto, CorCheio, CorVazio;
	Textbox *mag, *ammo;
	sf::Font* f;
	Jogador* j;

public:
	Interface();
	~Interface();
	void imprimir();
	void alteraMag(int x);
	void alteraAmmo(int x);
	void atualiza();
	void setJogador(Jogador* jo) { j = jo; }
	void teste();
};
