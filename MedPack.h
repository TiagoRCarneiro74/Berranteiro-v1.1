#pragma once
#include "Item.h"
#include "Jogador.h"
#include "Fase.h"
using namespace Personagens;
using namespace Fases;

namespace Itens {

	class Medpack : public Item {
	private:
		Fase* f;
		int valor;

	public:
		Medpack(Jogador* jo, float sx, float sy);
		~Medpack();
		void pegar();
		void setValor(int f0);
		void setFase(Fase* f0) { f = f0; }
	};
}