#pragma once
#include "Jogador.h"
#include "GerenciadorGrafico.h"
using namespace Entidades;
using namespace Personagens;

namespace Gerenciadores
{

	class GerenciadorEvento {
	private:
		GerenciadorGrafico* pGraf;
		Jogador* pJogador1;
		Jogador* pJogador2;
		bool tecla2;
		GerenciadorEvento();
		static GerenciadorEvento* pEvento;
		sf::Sound s;
		bool drop;
		//Menu* pMenu;

	public:
		static GerenciadorEvento* getGerenciadorEvento();
		~GerenciadorEvento();
		void setJogador1(Jogador* p);
		void setJogador2(Jogador* p);
		void setPGraf(GerenciadorGrafico* p);
		void verifTeclaPressionada(sf::Keyboard::Key tecla);
		void verifTeclaSolta(sf::Keyboard::Key tecla);
		void executar();
		void verifImpessoais(sf::Keyboard::Key tecla);
		bool getDrop() { return drop; }
		//void setMenu(Menu* m);
	};

}