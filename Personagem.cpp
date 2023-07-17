#include "Personagem.h"

using namespace Entidades;
using namespace Personagens;

Personagem::Personagem(const int v, const int id, float x, float y) : Entidade(v, sf::Vector2f(x, y), id)
{
    //dano = 0;
    virado = 0;
}

Personagem::~Personagem(){}

void Personagem::verifImg()
{
    if(vel.x>0)
    {
        virado = 0;
        if(atacar==true)
        {
            ataqueDir();
        }
        else
        {
            viradoDir();
        }
    }
    else if(vel.x<0)
    {
        virado = 1;
        if(atacar==true)
        {
            ataqueEsq();
        }
        else
        {
            viradoEsq();
        }
    }
    else if (vel.x == 0) {
        if (virado == 1 && atacar == true) ataqueEsq();
        else if (virado == 0 && atacar == true) ataqueDir();
        else if (virado == 1 && atacar == false) viradoEsq();
        else if (virado == 0 && atacar == false) viradoDir();
    }
}

bool Personagem::getVirado() { return virado; }
