#pragma once
#include "Item.h"
#include "Jogador.h"
using namespace Personagens;

namespace Itens {

	class MP5 : public Item {
	public:
		MP5(Jogador* jo, float sx, float sy);
		~MP5();
		void pegar();
	};
}
