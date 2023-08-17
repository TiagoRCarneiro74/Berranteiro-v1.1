#pragma once
#include "Item.h"
#include "Jogador.h"
#include "Fase.h"
using namespace Personagens;
using namespace Fases;

namespace Itens {

	class Skorpion : public Item {
	private:
		Fase* f;
		float ammo, magvar;

	public:
		Skorpion(Jogador* jo, float sx, float sy);
		~Skorpion();
		void pegar();
		void setFase(Fase* f0) { f = f0; }
		void setammo(float x) { ammo = x; }
		void setmagvar(float x) { magvar = x; }
	};
}