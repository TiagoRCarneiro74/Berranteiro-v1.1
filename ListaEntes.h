#pragma once

#include "Entidade.h"
#include "Lista.h"
#include <iostream>

using namespace std;
using namespace Entidades;

namespace Listas
{

	class ListaEntes {
	private:
		Lista<Entidade> lista;

	public:
		ListaEntes();
		~ListaEntes();
		void add(Entidade* x);
		void reposLista(float x, float y);
		void desenhaLista();
		Lista<Entidade>* getLista();
	};

}