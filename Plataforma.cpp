#include "Plataforma.h"
#include <time.h>
#include <iostream>

using namespace Entidades;

sf::Image Plataforma::teste = loadAlt("Midia/Imagens/Teste Tilemap2.png");

Plataforma::Plataforma(sf::Vector2f* coor) : Entidade(0, *coor, 132){
	/*if (!textura.loadFromImage(teste, sf::IntRect(coor.x / 2.0, coor.y / 2.0, 16, 16))) std::cout << "Erro no carregamento da textura da plataforma.\n";
	sf::Color color1 = teste.getPixel(coor.x/2.0f, coor.y/2.0f);
	sf::Color color2 = teste.getPixel(coor.x / 2.0f + 15.0f, coor.y / 2.0f + 15.0f);
	sf::Color color3 = teste.getPixel(coor.x / 2.0f + 7.0f, coor.y / 2.0f + 7.0f);
	if (color1 == sf::Color::Transparent && color2 == sf::Color::Transparent) {
		//std::cout << "Plataforma com textura vazia. Destruindo-a...\n" << std::endl;
		nula = true;
		//Plataforma::~Plataforma();
	}
	
	else {
		//corpo.setTexture(textura);
		corpo.setScale(2, 2);
		corpo.setTextureRect(sf::IntRect(0, 0, 16, 16));
	}
	corpo.setPosition(coor.x, coor.y);
	pos = coor;*/
	sf::Color color1 = teste.getPixel(coor->x / 2.0f, coor->y / 2.0f);
	sf::Color color2 = teste.getPixel(coor->x / 2.0f + 15.0f, coor->y / 2.0f + 15.0f);
	sf::Color color3 = teste.getPixel(coor->x / 2.0f + 7.0f, coor->y / 2.0f + 7.0f);
	if (color1 == sf::Color::Transparent && color2 == sf::Color::Transparent && color3 == sf::Color::Transparent) {
		nula = true;
	}

	float f = 0;
	int qtd = 0;
	bool flag = 0;
	for (f = coor->x; f < teste.getSize().x * 2; f = f + 32) {
		sf::Color color1 = teste.getPixel(f / 2.0f, coor->y / 2.0f);
		sf::Color color2 = teste.getPixel(f / 2.0f + 15.0f, coor->y / 2.0f + 15.0f);
		sf::Color color3 = teste.getPixel(f / 2.0f + 7.0f, coor->y / 2.0f + 7.0f);
		if (color1 == sf::Color::Transparent && color2 == sf::Color::Transparent && color3 == sf::Color::Transparent) {
			flag = 1;
			//if (qtd == 0) std::cout << "Não ha plataforma.\n";
			//else std::cout << "Fim do bloco de plataformas. qtd = " << qtd << ".\n";
			break;
		}
		else {
			qtd++;
		}
	}

	if (qtd > 0) {
		if (!textura.loadFromImage(teste, sf::IntRect(coor->x / 2.0, coor->y / 2.0, 16 * qtd, 16))) std::cout << "Erro no carregamento da textura da plataforma.\n";
		corpo.setScale(2, 2);
		corpo.setTextureRect(sf::IntRect(0, 0, 16 * qtd, 16));
		coor->x = f;
	}
	else if (flag == 1) coor->x += 32;
	else coor->x += 9999999999;
}

Plataforma::~Plataforma() {
	gerente = NULL;
	pos = sf::Vector2f(-1.0f, -1.0f);
}

const bool Plataforma::getNula() { return nula; }

void Plataforma::setImagem(sf::Image i) { teste = i; }

sf::Image Plataforma::loadAlt(const string s) {
	sf::Image i;
	i.loadFromFile(s);
	return i;
}

const bool Plataforma::verifNula(sf::Vector2f coor) {
	//std::cout << "VerifNula inicializado.\n";
	sf::Color color = teste.getPixel(coor.x / 2.0f, coor.y / 2.0f);
	sf::Color color2 = teste.getPixel(coor.x / 2.0f + 15.0f, coor.y / 2.0f + 15.0f);
	if (color == sf::Color::Transparent && color2 == sf::Color::Transparent) {
		//std::cout << "VerifNula finalizado.\n";
		return true;
	}
	else {
		//std::cout << "VerifNula finalizado.\n";
		return false;
	}
}

void Plataforma::move() {
	cair();
	setVelY(getVel().y - (300 / CLOCKS_PER_SEC));
}