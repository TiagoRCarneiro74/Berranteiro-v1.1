#pragma once
#include "Entidade.h"
#include "Inimigo.h"

using namespace Personagens;

namespace Entidades
{

	class Projetil: public Entidade
	{
		private:
			float distanciaPercorrida;
			float alcance;
			bool direita;
			bool ativado;
			Inimigo *atirador;

		public:
			Projetil(float x, float y);
			~Projetil();
			void move();
			void setAtivado(bool b);
			bool getAtivado();
			void setDireita(bool b);
			void setAtirador(Inimigo *i);
	};

}