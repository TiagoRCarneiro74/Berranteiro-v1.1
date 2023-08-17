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
	//pos.x = pos.x + vel.x;
	//pos.y = pos.y + vel.y;
	//corpo.setPosition(pos.x, pos.y);

	GerenciadorGrafico* graf = GerenciadorGrafico::getGerenciadorGrafico();
	if (pos.x > graf->getCoorView().x + graf->getView()->getSize().x / 2 || pos.x < graf->getCoorView().x - graf->getView()->getSize().x / 2 || pos.y > graf->getCoorView().y + graf->getView()->getSize().y / 2 || pos.y < graf->getCoorView().y - graf->getView()->getSize().y / 2) {
		setVelX(0.0f);
		setVelY(-0.3f);
		cair();
	}
	else
	{
		pos.y += vel.y;
		corpo.setPosition(pos.x, pos.y);
	}
}

void Item::setSound(sf::SoundBuffer x) { 
	db = x;
	d.setBuffer(db);
};

void Item::findar() {}

void Item::setVidas(int n) {
	numVidas = n;
	if (n <= 0) {
		vivo = false;
		if (d.getBuffer() != NULL) d.play();
		findar();
	}
	else vivo = true;
}