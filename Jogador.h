#pragma once
#include "Entidade.h"
#include "Personagem.h"
#include "Mapa.h"
#include "Arma.h"

namespace Entidades
{

	namespace Personagens
	{

		class Jogador : public Personagem {
		private:
			//sf::Texture Tesq, Tdir, Adir, Aesq;
			Mapa* pMapa2;
			sf::Clock tempoDano;
			bool verifTempo, atirando;
			int pontos;
			const int jogador;
			static int segueJogador;
			Lista<Arma> *l_arma;
			int arma_sel;
			ListaEntes* ini;
			sf::Sound s1;
			int maxVidas;
			Lista<string>* itens;

		public:
			Jogador(const int j);
			~Jogador();
			void move();
			void pular();
			void atualizaPos();
			void parar();
			void setMapa2(Mapa* m2) { pMapa2 = m2; }
			Mapa* getMapa2() { return pMapa2; }
			void viradoDir();
			void viradoEsq();
			void ataqueDir();
			void ataqueEsq();
			void colisaoInimigo(Entidade *i);
			int colisaoMapaObs(Entidade *hbx);
			int getPontos();
			void setSegue(int i);
			int getSegue();
			void setArmaSel(int x);
			int getArmaSel();
			Lista<Arma>* getl_arma();
			void atirar();
			void setl_ini(ListaEntes* i);
			Ente* hitscan(Ente* e);
			void setMaxVidas(int x) { maxVidas = x; };
			int getMaxVidas() { return maxVidas; };
			void setAtirando(int x) { atirando = x; };
			bool getAtirando() { return atirando; };
			Lista<string>* getItens() { return itens; };
			//void setArmaSel(int x) { arma_sel = x; }
			//Municoes getMunicoes() { return municoes; }
			//void setMunMP5(int x) { municoes.mp5 = x; }
			//void setMunSkorpion(int x) { municoes.skorpion = x; }
			//void setMunPistola(int x) { municoes.pistola = x; }
			//Interface* getInterface() { return interf; }
		};

	}

}
