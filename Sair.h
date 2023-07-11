#pragma once
#include "Opcao.h"
#include "Menu.h"

class Sair : public Opcao {
private:
	Menu* pMenu;

public:
	Sair(Menu* m);
	~Sair();
	void atualiza();
	void executar();
};