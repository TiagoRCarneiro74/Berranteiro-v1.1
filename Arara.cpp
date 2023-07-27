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
    if(!textura.loadFromFile("Midia/Imagens/AraraE.png")) std::cout << "Erro na abertura da textura do inimigo." << std::endl;
    else {
        corpo.setTexture(textura);
    }
    corpo.setScale(0.2, 0.2);

    Tdir.loadFromFile("Midia/Imagens/AraraD.png");
    Tesq.loadFromFile("Midia/Imagens/AraraE.png");
    Adir.loadFromFile("Midia/Imagens/AraraAtaqueD.png");
    Aesq.loadFromFile("Midia/Imagens/AraraAtaqueE.png");
}

Arara::~Arara() {}

void Arara::viradoEsq()
{
    corpo.setTexture(Tesq);
    corpo.setTextureRect(sf::IntRect(0, 0, 512, 220));
}
void Arara::viradoDir()
{
    corpo.setTexture(Tdir);
    corpo.setTextureRect(sf::IntRect(0, 0, 512, 220));
}

void Arara::ataqueDir()
{
	corpo.setTexture(Adir);
    corpo.setTextureRect(sf::IntRect(0, 0, 512, 321));
}

void Arara::ataqueEsq()
{
	corpo.setTexture(Aesq);
    corpo.setTextureRect(sf::IntRect(0, 0, 511, 322));
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

    else if((posiJogador.y - pos.y)<0) { vel.y = 0 - v; } 

    else
        vel.y = 0;

}

void Arara::calculaAvanco()
{
    srand(time(NULL));
    aumentaVel = rand()%3;
}