#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Jogador.h"
#include "Inimigo.h"
#include "Onca.h"
#include "GerenciadorGrafico.h"
#include "ListaEntes.h"
#include "Fase1.h"
#include "Fase2.h"
#include "Mapa.h"
#include "GerenciadorEvento.h"
#include "GerenciadorColisao.h"
#include "Menu.h"
#include "Resumir.h"
#include "BFase1.h"
#include "BFase2.h"
#include "Salvar.h"
#include "Sair.h"
#include <time.h>
#include <iostream>
#include <sstream>
#include <list>
using namespace std;
using namespace Entidades;
using namespace Personagens;
using namespace Gerenciadores;

class Jogo {
private:
	Menu* menuopc;
	Jogador* jogador1;
	Jogador* jogador2;
	GerenciadorGrafico *graf;
	GerenciadorEvento *pEvent;
	GerenciadorColisao *pColi;
	Resumir *resumir;
	BFase1 *bfase1;
	BFase2* bfase2;
	Salvar* salvar;
	Sair *sair;

public:
	Jogo();
	~Jogo();
	void executar();

};