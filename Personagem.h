
#pragma once
#include "Entidade.h"

namespace Entidades

{

    namespace Personagens
    {

        class Personagem : public Entidade
        {
        protected:
            //int dano;
            bool virado;
            sf::Texture Tesq, Tdir, Adir, Aesq;

        public:
            Personagem(const int v, const int id, float x, float y);
            ~Personagem();
            virtual void move() = 0;
            void verifImg();
            virtual void viradoEsq()=0;
            virtual void viradoDir()=0;
            virtual void ataqueDir()=0;
            virtual void ataqueEsq()=0;
            bool getVirado();


        };

    }

}
