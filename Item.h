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
	sf::Sound d;
	sf::SoundBuffer db;

public:
	Item(Jogador* jo, float x, float y);
	~Item();
	virtual void pegar();
	void move();
	string getNome() { return nome; }
	void setVidas(int n);
	void setSound(sf::SoundBuffer x);
	virtual void findar();
};
