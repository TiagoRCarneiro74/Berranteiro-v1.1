#include "Map.h"
#include <iostream>

//Map::Map() : tamx(16), tamy(16), qtdx(0), qtdy(0) {}
Map::Map():
Ente(sf::Vector2f(0.0f, 0.0f))
{ 
	tamx = 16; tamy = 16; qtdx = 0; qtdy = 0; incx = 0; incy = 0; 
}

Map::~Map() {}

void Map::inicializa() {}

void Map::load() {
	if (!textura.loadFromFile("Midia/Imagens/Teste Tilemap.png")) {
		std::cout << "Erro na abertura do tilemap." << std::endl;
	}
	else {
		corpo.setTexture(textura);
		corpo.setTextureRect(sf::IntRect(incx, incy, 640, 480));
		//sprite.setScale(2, 2);
		corpo.setPosition(sf::Vector2f(0.0f, 0.0f));
		qtdx = textura.getSize().x / tamx;
		qtdy = textura.getSize().y / tamy;
	}
}

void Map::update(float x, float y) { incx = incx + x; incy = incy + y; corpo.setTextureRect(sf::IntRect(incx, incy, 640, 480)); }
