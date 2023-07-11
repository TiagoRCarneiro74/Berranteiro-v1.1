#include "Inimigo.h"

namespace Entidades
{

    namespace Personagens

    {

        class Arara: public Inimigo
        {
            private:
                int aumentaVel;

            public:
                Arara(Jogador* j1, Jogador* j2, float x, float y);
                ~Arara();
                void ataque(sf::Vector2f posiJogador);
                void viradoEsq();
                void viradoDir();
                void ataqueDir();
                void ataqueEsq();
                void calculaAvanco();

        };

    }

}