#pragma once
#include <iostream>
#include "GerenciadorGrafico.h"
#include "SFML/Graphics.hpp"
#include <string>
using namespace std;
using namespace Gerenciadores;

//class GerenciadorGrafico;
class Ente
{
    protected:
        static GerenciadorGrafico *gerente;
        sf::Vector2f pos;
        sf::Sprite corpo;
        sf::Texture textura;


    public:

        Ente(sf::Vector2f xy);
        ~Ente();
        //virtual void executar() = 0;
        virtual void imprimir();
        sf::Vector2f getPos();
        sf::Sprite getCorpo();
        sf::Texture getTextura() { return textura; }
        void setPos(float x, float y);
        void setPos(sf::Vector2f k);
        static void setGerente(GerenciadorGrafico* g);
        sf::Vector2f getTam();
        static GerenciadorGrafico* getGerente() { return gerente; }
        void setTextura(sf::Texture tx);
        void setTextura(string s);
};