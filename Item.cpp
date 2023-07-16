#include "Item.h"

Item::Item(Jogador* jo, float x, float y) : Entidade(100, sf::Vector2f(0.0f, 0.0f), 701) {
	j = jo;
	this->setPos(x, y);
	nome = "\n";
	item = true;
}

Item::~Item() {}

void Item::pegar() {}

void Item::move() {
	pos.x = pos.x + vel.x;
	pos.y = pos.y + vel.y;
	corpo.setPosition(pos.x, pos.y);
}