#pragma once
#include "Item.h"
#include "Jogador.h"
using namespace Personagens;

namespace Itens {

	class Medpack : public Item {
	public:
		Medpack(Jogador* jo, float sx, float sy);
		~Medpack();
		void pegar();
	};
}