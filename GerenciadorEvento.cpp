#include "GerenciadorEvento.h"


using namespace Gerenciadores;

GerenciadorEvento* GerenciadorEvento::pEvento = NULL;

GerenciadorEvento::GerenciadorEvento() {
	pJogador1 = NULL;
	pJogador2 = NULL;
	tecla2 = false;
	//pMenu = NULL;
}

GerenciadorEvento::~GerenciadorEvento() {
	delete pEvento;
}

GerenciadorEvento* GerenciadorEvento::getGerenciadorEvento() {
	if (pEvento == NULL) {
		pEvento = new GerenciadorEvento();
	}
	return pEvento;
}

void GerenciadorEvento::setPGraf(GerenciadorGrafico* p) { pGraf = p; }

void GerenciadorEvento::setJogador1(Jogador* p) { pJogador1 = p; }

void GerenciadorEvento::setJogador2(Jogador* p) 
{ 
	pJogador2 = p;
	tecla2 = false;
}



void GerenciadorEvento::verifTeclaPressionada(sf::Keyboard::Key tecla) 
{
	//------JOGADOR 1------
	if(pJogador1->getVivo()==true)
	{
		if (tecla == sf::Keyboard::A) {
			pJogador1->setVelX(-8.0);
		}
		else if (tecla == sf::Keyboard::D) {
			pJogador1->setVelX(8.0);
		}
		if (tecla == sf::Keyboard::G) {
			pJogador1->setAtacar(true);
			if (pJogador1->getArmaSel() != 1) pJogador1->atirar();
		}
		if (tecla == sf::Keyboard::V) {
			pJogador1->setArmaSel(pJogador1->getArmaSel() + 1);
			int x = pJogador1->getl_arma()->getTam();
			if (pJogador1->getArmaSel() > x) pJogador1->setArmaSel(pJogador1->getArmaSel() - x);
			s.setBuffer(*(pJogador1->getl_arma()->getElX(pJogador1->getArmaSel())->getInfo()->getSomEquip()));
			s.play();
		}
		if (tecla == sf::Keyboard::R) {
			pJogador1->getl_arma()->getElX(pJogador1->getArmaSel())->getInfo()->recarregar();
		}
		if (tecla == sf::Keyboard::Space && pJogador1->getVel().y <= 0.1 && pJogador1->getVel().y >= -0.1) {
			pJogador1->pular();
		}
	}

	//------JOGADOR 2------
	if(pJogador2->getVivo()==true)
	{
		if (tecla == sf::Keyboard::Left) {
			pJogador2->setVelX(-8.0);
		}
		else if (tecla == sf::Keyboard::Right) {
			pJogador2->setVelX(8.0);
		}
		if (tecla == sf::Keyboard::L) {
			pJogador2->setAtacar(true);
		}
		if (tecla == sf::Keyboard::Up && pJogador2->getVel().y <= 0.1 && pJogador2->getVel().y >= -0.1) {
			pJogador2->pular();
		}
	}

	if(tecla == sf::Keyboard::Num2 && tecla2 == false)
	{
		pJogador2->setVidas(3);
		tecla2 = true;
	}

	if (tecla == sf::Keyboard::Escape) {
		pJogador1->setVidas(0);
		pJogador2->setVidas(0);
	}
	
}

void GerenciadorEvento::verifTeclaSolta(sf::Keyboard::Key tecla) {
	if(pJogador1->getVivo()==true)
	{
		if (tecla == sf::Keyboard::A || tecla == sf::Keyboard::D) {
			pJogador1->parar();
		}
		if (tecla == sf::Keyboard::G)
		{
			pJogador1->setAtacar(false);
		}
	}
	if(pJogador2->getVivo()==true)
	{
		if (tecla == sf::Keyboard::Left || tecla == sf::Keyboard::Right) {
			pJogador2->parar();
		}
		if (tecla == sf::Keyboard::L)
		{
			pJogador2->setAtacar(false);
		}
	}
}

void GerenciadorEvento::executar() {
	sf::Event evento;
	while (pGraf->getWindow()->pollEvent(evento)) {
		if (evento.type == sf::Event::KeyPressed) verifTeclaPressionada(evento.key.code);
		else if (evento.type == sf::Event::KeyReleased) verifTeclaSolta(evento.key.code);
		else if (evento.type == sf::Event::Closed) pGraf->fecharJanela();
	}
}

//void GerenciadorEvento::setMenu(Menu* m) { pMenu = m; }