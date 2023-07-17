#pragma once
#include "Personagem.h"
#include "Jogador.h"

namespace Entidades
{

    namespace Personagens

    {

        class Inimigo : public Personagem
        {
        protected:
            Jogador* jogador1;
            Jogador* jogador2;
            int movAl;
            bool horaAtaque;
            bool ataqueDistancia;
            bool voa;
            sf::Clock relogio;
            float dano;

        public:
            Inimigo(Jogador* j1, Jogador* j2, float x, float y);
            ~Inimigo();
            void move();
            void persegueJogador(sf::Vector2f posiJogador);
            void movimentoAleatorio();
            virtual void ataque(sf::Vector2f posiJogador);
            void congela();
            float getDano() { return dano; };
            void setDano(float x) { dano = x; };
        };

    }

}