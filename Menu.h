#pragma once
#include "Menu.h"
#include "Lista.h"
#include "Opcao.h"
#include "Fase1.h"
#include "Fase2.h"
#include "Textbox.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
using namespace Fases;

class Resumir;

class BFase1;

class BFase2;

class Salvar;

class Sair;

class Menu {
private:
	Lista<Opcao> opcoes;
	Opcao titulo;
	Ente carrega, fundo;
	sf::Music* musica;
	Fase1* f1;
	Fase2* f2;
	Resumir* resumir;
	BFase1* bfase1;
	BFase2* bfase2;
	Salvar* salvar;
	Sair* sair;
	Textbox* textbox;

public:
	Menu();
	~Menu();
	void executar();
	void setMusica(sf::Music* m);
	void setResumir(Resumir* r);
	void setBFase1(BFase1* b);
	void setBFase2(BFase2* b);
	void setSalvar(Salvar* s);
	void setSair(Sair* s);
	Fase1* getFase1();
	void setFase1(Fase1* f);
	Fase2* getFase2();
	void setFase2(Fase2* f);
	Fase* getFase();
	void setTextbox(Textbox* t);
	Textbox* getTextbox();
};