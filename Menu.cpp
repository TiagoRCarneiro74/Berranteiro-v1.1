#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "Menu.h"
#include "Resumir.h"
#include "BFase1.h"
#include "BFase2.h"
#include "Salvar.h"
#include "Sair.h"
#include <stdio.h>
#include <vector>
#include <string>
//#include <windows.h>
using namespace std;

Menu::Menu(): titulo(sf::Vector2f(30.0f, 0.0f)), carrega(sf::Vector2f(1000.0f, 1000.0f)), fundo(sf::Vector2f(0.0f, 0.0f)) {
	resumir = NULL;
	bfase1 = NULL;
	bfase2 = NULL;
	salvar = NULL;
	sair = NULL;
	f1 = NULL;
	f2 = NULL;
	pEvent = NULL;
	titulo.getCorpo().setTextureRect(sf::IntRect(0, 0, 578, 79));
	titulo.setTextura("Midia/Imagens/Titulo.png");
	titulo.getCorpo().setTextureRect(sf::IntRect(0, 0, 578, 79));
	titulo.setPos(sf::Vector2f(30.0f, 0.0f));
	titulo.getCorpo().setPosition(30.0f, 0.0f);
	
}

Menu::~Menu() {
	opcoes.~Lista();
	if (f1) delete f1;
	if (f2) delete f2;
	f1 = NULL;
	f2 = NULL;
}

void Menu::setMusica(sf::Music* m) { musica = m; }

void Menu::executar() {
	GerenciadorGrafico::getGerenciadorGrafico()->setView(sf::Vector2f(320.0f, 240.0f));
	GerenciadorGrafico* graf = GerenciadorGrafico::getGerenciadorGrafico();
	resumir->getCorpo().setPosition(800, 80);
	//FILE* fp = fopen("Ranking.txt", "r+");
	while (graf->verifJanelaAberta()) {
		pEvent->executar();
		int tam = graf->getWindow()->getSize().x;
		if (tam == 1360) graf->setView(sf::Vector2f(680.0f, 350.0f));
		else graf->setView(sf::Vector2f(320.0f, 240.0f));
		resumir->atualiza();
		bfase1->atualiza();
		bfase2->atualiza();
		salvar->atualiza();
		sair->atualiza();
		titulo.atualiza();
		if (resumir->getSelecionada() == true && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (getFase()) {
				resumir->executar();
				break;
			}
		}

		else if (bfase1->getSelecionada() == true && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (getFase2()) {
				delete f2;
				f2 = NULL;
			}
			bfase1->executar();
			break;

		}
		else if (bfase2->getSelecionada() == true && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (getFase1()) {
				delete f1;
				f1 = NULL;
			}
			bfase2->executar();
			break;

		}
		else if (salvar->getSelecionada() == true && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			salvar->executar();
			break;
		}

		else if (sair->getSelecionada() == true && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sair->executar();
		}
		GerenciadorGrafico* graf = GerenciadorGrafico::getGerenciadorGrafico();
		//graf->setView(sf::Vector2f(salvar->getPos().x + 160, bfase2->getPos().y));
		//printf("COOREDENADAS DA VIEW: %f, %f.\n", graf->getCoorView().x, graf->getCoorView().y);
		//printf("COOREDENADAS DE BFASE2: %f, %f.\n\n\n\n\n\n\n\n\n\n\n\n\n\n", bfase2->getCorpo().getPosition().x, bfase2->getCorpo().getPosition().y);
		//Sleep(5000);
		graf->getWindow()->setView(*(graf->getView()));
		graf->limpaJanela();
		graf->desenhaElemento(titulo.getCorpo());
		graf->desenhaElemento(resumir->getCorpo());
		graf->desenhaElemento(bfase1->getCorpo());
		graf->desenhaElemento(bfase2->getCorpo());
		graf->desenhaElemento(salvar->getCorpo());
		graf->desenhaElemento(sair->getCorpo());
		graf->mostraElementos();
	}
}

Fase1* Menu::getFase1() { return f1; }

void Menu::setResumir(Resumir* r) { resumir = r; }

void Menu::setBFase1(BFase1* b) { bfase1 = b; }

void Menu::setBFase2(BFase2* b) { bfase2 = b; }

void Menu::setSalvar(Salvar* s) { salvar = s; }

void Menu::setSair(Sair* s) { sair = s; }

void Menu::setFase1(Fase1* f) { f1 = f; }

Fase* Menu::getFase() 
{
	if (f1) return f1;
	else if (f2) return f2;
	else if (f3) return f3;
	else
	{
		f1 = NULL;
		return f1;
	}
}

Fase2* Menu::getFase2() { return f2; }

void Menu::setFase2(Fase2* f) { f2 = f; }

void Menu::setTextbox(Textbox* t) { textbox = t; }

Textbox* Menu::getTextbox() { return textbox; }