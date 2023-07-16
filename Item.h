#pragma once
#include "Entidade.h"
using namespace Entidades;
#include "Jogador.h"
using namespace Personagens;
#include <string>
using namespace std;

class Item : public Entidade {
protected:
	Jogador* j;
	string nome;

public:
	Item(Jogador* jo, float x, float y);
	~Item();
	virtual void pegar();
	void move();
	string getNome() { return nome; }
};
