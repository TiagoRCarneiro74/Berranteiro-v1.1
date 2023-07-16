#pragma once
#include "Fase.h"
#include "SFML/Audio.hpp"

namespace Fases
{

    class Fase1: public Fase
    {
    private:
        sf::Music* f1;

        public:
            Fase1();
            Fase1(GerenciadorColisao *c, GerenciadorGrafico *g, GerenciadorEvento *e);
            ~Fase1();
            void executar();
            void geraInimigos();
            void geraObstaculos();
            void geraTrepadeira(float x, float y);
            void geraItens();
            sf::Music* getMusica();
    };

}