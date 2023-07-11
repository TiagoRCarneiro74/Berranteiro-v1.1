#pragma once
#include "Opcao.h"
#include "Menu.h"

class Salvar : public Opcao {
private:
	Menu* pMenu;

public:
	Salvar(Menu* m);
	~Salvar();
	void executar();
	void atualiza();
};
