#include "Inimigo.h"
#include <iostream>

using namespace Entidades;
using namespace Personagens;

Inimigo::Inimigo(Jogador *j1, Jogador *j2, float x, float y) :
Personagem(20, 103, x, y)
{
    jogador1 = j1;
    jogador2 = j2;
    movAl = rand()%2;
    horaAtaque = true;
}

Inimigo::~Inimigo()
{
    jogador1 = NULL;
    jogador2 = NULL;
}

void Inimigo::move()
{
    GerenciadorGrafico* graf = GerenciadorGrafico::getGerenciadorGrafico();
    if (pos.x > graf->getCoorView().x + 500 || pos.x < graf->getCoorView().x - 500 || pos.y > graf->getCoorView().y + 400 || pos.y < graf->getCoorView().y - 400) {
        congela();
    }
    else {
        sf::Vector2f posiJogador, posiJogador1, posiJogador2;

            if(voa==true)
                setVelY(0);

            posiJogador1 = jogador1->getPos();
            posiJogador2 = jogador2->getPos();

            if ((abs(posiJogador1.x - pos.x) <= abs(posiJogador2.x - pos.x)))
                posiJogador = posiJogador1;
            
            else
                posiJogador = posiJogador2;
            
            if (abs(posiJogador.x - pos.x)<200)
            {
                if(voa==true)
                    ataque(posiJogador);
                else
                {
                    if(abs(posiJogador.y - pos.y)<100)
                    {
                        ataque(posiJogador);
                    }
                }
            }
            else if(abs(posiJogador.x - pos.x)<400 && abs(posiJogador.y - pos.y)<400)
            {
                if(voa==true || abs(posiJogador.y - pos.y)<100)
                    persegueJogador(posiJogador, 0.8);

                atacar = false;
            }
            else
            {
                movimentoAleatorio();
                atacar = false;
            }

            if (abs(posiJogador.x - pos.x)<200) { atacar = true; }

            //cair();

            pos.y = pos.y + vel.y;
            pos.x = pos.x + vel.x;

            corpo.setPosition(pos.x, pos.y);
            verifImg();

            vel.x = 0;

        }
    
}

void Inimigo::persegueJogador(sf::Vector2f posiJogador, float x)
{
    
    vel.x = 0.0;

    if((posiJogador.x - pos.x)<0) {  vel.x = vel.x - x; }

    else if((posiJogador.x - pos.x)>0) { vel.x = vel.x + x; }

    if(voa==true)
    {
        if((posiJogador.y - pos.y)<0)
            vel.y = vel.y - x;
        else if((posiJogador.y - pos.y)>0)
            vel.y = vel.y + x;
        else
            vel.y = 0;
    }
    

}

void Inimigo::movimentoAleatorio()
{
    if(movAl==1)
    {
        vel.x = vel.x + 0.4;
    }
    else
    {
        vel.x = vel.x - 0.4;
    }

    float dt = relogio.getElapsedTime().asSeconds();
    if(dt>=1)
    {
        relogio.restart();
        movAl = rand()%2;
    }

}

void Inimigo::ataque(sf::Vector2f posiJogador)
{
    vel.x = 0.0;

    if((posiJogador.x - pos.x)<0) {  vel.x = vel.x - 1.5; }

    else if((posiJogador.x - pos.x)>0) { vel.x = vel.x + 1.5; }

        
}

void Inimigo::congela() {
    setVelX(0.0f);
    setVelY(-0.3f);
    cair();
}