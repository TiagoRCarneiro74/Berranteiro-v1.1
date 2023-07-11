#pragma once
#include "Opcao.h"
#include "Menu.h"

class BFase2 : public Opcao {
private:
	Menu* pMenu;

public:
	BFase2(Menu* m);
	~BFase2();
	void executar();
	void atualiza();
};