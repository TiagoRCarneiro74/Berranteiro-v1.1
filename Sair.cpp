#include "Sair.h"

Sair::Sair(Menu* m): Opcao() {
	pMenu = m;
	/*sf::Texture tex;
	tex.loadFromFile("Midia/Imagens/Menu Opc 5.png");
	setTextura(tex);
	setPos(sf::Vector2f(160.0f, 400.0f));
	corpo.setPosition(sf::Vector2f(160.0f, 400.0f));*/
	if (!textura.loadFromFile("Midia/Imagens/Menu Opc 5.png")) cout << "Erro na abertura da imagem";
	setPos(sf::Vector2f(160.0f, 400.0f));
	corpo.setPosition(sf::Vector2f(160.0f, 400.0f));
	cout << "Sair criado.\npos.x = " << getPos().x << "\npos.y = " << getPos().y << endl;

	m->setSair(this);
}

Sair::~Sair() {}

void Sair::atualiza() {
	GerenciadorGrafico* graf = GerenciadorGrafico::getGerenciadorGrafico();
	int tamx = graf->getWindow()->getSize().x;
	int tamy = graf->getWindow()->getSize().y;
	if (tamx == 1360) {
		corpo.setScale(1.45f, 1.45f);
		setPos(448, 0.83333 * tamy);
		corpo.setPosition(448, 0.83333 * tamy);
	}
	else {
		corpo.setScale(1, 1);
		setPos(0.25 * tamx, 0.83333 * tamy);
		corpo.setPosition(0.25 * tamx, 0.83333 * tamy);
	}
	if (sf::Mouse::getPosition().x - graf->getWindow()->getPosition().x >= getPos().x && sf::Mouse::getPosition().y - graf->getWindow()->getPosition().y - 30 >= getPos().y && sf::Mouse::getPosition().x - graf->getWindow()->getPosition().x <= getPos().x + getTam().x && sf::Mouse::getPosition().y - graf->getWindow()->getPosition().y - 30 <= getPos().y + getTam().y) {
		selecionada = true;
		sf::Texture tex;
		tex.loadFromFile("Midia/Imagens/Menu Opc 5-Sel.png");
		setTextura(tex);
	}
	else {
		selecionada = false;
		sf::Texture tex;
		tex.loadFromFile("Midia/Imagens/Menu Opc 5.png");
		setTextura(tex);
	}
}

void Sair::executar() {
	GerenciadorGrafico* graf = GerenciadorGrafico::getGerenciadorGrafico();
	graf->fecharJanela();
	//pMenu->~Menu();
	
}