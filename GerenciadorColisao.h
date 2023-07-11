#pragma once
#include "ListaEntes.h"
#include "Jogador.h"
#include "Mapa.h"
#include <vector>
using namespace Entidades;
using namespace Personagens;

namespace Gerenciadores
{

	class GerenciadorColisao {
	private:
		vector<Jogador*> jogadores;
		ListaEntes* inimigos;
		Mapa* map;


	public:
		GerenciadorColisao(ListaEntes* ini, Mapa* m, Jogador* p1, Jogador* p2);
		GerenciadorColisao();
		~GerenciadorColisao();
		const sf::Vector2f calculaColisaoIni(Ente* e1, Ente* e2);
		const sf::Vector2f calculaColisaoPlat(Ente* e, Plataforma* p);
		void executar();
		void incluirJogador(Jogador *p);
		void setInimigos (ListaEntes *l);
		void setMapa (Mapa *m);
		Ente* hitscan(Jogador* j, Ente* e);
	};

}