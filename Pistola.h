#pragma once
#include "Item.h"
#include "Jogador.h"
using namespace Personagens;

namespace Itens {

	class Pistola : public Item {
	public:
		Pistola(Jogador* jo, float sx, float sy);
		~Pistola();
		void pegar();
	};
}
