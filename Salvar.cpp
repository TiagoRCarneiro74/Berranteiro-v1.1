#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "Salvar.h"
#include "Textbox.h"
#include "Jogador.h"
#include <Windows.h>
#include <stdio.h>
#include <string.h>
using namespace std;

Salvar::Salvar(Menu* m) {
	pMenu = m;
	sf::Texture tex;
	tex.loadFromFile("Midia/Imagens/Menu Opc 4.png");
	setTextura(tex);
	setPos(sf::Vector2f(160.0f, 320.0f));
	corpo.setPosition(sf::Vector2f(160.0f, 320.0f));

	m->setSalvar(this);
}

Salvar::~Salvar() {}

void Salvar::atualiza() {
	GerenciadorGrafico* graf = GerenciadorGrafico::getGerenciadorGrafico();
	if (sf::Mouse::getPosition().x - graf->getWindow()->getPosition().x >= getPos().x && sf::Mouse::getPosition().y - graf->getWindow()->getPosition().y - 30 >= getPos().y && sf::Mouse::getPosition().x - graf->getWindow()->getPosition().x <= getPos().x + getTam().x && sf::Mouse::getPosition().y - graf->getWindow()->getPosition().y - 30 <= getPos().y + getTam().y) {
		selecionada = true;
		sf::Texture tex;
		tex.loadFromFile("Midia/Imagens/Menu Opc 4-Sel.png");
		setTextura(tex);
	}
	else {
		selecionada = false;
		sf::Texture tex;
		tex.loadFromFile("Midia/Imagens/Menu Opc 4.png");
		setTextura(tex);
	}
}

void Salvar::executar() {
	FILE* fp = fopen("Ranking.txt", "a+");
	/*printf("Qual o nome do jogador?: ");
	char nome[30];
	scanf("%s", nome);
	//fgets(nome, 30, stdin);
	fputs(nome, fp);
	fputc(',', fp);
	int pon;
	if (pMenu->getFase1()) pon = pMenu->getFase1()->getJogador1()->getPontos();
	else if (pMenu->getFase2()) pon = pMenu->getFase2()->getJogador1()->getPontos();
	char p[5];
	_itoa(pon, p, 10);
	fputs(p, fp);
	fputc('\n', fp);*/
	sf::Font* f = new sf::Font();
	f->loadFromFile("Midia/Imagens/FSEX300.ttf");
	Textbox* intro = new Textbox(24, sf::Color::White, false);
	intro->setText("Digite seu nome: ");
	intro->setPosition(sf::Vector2f(50, 50));
	intro->setFont(f);
	Textbox* t = new Textbox(24, sf::Color::Blue, true);
	t->setFont(f);
	t->setPosition(sf::Vector2f(50, 100));
	Textbox* pontos1 = new Textbox(24, sf::Color::White, false);
	Textbox* pontos2 = new Textbox(24, sf::Color::White, false);
	pontos1->setText("Sua pontuacao e: ");
	char proxy[5];
	if (pMenu->getFase2()) pontos2->setText(_itoa(pMenu->getFase2()->getJogador1()->getPontos(), proxy, 10));
	else if (pMenu->getFase1()) pontos2->setText(_itoa(pMenu->getFase1()->getJogador1()->getPontos(), proxy, 10));
	else pontos2->setText("0");
	pontos1->setFont(f);
	pontos2->setFont(f);
	pontos1->setPosition(sf::Vector2f(50, 150));
	pontos2->setPosition(sf::Vector2f(250, 150));
	Textbox* info = new Textbox(18, sf::Color::White, false);
	info->setText("Pressione Enter para\nsalvar ou Tab para sair.");
	info->setFont(f);
	info->setPosition(sf::Vector2f(50, 200));
	Textbox* ranking = new Textbox(32, sf::Color::White, false);
	ranking->setText("RANKING: ");
	ranking->setPosition(sf::Vector2f(330, 50));
	ranking->setFont(f);
	FILE* fp2 = fopen("Ranking.txt", "r+");
	Lista<Textbox>* colocados = new Lista<Textbox>();







	int cont = 0;

	char** nomes;
	nomes = (char**)malloc(sizeof(char*) * 50);
	vector<int> pontos;
	char line[35], * token;
	token = (char*)malloc(sizeof(char) * 30);
	cont = 0;
	while (fgets(line, sizeof(line), fp)) {
		token = strtok(line, ",");
		nomes[cont] = (char*)malloc(sizeof(char) * 30);
		//nomes[cont] = *(token);
		strcpy(nomes[cont], token);
		cont++;
		token = strtok(NULL, ",");
		pontos.push_back(atoi(token));
	}
	int a = 0, b = 0, maior = -1, pos = 0;
	char* auxs;
	auxs = (char*)malloc(sizeof(char) * 30);
	int auxi;
	for (a = 0; a < pontos.size(); a++) {
		maior = -1;
		for (b = a; b < pontos.size(); b++) {
			if (pontos[b] > maior) {
				maior = pontos[b];
				pos = b;
			}
		}
		auxi = pontos[pos];
		auxs = nomes[pos];
		pontos[pos] = pontos[a];
		nomes[pos] = nomes[a];
		pontos[a] = auxi;
		nomes[a] = auxs;
	}
	for (int a = 0; a < pontos.size(); a++) {
		printf("%d nomes nos colocados.\n", a + 1);
		Textbox* j = new Textbox(24, sf::Color::White, false);
		char recep[5];
		_itoa(pontos[a], recep, 10);
		j->setFont(f);
		j->setPosition(sf::Vector2f(330, 100 + a*50));
		j->setText(nomes[a]);
		colocados->incluirEl(j);
		Textbox* k = new Textbox(24, sf::Color::Blue, false);
		k->setFont(f);
		k->setText(recep);
		k->setPosition(sf::Vector2f(560, 100 + a*50));
		colocados->incluirEl(k);
	}






	GerenciadorGrafico* graf = GerenciadorGrafico::getGerenciadorGrafico();
	sf::Event e;
	while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))) {
		graf->getWindow()->pollEvent(e);
		switch (e.type) {
		case sf::Event::Closed:
			graf->fecharJanela();
			break;
		case sf::Event::TextEntered:
			t->digitar(e);
			break;
		}
		graf->limpaJanela();
		t->draw(graf->getWindow());
		intro->draw(graf->getWindow());
		pontos1->draw(graf->getWindow());
		pontos2->draw(graf->getWindow());
		info->draw(graf->getWindow());
		ranking->draw(graf->getWindow());
		for (int a = 0; a < colocados->getTam(); a++) {
			Textbox* p = colocados->getElX(a+1)->getInfo();
			p->draw(graf->getWindow());
		}
		graf->getWindow()->display();
		Sleep(50);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		std::string nome = t->getText();
		char* s = NULL;
		s = (char*)malloc(sizeof(char) * 30);
		int i = 0;
		for (i = 0; i < nome.length(); i++) {
			s[i] = nome[i];
		}
		if (i < 30) s[i] = '\0';
		printf("O nome digitado foi %s.\n", s);
		fputs(s, fp);
		printf("O nome digitado foi %s.\n", s);
		fputc(',', fp);
		int pon=0;
		if (pMenu->getFase1()) pon = pMenu->getFase1()->getJogador1()->getPontos();
		else if (pMenu->getFase2()) pon = pMenu->getFase2()->getJogador1()->getPontos();
		printf("O nome digitado foi %s.\n", s);
		char p[5];
		_itoa(pon, p, 10);
		fputs(p, fp);
		fputc('\n', fp);
	}
	
	fclose(fp);
	delete info;
	delete pontos1;
	delete pontos2;
	delete t;
	delete intro;
	delete ranking;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) pMenu->executar();
}