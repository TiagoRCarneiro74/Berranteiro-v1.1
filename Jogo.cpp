#include "Jogo.h"

Jogo::Jogo() {

	jogador1 = NULL;
	jogador2 = NULL;

	graf = GerenciadorGrafico::getGerenciadorGrafico();
	pEvent = GerenciadorEvento::getGerenciadorEvento();
	menuopc = new Menu();
	//Fase1* f = new Fase1();
	//f = new Fase1();
	//pColi = new GerenciadorColisao(f->getInimigos(), f->getMapa2(), f->getJogador1());
	//pEvent->setJogador(f->getJogador1());
	pEvent->setPGraf(graf);
	//menuopc->setFase1(f);
	resumir = new Resumir(menuopc);
	bfase1 = new BFase1(menuopc);
	bfase2 = new BFase2(menuopc);
	salvar = new Salvar(menuopc);
	sair = new Sair(menuopc);
	//menuopc->setBFase1(bfase1);
	//menuopc->setResumir(resumir);
	//menuopc->setSair(sair);
	//menuopc->setFase1(f);
	//jogador1 = f->getJogador1();
	menuopc->executar();
	bool chk = 1;
	try { 
		if (menuopc->getFase() == NULL) throw (Jogador(1));
	}
	catch (Jogador j) {
		cout << "Nao ha jogador construido.\n";
		//Jogo::~Jogo();
		chk = 0;
	}
	if (chk == 1) executar();
}

Jogo::~Jogo() {
	delete pColi;
	//delete graf;
	//delete pEvent;
}

void Jogo::executar() {
	/*int i;
	while(graf->verifJanelaAberta())
	{

		i = menuopc->executar();

		switch(i)
		{
			case 1:
			{
				graf->fecharJanela();
			}
			break;

			case 2:
			{
				menuopc->getFase1()->executar();
			}
			break;

			case 3:
			{
		
			}
			break;

			default:
			{
				
			}
			break;
		}
	}*/
	if (menuopc->getFase2()) {
		jogador1 = menuopc->getFase2()->getJogador1();
		jogador2 = menuopc->getFase2()->getJogador2();
		//menuopc->getFase1()->getEvent()->setMenu(menuopc);
		if (GerenciadorGrafico::getGerenciadorGrafico()->verifJanelaAberta()) menuopc->getFase2()->executar();
	}
	else if (menuopc->getFase1()) {
		jogador1 = menuopc->getFase1()->getJogador1();
		jogador2 = menuopc->getFase1()->getJogador2();
		//menuopc->getFase1()->getEvent()->setMenu(menuopc);
		menuopc->getFase1()->executar();
		if ((jogador1->getVidas() > 0)) {
			Fase2* y = new Fase2();
			menuopc->setFase2(y);
			jogador1 = menuopc->getFase2()->getJogador1();
			jogador2 = menuopc->getFase2()->getJogador2();
			menuopc->getFase2()->executar();
		}
	}
	
	//cout << "Vidas de jogador: " << jogador1->getVidas() << endl;
	graf->setView(sf::Vector2f(320.0f, 240.0f));
	resumir->setPos(graf->getCoorView().x - 160, graf->getCoorView().y - 160);
	if (jogador1->getVidas() <= 0 && jogador2->getVidas() <= 0 && GerenciadorGrafico::getGerenciadorGrafico()->verifJanelaAberta()) {
		graf->setView(sf::Vector2f(320.0f, 240.0f));
		cout << "Coordenadas de view: " << graf->getCoorView().x << ", " << graf->getCoorView().y << endl;
		resumir->setPos(graf->getCoorView().x - 160, graf->getCoorView().y - 160);
		resumir->getCorpo().setPosition(graf->getCoorView().x - 160, graf->getCoorView().y - 160);
		menuopc->setResumir(resumir);
		menuopc->executar();
		executar();
		/*Fase* fm1 = menuopc->getFase();
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\nO menu sera executado.\n";
		menuopc->executar();
		Fase* fm2 = menuopc->getFase();
		if (fm1 != fm2) {
			delete fm1;
			pColi = new GerenciadorColisao(fm2->getInimigos(), fm2->getMapa2(), fm2->getJogador1());
			pEvent->setJogador(fm2->getJogador1());
			jogador1 = fm2->getJogador1();
		}*/
		
	}
	
}
