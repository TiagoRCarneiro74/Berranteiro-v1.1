#include "Fase1.h"
#include "Fase2.h"
#include "Pedra.h"
#include "Espinho.h"
#include <iostream>

using namespace Fases;

Fase1::Fase1(GerenciadorColisao *c, GerenciadorGrafico *g, GerenciadorEvento *e):
Fase(c, g, e)
{
    
}

Fase1::Fase1(): Fase() {
    lista = new ListaEntes();
    inimigos = new ListaEntes();
    //obs = new Lista<Obstaculo>;

    f1 = new sf::Music();
    f1->openFromFile("Midia/Musicas/S8M4.ogg");
    sf::Image i;
    i.loadFromFile("Midia/Imagens/Fase1.png");
    Plataforma::setImagem(i);
    Mapa* mapa = new Mapa(sf::Vector2f(0.0f, 160.0f), sf::Vector2f(4992.0f, 2240.0f));
    mapa2 = mapa;

    j1 = new Jogador(1);
    j1->setMapa2(mapa2);
    interf->setJogador(j1);

    j2 = new Jogador(2);
    j2->setMapa2(mapa2);

    pGraf = GerenciadorGrafico::getGerenciadorGrafico();
    pEvent = GerenciadorEvento::getGerenciadorEvento();

    lista->add(static_cast<Entidade*>(j1));
    lista->add(static_cast<Entidade*>(j2));

    geraInimigos();
    geraObstaculos();
    geraItens();

    pEvent->setJogador1(j1);
    pEvent->setJogador2(j2);

    pColi = new GerenciadorColisao(inimigos, mapa2, j1, j2);

    f1->play();
}

Fase1::~Fase1(){
    delete f1;
}

void Fase1::executar()
{
    //float legacy = 0.0, atual = 0.0;
    //Elemento<Hitbox>* itobs = obs->getPrimeiro();
    

    if (j1 && j2) while((j1->getVidas()>0 || j2->getVidas()>0) && GerenciadorGrafico::getGerenciadorGrafico()->verifJanelaAberta())
    {
        moveLista();
        //atual = j1->getMapa()->getincx();

        /*if (atual != legacy) {
			inimigos->reposLista(-j1->getVel().x, 0);
			while (itobs != NULL) {
				itobs->getInfo()->reposX(-j1->getVel().x);
				itobs = itobs->getProximo();
			}
		}*/
        if ((j1->getPos().x > 4300 && j1->getPos().y > 800) || (j2->getPos().x > 4300 && j2->getPos().y > 800)) {
            f1->stop();
            //Fase2* f2 = new Fase2();
            //f2->executar();
            break;
        }
        pGraf->limpaJanela();
	    mapa2->imprimir();
		lista->desenhaLista();
        interf->atualiza();
        interf->imprimir();
		pGraf->mostraElementos();
        float t = clock.restart().asSeconds();
        float fps = 1.0f / (t);
        std::cout << "FPS: " << fps << "\n";
        //interf->teste();
        //interface->atualiza();
        //interface->imprimir();
    }
    std::cout << "O loop de execucao da fase terminou.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    f1->pause();
}

void Fase1::geraInimigos()
{

    srand(time(NULL));
    int verif;
    int lim = 0;
    int contador = 0;
    float x = 300;
    float y = 100;
    geraOnca(660, 376);
    geraSoldado(1000, 120, 1);
    geraOnca(3224, 1462);
    geraArara(2384, 250);
    geraArara(1312, 150);
    geraArara(2936, 568);
    geraSoldado(3456, 662, 2);


    verif = rand() % 4;
    if (verif == 1) geraOnca(1072, 248);
    verif = rand() % 4;
    if (verif == 1) geraArara(352, 50);
    verif = rand() % 4;
    if (verif == 1) geraArara(1080, 96);
    verif = rand() % 4;
    if (verif == 1) geraOnca(2304, 374);
    verif = rand() % 4;
    /*if (verif == 1) geraSoldado(3456, 662, 2);
    verif = rand() % 4;*/
    if (verif == 1) geraOnca(3014, 1335);
    verif = rand() % 4;
    if (verif == 1) geraSoldado(4334, 823, 2);
    verif = rand() % 4;
    if (verif == 1) geraOnca(3110, 1848);

    j1->setl_ini(inimigos);
}


void Fase1::geraObstaculos() {
    srand(time(NULL));
    
    int verif;
    verif = rand() % 4;
    if (verif == 1) {
        geraPedra(1736, 280);
    }
    verif = rand() % 4;
    if (verif == 2) {
        geraPedra(2368, 200);
    }
    verif = rand() % 4;
    if (verif == 3) {
        geraPedra(3302, 300);
    }
    geraTrepadeira(1072, 100);
    geraPedra(2056, 300);
    geraPedra(2632, 300);
    geraEspinho(3424, 1856, 8);
    geraEspinho(2752, 1952, 3);
    geraEspinho(3424, 2144, 3);
    geraEspinho(3616, 2144, 3);

    verif = rand() % 4;
    if (verif == 1) {
        geraEspinho(3168, 1472, 3);
    }
    verif = rand() % 4;
    if (verif == 2) {
        geraEspinho(3136, 736, 4);
    }
    verif = rand() % 4;
    if (verif == 3) {
        geraEspinho(2592, 544, 4);
    }
    verif = rand() % 4;
    if (verif == 1) {
        geraEspinho(576, 160, 3);
    }
}

void Fase1::geraTrepadeira(float x, float y)
{
    Trepadeira* p1 = new Trepadeira(x, y);
    lista->add(p1);
    inimigos->add(p1);
}

void Fase1::geraItens() {
    geraItem(2368, 300, "skorpion");
    geraItem(2300, 300, "caixa");
    geraItem(1000, 200, "med");
    geraItem(920, 180, "caixa");
    geraItem(1100, 200, "med");
    geraItem(3300, 300, "med");
    geraItem(4330, 820, "med");
}

sf::Music* Fase1::getMusica() { return f1; }
