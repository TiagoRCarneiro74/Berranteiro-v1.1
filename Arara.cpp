#include "Arara.h"

using namespace Entidades;
using namespace Personagens;

Arara::Arara(Jogador* j1, Jogador* j2, float x, float y) :
Inimigo(j1, j2, x, y)
{
    dano = 15;
    numVidas = 30;
    aumentaVel = 0;
    ataqueDistancia = false;
    voa = true;

    corpo.setTextureRect(sf::IntRect(0, 0, 512, 220));
    if(!textura.loadFromFile("Midia/Imagens/Arara.png")) std::cout << "Erro na abertura da textura do inimigo." << std::endl;
    else {
        corpo.setTexture(textura);
    }
    corpo.setScale(0.2, 0.2);
}

Arara::~Arara() {}

void Arara::viradoEsq()
{
    textura.loadFromFile("Midia/Imagens/Arara2.png");
    corpo.setTextureRect(sf::IntRect(0, 0, 512, 225));  
}
void Arara::viradoDir()
{
    textura.loadFromFile("Midia/Imagens/Arara.png");
    corpo.setTextureRect(sf::IntRect(0, 0, 512, 220));
}

void Arara::ataqueDir()
{
	textura.loadFromFile("Midia/Imagens/AraraAtaque2.png");
    corpo.setTextureRect(sf::IntRect(0, 0, 512, 321));
}

void Arara::ataqueEsq()
{
	textura.loadFromFile("Midia/Imagens/AraraAtaque1.png");
    corpo.setTextureRect(sf::IntRect(0, 0, 512, 322));
}

void Arara::ataque(sf::Vector2f posiJogador)
{
    int verif, v = 4;

    vel.x = 0.0;

    srand(time(NULL));
    verif = rand()%2;
    
    if(verif==2)
    {
        calculaAvanco();
        v = v + aumentaVel;
    }

    if((posiJogador.x - pos.x)<0) {  vel.x = vel.x - v; }

    else if((posiJogador.x - pos.x)>0) { vel.x = vel.x + v; }

    if((posiJogador.y - pos.y)>0) { vel.y = v; }

    else if((posiJogador.y - pos.y)<=0) { vel.y = 0; } 

}

void Arara::calculaAvanco()
{
    srand(time(NULL));
    aumentaVel = rand()%3;
}