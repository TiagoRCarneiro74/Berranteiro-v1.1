#pragma once
#include "Item.h"
#include "Jogador.h"
#include "Fase.h"
using namespace Fases;
using namespace Personagens;

namespace Itens {

	class MP5 : public Item {
	private:
		Fase* f;
		float ammo, magvar;

	public:
		MP5(Jogador* jo, float sx, float sy);
		~MP5();
		void pegar();
		void setFase(Fase* f0) { f = f0; }
		void setammo(float x) { ammo = x; }
		void setmagvar(float x) { magvar = x; }
	};
}
