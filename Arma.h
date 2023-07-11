#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <string>
using namespace std;

class Arma {
protected:
	clock_t t0, tr;
	//sf::Sprite *Sesq, *Sdir;
	sf::Texture Tesq, Tdir, Adir, Aesq;
	float dano, cad, rec, alc, mag, magvar;
	sf::SoundBuffer* s, *e, *d, *r;
	sf::Sound r0;
	string nome;
	bool hitscan, dry, recarregando;

public:
	Arma(string n);
	~Arma();
	sf::Texture* getTdir();
	sf::Texture* getTesq();
	sf::Texture* getAdir();
	sf::Texture* getAesq();
	//void atirar();
	float getDano() { return dano; };
	float getRec() { return rec; };
	float getCad() { return cad; };
	float getAlc() { return alc; };
	clock_t getClock() { return t0; };
	void setClock(clock_t t) { t0 = t; };
	sf::SoundBuffer* getSom() { return s; };
	sf::SoundBuffer* getSomEquip() { return e; };
	bool getHitscan() { return hitscan; };
	void setMagvar(float x) { 
		if (x <= 0) dry = 1;
		magvar = x;
	};
	float getMag() { return mag; };
	float getMagvar() { return magvar; };
	void setDry(int x) { dry = x; };
	bool getDry() { return dry; };
	sf::SoundBuffer* getSomDry() { return d; };
	void recarregar();
	clock_t getTR() { return tr; };
	bool getRecarregando() { return recarregando; };
	void setRecarregando(int x) { recarregando = x; };
};
