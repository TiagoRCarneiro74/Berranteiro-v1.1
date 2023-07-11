#pragma once
#include "Obstaculo.h"

namespace Entidades
{

	class Pedra : public Obstaculo {
	private:
		int massa;

	public:
		Pedra(float x, float y);
		~Pedra();
	};

}