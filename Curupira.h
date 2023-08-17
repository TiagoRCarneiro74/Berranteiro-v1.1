#pragma once
#include "Inimigo.h"
#include "ListaEntes.h"
#include "Lista.h"
#include "Projetil.h"
#include "Item.h"
#include "Fase.h"
using namespace Fases;

namespace Entidades
{

	namespace Personagens
	{

		class Curupira: public Inimigo
		{
			private:
				Projetil *fogo;
				bool atirar;
				bool ressucitar;
				bool corre;
				ListaEntes *animais;
				sf::Clock relogio;
				string item;
				Fase* f;
				sf::Clock proj;

			public:
				Curupira(Jogador* j1, Jogador* j2, float x, float y);
				~Curupira();
				void move();
				void viradoEsq();
				void viradoDir();
				void ataqueDir();
				void ataqueEsq();
				void ataque(sf::Vector2f posiJogador);
				void afastar(sf::Vector2f posiJogador);
				void ressucitarAnimais();
				void calculaRessucitar();
				void setLista(ListaEntes *l);
				void setVidas(int x);
				Projetil* getFogo();
				void setItem(string s) { item = s; }
				void setFase(Fase* f0) { f = f0; }
				
		};

	}

}