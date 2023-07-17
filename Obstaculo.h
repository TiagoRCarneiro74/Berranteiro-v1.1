#pragma once
#include "Entidade.h"

namespace Entidades

{

	class Obstaculo : public Entidade {
	protected:
		int danoso;

	public:
		Obstaculo(float x, float y);
		~Obstaculo();
		void move();
		int getDano() { return danoso; }
	};

}