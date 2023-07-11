#pragma once
#include "Entidade.h"

namespace Entidades

{

	class Obstaculo : public Entidade {
	protected:
		bool danoso;

	public:
		Obstaculo(float x, float y);
		~Obstaculo();
		void move();
	};

}