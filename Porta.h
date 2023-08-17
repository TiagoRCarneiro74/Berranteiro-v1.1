#pragma once
#include "Obstaculo.h"
#include "Item.h"
#include "Fase.h"
using namespace Fases;

class Porta : public Item {
private:
	string ativ;
	bool aberta;
	Fase* f;

public:
	Porta(Jogador* jo, float sx, float sy);
	~Porta();
	void pegar();
	void setString(string s) { ativ = s; }
	void setVidas(int n);
	string getString() { return ativ; }
	void setFase(Fase* f0) { f = f0; }
};
