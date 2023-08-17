#pragma once
#include "Inimigo.h"
#include "Arma.h"
#include "Fase.h"

using namespace Fases;
namespace Entidades
{
    namespace Personagens
    {
        class Soldado : public Inimigo
        {
            private:
                //sf::Texture Tesq, Tdir, Adir, Aesq;
                Arma *arma;
                int skin;
                sf::Sound s1;
                bool corre;
                sf::Clock relogio;
                float dt;
                int contador;
                Fase* f;

            public:
                Soldado(Jogador *j1, Jogador *j2, float x, float y, int s);
                ~Soldado();
                void move();
                void viradoEsq();
                void viradoDir();
                void ataqueDir();
                void ataqueEsq();
                void afastar(sf::Vector2f posiJogador);
                void ataque(sf::Vector2f posiJogador);
                void setVidas(int n);
                void setFase(Fase* f0) { f = f0; };

			    //void atirar();
			    Ente* hitscan(Ente* e);
			    //void setAtirando(int x) { atirando = x; };
			    //bool getAtirando() { return atirando; };
        };
    }
}