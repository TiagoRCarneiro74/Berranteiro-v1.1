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
	sf::Sprite cor, frame;
	sf::RectangleShape HBar;
	sf::Texture TRosto, CorCheio, TFrame;
	Textbox *mag, *ammo, *instrucao;
	sf::Font* f;
	Jogador* j;
	sf::Clock clock;
	float tref;

public:
	Interface();
	~Interface();
	void imprimir();
	void alteraMag(int x);
	void alteraAmmo(int x);
	void atualiza();
	void setJogador(Jogador* jo) { j = jo; }
	void teste();
	void setInstrucao(string s);
};
