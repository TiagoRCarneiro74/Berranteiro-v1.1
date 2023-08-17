#include "Obstaculo.h"

using namespace Entidades;

Obstaculo::Obstaculo(float x, float y) : Entidade(3, sf::Vector2f(x, y), 0) {
	danoso = false;
	atacar = danoso;
	obstaculo = true;
	colidivel = true;
}

Obstaculo::~Obstaculo() {}

void Obstaculo::move() { 
	//cair();
	GerenciadorGrafico* graf = GerenciadorGrafico::getGerenciadorGrafico();
	if (pos.x > graf->getCoorView().x + 320 || pos.x < graf->getCoorView().x - 320 || pos.y > graf->getCoorView().y + 240 || pos.y < graf->getCoorView().y - 240) {
        setVelX(0.0f);
		setVelY(-0.3f);
		cair();
    }
	else
	{
		pos.y += 4*vel.y;
		corpo.setPosition(pos.x, pos.y);
	}
}