#pragma once
#include "Item.h"
#include "Jogador.h"
#include "Fase.h"
using namespace Personagens;
using namespace Fases;

namespace Itens {

	class MunicaoMP5 : public Item {
	private:
		Fase* f;
		int valor;

	public:
		MunicaoMP5(Jogador* jo, float sx, float sy);
		~MunicaoMP5();
		void pegar();
		void setFase(Fase* f0) { f = f0; }
		void setValor(int x) { valor = x; }
	};
}