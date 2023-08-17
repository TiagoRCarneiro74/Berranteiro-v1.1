#pragma once
#include "Item.h"
#include "Jogador.h"
#include "Fase.h"
using namespace Personagens;
using namespace Fases;

namespace Itens {

	class Chave : public Item {
	private:
		string* s;
		Fase* f;

	public:
		Chave(Jogador* jo, float sx, float sy);
		~Chave();
		void setString(string s0);
		void setVidas(int n);
		void pegar();
		void setFase(Fase* f0) { f = f0; }
	};
}