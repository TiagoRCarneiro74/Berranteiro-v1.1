#include "Onca.h"

using namespace Entidades;
using namespace Personagens;

Onca::Onca(Jogador* j1, Jogador* j2, float x, float y) :
Inimigo(j1, j2, x, y)
{
    dano = 25;
    numVidas = 50;
    agressividade = false;
    ataqueDistancia = false;
    voa = false;

    corpo.setTextureRect(sf::IntRect(0, 0, 497, 340));
    if(!textura.loadFromFile("Midia/Imagens/OncaE.png")) std::cout << "Erro na abertura da textura do inimigo." << std::endl;
    else {
        corpo.setTexture(textura);
    }
    corpo.setScale(0.2, 0.2);
    Tdir.loadFromFile("Midia/Imagens/OncaD.png");
    Tesq.loadFromFile("Midia/Imagens/OncaE.png");
    Adir.loadFromFile("Midia/Imagens/OncaAtaqueD.png");
    Aesq.loadFromFile("Midia/Imagens/OncaAtaqueE.png");
}

Onca::~Onca(){}

void Onca::viradoEsq()
{
    corpo.setTexture(Tesq); 
    corpo.setTextureRect(sf::IntRect(0, 0, 497, 340));
}
void Onca::viradoDir()
{
    corpo.setTexture(Tdir);
    corpo.setTextureRect(sf::IntRect(0, 0, 497, 340));
}

void Onca::ataqueDir()
{
	corpo.setTexture(Adir);
    corpo.setTextureRect(sf::IntRect(0, 0, 512, 317));
}

void Onca::ataqueEsq()
{
	corpo.setTexture(Aesq);
    corpo.setTextureRect(sf::IntRect(0, 0, 512, 317));
}

 void Onca::ataque(sf::Vector2f posiJogador)
 {
    int v;

    vel.x = 0.0;

    calculaAgressividade();

    if (agressividade==true) { v = 4; }
    else { v = 1.5; }

    if((posiJogador.x - pos.x)<0) {  vel.x = vel.x - v; }

    else if((posiJogador.x - pos.x)>0) { vel.x = vel.x + v; }

    if(vel.y==0) { vel.y = -4; }
    


    /*float dt = relogio2.getElapsedTime().asSeconds();
    if(dt>=1.0)
    {
        relogio2.restart();
        horaAtaque = false;
    }*/

 }

 void Onca::calculaAgressividade()
 {
    srand(time(NULL));

    int i = rand()%10;

    if(i==3 || i==7)
    {
        agressividade = true;
    }
 }