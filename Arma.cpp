#include "Arma.h"
#include <iostream>

Arma::Arma(string n) {
	t0 = 0;
	tr = 0;
	nome = n;
	//inimigo = i;
	e = new sf::SoundBuffer();
	s = new sf::SoundBuffer();
	d = new sf::SoundBuffer();
	r = new sf::SoundBuffer();
	r->loadFromFile("Midia/Musicas/Load Gun.wav");
	r0.setBuffer(*r);
	d->loadFromFile("Midia/Musicas/dryfire1.wav");
	if (nome == "zero") {
		cad = 1;
		rec = 0;
		dano = 10;
		hitscan = 0;
		mag = -1;
		
		Tesq.loadFromFile("Midia/Imagens/J1Esquerda.png");
		Tdir.loadFromFile("Midia/Imagens/J1Direita.png");
		Adir.loadFromFile("Midia/Imagens/J1AtaqueDireita.png");
		Aesq.loadFromFile("Midia/Imagens/J1AtaqueEsquerda.png");
		
	}
	else if (nome == "skorpion" || nome == "skorpion-s") {
		cad = 10;
		dano = 20;
		rec = 1.25;
		alc = 640;
		hitscan = 1;
		mag = 30;
		magvar = 30;
		ammo = 180;
		if(nome == "skorpion")
		{
			Tesq.loadFromFile("Midia/Imagens/Skorpion-E.png");
			Tdir.loadFromFile("Midia/Imagens/Skorpion-D.png");
			Aesq.loadFromFile("Midia/Imagens/Skorpion-AE.png");
			Adir.loadFromFile("Midia/Imagens/Skorpion-AD.png");
		}
		else
		{
			mag = 180;
			magvar = 180;
		}
		if (!s->loadFromFile("Midia/Musicas/sbarrel1.ogg")) std::cout << "ERRO.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nERRO.\n";
		e->loadFromFile("Midia/Musicas/Load Gun.wav");
	}
	else if (nome == "pistola") {
		cad = 5;
		dano = 10;
		rec = 0.75;
		alc = 480;
		hitscan = 1;
		mag = 12;
		magvar = 12;
		ammo = 240;

		Tesq.loadFromFile("Midia/Imagens/Pistola-E.png");
		Tdir.loadFromFile("Midia/Imagens/Pistola-D.png");
		Aesq.loadFromFile("Midia/Imagens/Pistola-AE.png");
		Adir.loadFromFile("Midia/Imagens/Pistola-AD.png");
		
		s->loadFromFile("Midia/Musicas/Pistol.wav");
		e->loadFromFile("Midia/Musicas/Load Gun.wav");
	}
	else if (nome == "mp5" || nome == "mp5-s") {
		cad = 18;
		dano = 8;
		rec = 1;
		alc = 560;
		hitscan = 1;
		mag = 32;
		magvar = 32;
		ammo = 320;
		if(nome == "mp5")
		{
			Tesq.loadFromFile("Midia/Imagens/MP5-E.png");
			Tdir.loadFromFile("Midia/Imagens/MP5-D.png");
			Aesq.loadFromFile("Midia/Imagens/MP5-AE.png");
			Adir.loadFromFile("Midia/Imagens/MP5-AD.png");
		}
		else
		{
			mag = 320;
			magvar = 320;
		}
		s->loadFromFile("Midia/Musicas/MP5.wav");
		e->loadFromFile("Midia/Musicas/Load Gun.wav");
	}
}

Arma::~Arma() {
	delete s;
	delete e;
	delete d;
	delete r;
}

sf::Texture* Arma::getTdir() { return &Tdir; }

sf::Texture* Arma::getTesq() { return &Tesq; }

sf::Texture* Arma::getAdir() { return &Adir; }

sf::Texture* Arma::getAesq() { return &Aesq; }

void Arma::recarregar() {
	if (ammo > 0) {
		r0.play();
		tr = clock();
		recarregando = 1;
	}
}

void Arma::verifReload() {
	clock_t at = clock();
	if (at / (float)CLOCKS_PER_SEC - tr / (float)CLOCKS_PER_SEC >= rec && recarregando == 1) {
		magvar = mag;
		dry = 0;
		recarregando = 0;
	}
	else if (recarregando == 1) dry = 1;
}