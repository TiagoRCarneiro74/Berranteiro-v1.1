#include "Projetil.h"

using namespace Entidades;


Projetil::Projetil(float x, float y):
Entidade(0,sf::Vector2f(x, y), 0)
{
	atirador = NULL;
    direita = false;
	ativado = false;
	alcance = 650;
	distanciaPercorrida = 0;
	setAtacar(false);
    corpo.setTextureRect(sf::IntRect(0,0,62,79));
	if(!textura.loadFromFile("Midia/Imagens/Fogo.png")) std::cout << "Erro na abertura da textura do inimigo." << std::endl;
    	else {
        	corpo.setTexture(textura);
    	}
	corpo.setScale(0.2, 0.2);
}
Projetil::~Projetil()
{
	atirador = NULL;
}
void Projetil::move()
{
	vel.x = 0;
	setAtacar(false);

	if(ativado == true)
	{
		setAtacar(true);
        if(direita==true)
            vel.x = 6;
        else
            vel.x = -6;

		distanciaPercorrida = distanciaPercorrida + 6;
		
		if (distanciaPercorrida < alcance) { setVelY(0); }

        pos.x = pos.x + vel.x;
        pos.y = pos.y + vel.y*2;
		corpo.setPosition(pos.x, pos.y);

	}
	else
	{
		setPos(atirador->getPos());
	}

	if((distanciaPercorrida > alcance && vel.y == 0) && (pos != atirador->getPos()))
	{
		distanciaPercorrida = 0;
		ativado = false;
		setPos(atirador->getPos());
	}
}

void Projetil::setAtivado(bool b)
{
	ativado = b;
}

bool Projetil::getAtivado()
{
	return ativado;
}

void Projetil::setDireita(bool b)
{
    direita = b;
}

void Projetil::setAtirador(Inimigo *i)
{
    atirador = i;
}