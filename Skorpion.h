#pragma once
#include "Item.h"
#include "Jogador.h"
using namespace Personagens;

namespace Itens {

	class Skorpion : public Item {
	public:
		Skorpion(Jogador* jo, float sx, float sy);
		~Skorpion();
		void pegar();
	};
}