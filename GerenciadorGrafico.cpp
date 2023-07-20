#include "GerenciadorGrafico.h"

using namespace Gerenciadores;

GerenciadorGrafico* GerenciadorGrafico::pGrafico = NULL;

GerenciadorGrafico::GerenciadorGrafico() {
	window = new sf::RenderWindow(sf::VideoMode(640, 480), "Berranteiro++ v1.1");
	window->setFramerateLimit(60);
	sf::Image im;
	im.loadFromFile("Midia/Imagens/Icon2.png");
	window->setIcon(48, 48, im.getPixelsPtr());
	view.setCenter(sf::Vector2f(320.0f, 240.0f));
	view.setSize(sf::Vector2f(640, 480));
}

GerenciadorGrafico::~GerenciadorGrafico() {
	if (window) {
		delete window;
		window = NULL;
	}
	delete pGrafico;
}

GerenciadorGrafico* GerenciadorGrafico::getGerenciadorGrafico() {
	if (pGrafico == NULL) {
		pGrafico =  new GerenciadorGrafico();
	}
	return pGrafico;
}

sf::RenderWindow* GerenciadorGrafico::getWindow() { return window;  }

void GerenciadorGrafico::limpaJanela() { window->clear(); }

void GerenciadorGrafico::desenhaElemento(sf::Sprite corpo) { window->draw(corpo); }

void GerenciadorGrafico::mostraElementos() { window->display(); }

void GerenciadorGrafico::fecharJanela() { window->close(); }

const bool GerenciadorGrafico::verifJanelaAberta() {
	if (window->isOpen() == 1) return true;
	else return false;
}

sf::Vector2f GerenciadorGrafico::getCoorView() { return view.getCenter(); }

void GerenciadorGrafico::setView(sf::Vector2f coor) { view.setCenter(coor); }

sf::View* GerenciadorGrafico::getView() { return &view; }

void GerenciadorGrafico::imprimeRet(sf::RectangleShape ret) { window->draw(ret); }

void GerenciadorGrafico::imprimeTexto(sf::Text tex) { window->draw(tex); }