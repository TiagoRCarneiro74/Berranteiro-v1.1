#include "Jogador.h"
#include "Inimigo.h"
#include "Obstaculo.h"
#include <windows.h>
#include <iostream>
#include <cmath>

using namespace Entidades;
using namespace Personagens;

int Jogador::segueJogador = 1;

Jogador::Jogador(const int j): Personagem(100, 101, 50, 50), jogador(j){
	pMapa2 = NULL;
	verifTempo = true;
	maxVidas = 100;
	pontos = 0;
	l_arma = new Lista<Arma>();

	if(j==1)
	{
		corpo.setTextureRect(sf::IntRect(0, 0, 288, 370));
		if(!textura.loadFromFile("Midia/Imagens/J1Direita.png")) std::cout << "Erro na abertura da textura do jogador." << std::endl;
	}
	else
	{
		corpo.setTextureRect(sf::IntRect(0, 0, 289, 371));
		if(!textura.loadFromFile("Midia/Imagens/J2Direita.png")) std::cout << "Erro na abertura da textura do jogador." << std::endl;
		setVidas(0);
	}
	corpo.setScale(sf::Vector2f(0.2f, 0.2f));
	Arma* zero = new Arma("zero");
	l_arma->incluirEl(zero);
	arma_sel = 1;
	Arma* Pistola = new Arma("pistola");
	l_arma->incluirEl(Pistola);
	Arma* Skorpion = new Arma("mp5");
	l_arma->incluirEl(Skorpion);
}

Jogador::~Jogador() {
	delete l_arma;
}

void Jogador::move() 
{
	//std::cout << "Nova pos.x: " << pos.x << std::endl;
	//std::cout << "vel.y = " << vel.y << std::endl;
	//std::cout << "pos.y = " << pos.y << std::endl;
	
	if((jogador==1 && segueJogador==1)||(jogador==2 && segueJogador==2))
		atualizaPos();

	pos.x = pos.x + vel.x;
	pos.y = pos.y + vel.y;
	corpo.setPosition(pos.x, pos.y);

	verifImg();

	if (atirando == 1) atirar();
}

void Jogador::atualizaPos() {
	//if (pos.x < 640 && pos.x > 0) {
	//}

	//if (pos.y < 430 && pos.y > 0) pos.y = pos.y + vel.y;
	if (gerente->getCoorView().x >= 320 && (pos.x <= gerente->getCoorView().x - 40 && vel.x<0) ||
	(gerente->getCoorView().x + vel.x <= pMapa2->getLista()->getElX(pMapa2->getLista()->getTam())->getInfo()->getPos().x && pos.x >= gerente->getCoorView().x + 40 && vel.x>0)) {
			
		if (numVidas > 0) gerente->setView(sf::Vector2f(gerente->getCoorView().x + vel.x, gerente->getCoorView().y));
	}
		//else
		//{
		//}
	if ((pos.y >= gerente->getCoorView().y + 240 - getTam().y - 90 && vel.y > 0) || (pos.y <= gerente->getCoorView().y - 150 && vel.y < 0)) {

		if (numVidas > 0) gerente->setView(sf::Vector2f(gerente->getCoorView().x, gerente->getCoorView().y + vel.y));

	}
	gerente->getWindow()->setView(*(gerente->getView()));
	
}

void Jogador::parar() {
	vel.x = 0;
}

void Jogador::pular() { vel.y = -10; }


void Jogador::viradoDir()
{
	if(jogador==1)
	{
		
		if (arma_sel == 1) {
			corpo.setTextureRect(sf::IntRect(0, 0, 288, 370));
			textura.loadFromFile("Midia/Imagens/J1Direita.png");
		}
		else {
			corpo.setTextureRect(sf::IntRect(0, 0, l_arma->getElX(arma_sel)->getInfo()->getTdir()->getSize().x, 370));
			this->setTextura(*((l_arma->getElX(arma_sel)->getInfo())->getTdir()));
		}
	}
	else
	{
		corpo.setTextureRect(sf::IntRect(0, 0, 289, 371));
		textura.loadFromFile("Midia/Imagens/J2Direita.png");
	}
}
void Jogador::viradoEsq()
{
	if(jogador==1)
	{
		if (arma_sel == 1) {
			corpo.setTextureRect(sf::IntRect(0, 0, 288, 370));
			textura.loadFromFile("Midia/Imagens/J1Esquerda.png");
		}
		else {
			corpo.setTextureRect(sf::IntRect(0, 0, l_arma->getElX(arma_sel)->getInfo()->getTesq()->getSize().x, 370));
			this->setTextura(*((l_arma->getElX(arma_sel)->getInfo())->getTesq()));
		}
	}
	else
	{
		corpo.setTextureRect(sf::IntRect(0, 0, 291, 369));
		textura.loadFromFile("Midia/Imagens/J2Esquerda.png");
	}
}

void Jogador::ataqueDir()
{
	if(jogador==1)
	{
		if (arma_sel == 1) {
			corpo.setTextureRect(sf::IntRect(0, 0, 477, 363));
			textura.loadFromFile("Midia/Imagens/J1AtaqueDireita.png");
		}
		else {
			corpo.setTextureRect(sf::IntRect(0, 0, l_arma->getElX(arma_sel)->getInfo()->getAdir()->getSize().x, 370));
			this->setTextura(*((l_arma->getElX(arma_sel)->getInfo())->getAdir()));
		}
	}
	else
	{
		corpo.setTextureRect(sf::IntRect(0, 0, 480, 369));
		textura.loadFromFile("Midia/Imagens/J2AtaqueDireita.png");
	}
}

void Jogador::ataqueEsq()
{
	if(jogador==1)
	{
		if (arma_sel == 1) {
			corpo.setTextureRect(sf::IntRect(0, 0, 477, 363));
			textura.loadFromFile("Midia/Imagens/J1AtaqueEsquerda.png");
		}
		else {
			corpo.setTextureRect(sf::IntRect(0, 0, l_arma->getElX(arma_sel)->getInfo()->getAesq()->getSize().x, 370));
			this->setTextura(*((l_arma->getElX(arma_sel)->getInfo())->getAesq()));
		}
	}
	else
	{
		corpo.setTextureRect(sf::IntRect(0, 0, 480, 369));
		textura.loadFromFile("Midia/Imagens/J2AtaqueEsquerda.png");
	}
}

void Jogador::colisaoInimigo(Entidade *i)
{

	if(verifTempo==true)
	{
		if(atacar==true)
		{
			i->setVidas(i->getVidas()-10);
			if (i->getVivo() == false) pontos += 100;
		}
		else if(i->getAtacar()==true)
		{
			numVidas -= static_cast <Inimigo*> (i)->getDano();
			if(getVidas()==0)
			{
				if(jogador==1 && segueJogador==1)
					setSegue(2);
				else if(jogador==2 && segueJogador==2)
					setSegue(1);
			}
		}
		verifTempo = false;
	}

	float dt = tempoDano.getElapsedTime().asSeconds();
	if(dt>=3)
	{
		verifTempo = true;
		tempoDano.restart();
	}
}

int Jogador::colisaoMapaObs(Entidade *hbx)
{
	bool flag = 0;
	if (trunc(getPos().x + getTam().x) <= hbx->getPos().x + 16 && getPos().y >= hbx->getPos().y - getTam().y + 8) {
		setPos(sf::Vector2f(hbx->getPos().x - getTam().x, getPos().y));
		//pJogador->setVelY(-0.3f);
		//std::cout << "Colisao com a direita.\n";
		setVelY(getVel().y / 1.1f);
		flag = 1;
	}
	else if (getPos().x - 8 >= hbx->getPos().x + hbx->getTam().x - 16 && getPos().y >= hbx->getPos().y - getTam().y + 8) {
		setPos(sf::Vector2f(hbx->getPos().x + hbx->getTam().x, getPos().y));
		//std::cout << "Colisao com a esquerda.\n";
		//if (pJogador->getVel().y <= 0.6 && pJogador->getVel().y >= 0.2) pJogador->setVelY(-0.3f);
		//else pJogador->setVelY(pJogador->getVel().y / 2.0f);
		setVelY(getVel().y / 1.1f);
		flag = 1;
	}


	else if (trunc(getPos().y + getTam().y) + 8 >= trunc(hbx->getPos().y) && getVel().y >= 0) {
		//std::cout << "Colisao abaixo.\n";
		//int py = pJogador->getPos().y / 32;
		//py = py * 32;
		if (getVel().y > 0) {
			setPos(sf::Vector2f(getPos().x, hbx->getPos().y - 73));
		}
		setVelY(0.0f);
		//pJogador->setPos(sf::Vector2f(pJogador->getPos().x, trunc(hbx->getPos().y - pJogador->getTam().y)));
		flag = 1;
	}
	else if (getPos().y >= hbx->getPos().y + hbx->getTam().y - 16) {
		//std::cout << "Colisao acima.\n";
		setVelY(-getVel().y);
		setPos(getPos().x, hbx->getPos().y + hbx->getTam().y);
	}
	
	if(verifTempo==true && hbx->getAtacar()==true)
	{
		//operator--();
		numVidas -= static_cast <Obstaculo*> (hbx)->getDano();
		verifTempo = false;
	}

	float dt = tempoDano.getElapsedTime().asSeconds();
	if(dt>=3)
	{
		verifTempo = true;
		tempoDano.restart();
	}

	return flag;
}

int Jogador::getPontos() { return pontos; }

void Jogador::setSegue(int i)
{
	segueJogador = i;
}

int Jogador::getSegue()
{
	return segueJogador;
}

void Jogador::setArmaSel(int x) { arma_sel = x; }

int Jogador::getArmaSel() { return arma_sel; }

Lista<Arma>* Jogador::getl_arma() { return l_arma; }

void Jogador::setl_ini(ListaEntes* i) { ini = i; }

Ente* Jogador::hitscan(Ente* e) {
	if (virado == 0) {
		if (((e->getPos().y <= this->getPos().y + 40 && e->getPos().y + e->getTam().y >= this->getPos().y + 40) || e->getPos().y <= this->getPos().y + 60 && e->getPos().y + e->getTam().y > this->getPos().y + 60) && (e->getPos().x + e->getTam().x > this->getPos().x + this->getTam().x - 10) && e->getPos().x < this->getPos().x + this->getTam().x + l_arma->getElX(arma_sel)->getInfo()->getAlc()) return e;
	}
	else if (virado == 1) {
		if (((e->getPos().y <= this->getPos().y + 40 && e->getPos().y + e->getTam().y >= this->getPos().y + 40) || e->getPos().y <= this->getPos().y + 60 && e->getPos().y + e->getTam().y > this->getPos().y + 60) && (e->getPos().x < this->getPos().x - 10) && e->getPos().x + e->getTam().x > this->getPos().x - l_arma->getElX(arma_sel)->getInfo()->getAlc()) return e;
	}
	return NULL;
}

void Jogador::atirar() {
	if (arma_sel == 1) return;

	clock_t t1 = clock();
	Arma* x = l_arma->getElX(arma_sel)->getInfo();
	if (t1 / (float)CLOCKS_PER_SEC - x->getTR() / (float)CLOCKS_PER_SEC > x->getRec() && x->getRecarregando() == 1) {
		x->setDry(0);
		x->setMagvar(x->getMag());
		x->setRecarregando(0);
	}
	else if (x->getRecarregando() == 1) x->setDry(1);
	if (x->getDry() == 1) {
		s1.setBuffer(*(x->getSomDry()));
		s1.play();
		return;
	}
	if (t1 / (float) CLOCKS_PER_SEC - x->getClock() / (float) CLOCKS_PER_SEC < 1.0 / x->getCad()) {
		if (virado == 0) this->setTextura(*(x->getTdir()));
		else this->setTextura(*(x->getTesq()));
		return;
	}
	std::cout << t1 / (float) CLOCKS_PER_SEC << " - " << x->getClock() / (float) CLOCKS_PER_SEC << " = " << t1 / (float) CLOCKS_PER_SEC - x->getClock() / (float) CLOCKS_PER_SEC << "\n";
	x->setClock(t1);
	s1.setBuffer(*(x->getSom()));
	s1.play();
	Ente* e = NULL, *e1 = NULL;
	int cont = 1, min=99999999999;
	while (ini->getLista()->getTam() >= cont) {
		e = hitscan(ini->getLista()->getElX(cont)->getInfo());
		if (e != NULL) if (static_cast <Inimigo*> (e)->getVivo() == false) {
			e = NULL;
			cont++;
			continue;
		}
		if (e != NULL) if (fabs(e->getPos().x - this->getPos().x) < min) {
			min = e->getPos().x - this->getPos().x;
			e1 = e;
		}
		//std::cout << e->getPos().x << "\ne.y = " << e->getPos().y << "\nj.x = " << this->getPos().x << "\nj.y = " << this->getPos().y << "\n";
		//Sleep(1000);
		cont++;
	}
	e = e1;
	if (e == NULL) {
		std::cout << "e == NULL.\n" ;
	}
	else std::cout << "e != NULL.\n";
	//Sleep(1000);
	x->setMagvar(x->getMagvar() - 1);
	x->setAmmo(x->getAmmo() - 1);
	if (e == NULL) return;
	//std::cout << "ATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\n";

	static_cast <Inimigo*> (e)->setVidas(static_cast <Inimigo*> (e)->getVidas() - l_arma->getElX(arma_sel)->getInfo()->getDano());
}