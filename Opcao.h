#pragma once
#include "Ente.h"
#include "SFML/Graphics.hpp"
#include "GerenciadorGrafico.h"

class Opcao : public Ente {
protected:
	bool selecionada;

public: 
	Opcao();
	Opcao(sf::Vector2f ini);
	~Opcao();
	void setSelecionada(bool sel);
	const bool getSelecionada();
	virtual void atualiza();
	virtual void executar();
};