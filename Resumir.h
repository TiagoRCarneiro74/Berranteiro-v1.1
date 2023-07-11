#pragma once
#include "Opcao.h"
#include "Menu.h"

class Resumir : public Opcao {
private:
	Menu* pMenu;

public:
	Resumir(Menu* m);
	~Resumir();
	void executar();
	void atualiza();
};