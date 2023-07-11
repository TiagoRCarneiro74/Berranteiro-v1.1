#pragma once
#include "Entidade.h"
#include <string>
using namespace std;

namespace Entidades
{

	class Plataforma : public Entidade {
	private:
		static sf::Image teste;
		sf::Image teste2;
		bool nula = false;

	public:
		Plataforma(sf::Vector2f coor);
		~Plataforma();
		void move();
		const bool getNula();
		static void setImagem(sf::Image i);
		static sf::Image loadAlt(const string s);
		const bool verifNula(sf::Vector2f coor);
	};

}
