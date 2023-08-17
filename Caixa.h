#pragma once
#include "Obstaculo.h"
#include "SFML/Audio.hpp"
#include "Item.h"
#include "Skorpion.h"
#include "MP5.h"
#include "Pistola.h"
#include "MedPack.h"
#include "Fase.h"
#include <time.h>
#include <string>
using namespace Itens;
using namespace Fases;



class Caixa : public Item {
private:
	sf::Sound s;
	sf::SoundBuffer sb;
	//Item* i1, * i2;
	string i1, i2;
	Fase* f;

public:
	Caixa(Jogador* j, float sx, float sy);
	~Caixa();
	void pegar();
	void findar();
	void setI1(string s);
	void setI2(string s);
	string getI1();
	string getI2();
	void setFase(Fase* k);
};
