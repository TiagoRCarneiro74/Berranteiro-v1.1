#pragma once
#include "Inimigo.h"

namespace Entidades
{

    namespace Personagens
    {

        class Onca: public Inimigo
        {
            private:
                bool agressividade;
            public:
                Onca(Jogador* j1, Jogador* j2, float x, float y);
                ~Onca();
                void viradoEsq();
                void viradoDir();
                void ataqueDir();
                void ataqueEsq();
                void ataque(sf::Vector2f posiJogador);
                void calculaAgressividade();

        };

    }

}