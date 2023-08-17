#pragma once
#include "Fase.h"
#include "Curupira.h"
#include "SFML/Audio.hpp"

namespace Fases
{

    class Fase3 : public Fase
    {
    private:
        sf::Music* f1;

    public:
        Fase3();
        Fase3(GerenciadorColisao* c, GerenciadorGrafico* g, GerenciadorEvento* e);
        ~Fase3();
        void executar();
        void geraInimigos();
        void geraObstaculos();
        void geraTrepadeira(float x, float y);
        void geraItens();
        Curupira* geraCurupira(float x, float y);
        sf::Music* getMusica();
    };

}