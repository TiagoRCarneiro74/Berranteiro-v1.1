#pragma once
#include "Inimigo.h"
#include "ListaEntes.h"
#include "Lista.h"
#include "Projetil.h"

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
				Projetil* getFogo();
				
		};

	}

}