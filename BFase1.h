#pragma once
#include "Opcao.h"
#include "Menu.h"

class BFase1 : public Opcao {
private:
	Menu* pMenu;

public:
	BFase1(Menu* m);
	~BFase1();
	void executar();
	void atualiza();
};