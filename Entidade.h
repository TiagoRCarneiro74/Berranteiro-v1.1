#pragma once
#include <SFML/Graphics.hpp>
#include "Ente.h"

namespace Entidades
{

	class Entidade: public Ente{
	protected:
		sf::Vector2f vel;
		bool vivo;
		bool atacar;
		bool obstaculo;
		int numVidas;

	public:
		Entidade(const int v, sf::Vector2f xy, int i);
		~Entidade();
		virtual void move() = 0;
		void cair();
		sf::Vector2f getVel() { return vel; };
		int getVidas(){ return numVidas; }
		void setVelX(float x);
		void setVelY(float y);
		bool getAtacar();
		void setAtacar(bool a);
		bool getVivo();
		void setVivo(bool v);
		void operator++();
		void operator--();
		void repos(float x, float y) { pos.x = pos.x + x; pos.y = pos.y + y; corpo.setPosition(pos.x, pos.y); }
		void setVidas(int n);
		bool getObstaculo();
	};

}