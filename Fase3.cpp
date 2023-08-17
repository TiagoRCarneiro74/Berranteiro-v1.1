#include "Fase3.h"
#include "Fase2.h"
#include "Pedra.h"
#include "Espinho.h"
#include "Item.h"
#include "Caixa.h"
#include "Chave.h"
#include "Porta.h"
#include "MunicaoMP5.h"
#include <iostream>

using namespace Fases;
using namespace Itens;

Fase3::Fase3(GerenciadorColisao* c, GerenciadorGrafico* g, GerenciadorEvento* e) :
    Fase(c, g, e)
{

}

Fase3::Fase3() : Fase() {
    lista = new ListaEntes();
    inimigos = new ListaEntes();
    //obs = new Lista<Obstaculo>;

    f1 = new sf::Music();
    //f1->openFromFile("Midia/Musicas/S8M4.ogg");
    sf::Image i;
    i.loadFromFile("Midia/Imagens/Fase3.png");
    Plataforma::setImagem(i);
    Mapa* mapa = new Mapa(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(9600.0f, 2048.0f));
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

Fase3::~Fase3() {
    delete f1;
}

void Fase3::executar()
{
    //float legacy = 0.0, atual = 0.0;
    //Elemento<Hitbox>* itobs = obs->getPrimeiro();


    if (j1 && j2) while ((j1->getVidas() > 0 || j2->getVidas() > 0) && GerenciadorGrafico::getGerenciadorGrafico()->verifJanelaAberta())
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
        /*if ((j1->getPos().x > 4300 && j1->getPos().y > 800) || (j2->getPos().x > 4300 && j2->getPos().y > 800)) {
            f1->stop();
            //Fase2* f2 = new Fase2();
            //f2->executar();
            break;
        }*/
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
    //f1->pause();
}

void Fase3::geraInimigos()
{
    geraOnca(400, 100);
    geraSoldado(1152, 416, 1);
    //geraSoldado(1248, 416, 2);
    geraArara(928, 224);
    geraArara(65 * 32, 17 * 32);
    geraOnca(75 * 32, 18 * 32);
    geraSoldado(59 * 32, 10 * 32, 2);
    geraOnca(48 * 32, 27 * 32);
    geraArara(61 * 32, 31 * 32);
    geraArara(21 * 32, 34 * 32);
    geraArara(29 * 32, 36 * 32);
    geraSoldado(30 * 32, 18 * 32, 2);
    geraSoldado(3 * 32, 29 * 32, 1);
    geraOnca(22 * 32, 46 * 32);
    geraOnca(28 * 32, 46 * 32);
    geraSoldado(7 * 32, 49 * 32, 2);
    geraOnca(43 * 32, 0);
    geraOnca(47 * 32, 0);
    geraSoldado(107 * 32, 49 * 32, 2);
    geraOnca(102 * 32, 55 * 32);
    geraOnca(107 * 32, 55 * 32);
    geraArara(87 * 32, 50 * 32);
    geraSoldado(70 * 32, 55 * 32, 1);
    geraOnca(78 * 32, 51 * 32);
    geraArara(44 * 32, 54 * 32);
    geraArara(54 * 32, 54 * 32);
    geraOnca(33 * 32, 56 * 32);
    geraSoldado(131 * 32, 54 * 32, 1);
    geraOnca(91 * 32, 39 * 32);
    geraArara(99 * 32, 14 * 32);
    geraArara(98 * 32, 25 * 32);
    geraArara(96 * 32, 35 * 32);
    geraSoldado(125 * 32, 8 * 32, 2);
    geraOnca(113 * 32, 22 * 32);



    Curupira* c = geraCurupira(215 * 32, 11 * 32);
    c->setItem("chave-A4");
    inimigos->add(static_cast<Entidade*>(c->getFogo()));
    lista->add(static_cast<Entidade*>(c->getFogo()));

    c->setLista(inimigos);

    /*srand(time(NULL));
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
    /*if (verif == 1) geraOnca(3014, 1335);
    verif = rand() % 4;
    if (verif == 1) geraSoldado(4334, 823, 2);
    verif = rand() % 4;
    if (verif == 1) geraOnca(3110, 1848);*/

    j1->setl_ini(inimigos);
}


void Fase3::geraObstaculos() {
    /*srand(time(NULL));

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
    }*/
    geraEspinho(10 * 32, 13 * 32, 4);
    geraEspinho(14 * 32, 50 * 32, 6);
    geraEspinho(31 * 32, 50 * 32, 9);
    geraEspinho(95 * 32, 43 * 32, 10);
    geraEspinho(42 * 32, 60 * 32, 6);
    geraEspinho(55 * 32, 60 * 32, 6);
    geraEspinho(111 * 32, 50 * 32, 2);
}

void Fase3::geraTrepadeira(float x, float y)
{
    Trepadeira* p1 = new Trepadeira(x, y);
    lista->add(p1);
    inimigos->add(p1);
}

void Fase3::geraItens() {
    Item* i = NULL;
    /*geraItem(2368, 300, "skorpion");
    i = geraItem(2300, 300, "caixa");
    static_cast <Caixa*> (i)->setI1("skorpion");
    static_cast <Caixa*> (i)->setI2("skorpion");
    geraItem(1000, 200, "med");
    geraItem(920, 180, "caixa");
    i = geraItem(900, 150, "chave");
    static_cast <Chave*> (i)->setString("3A1");
    geraItem(1100, 200, "med");
    geraItem(3300, 300, "med");
    geraItem(4330, 820, "med");
    i = geraItem(300, 100, "porta");
    static_cast <Porta*> (i)->setString("3A1");*/

    i = geraItem(2 * 32, 17 * 32, "caixa");
    static_cast <Caixa*> (i)->setI1("chave-A1");
    static_cast <Caixa*> (i)->setI2("mp5");
    geraItem(59 * 32, 11 * 32, "medpack");
    geraItem(61 * 32, 11 * 32, "medpack");
    geraItem(23 * 32, 41 * 32, "medpack");
    geraItem(27 * 32, 41 * 32, "medpack");
    geraItem(74 * 32, 36 * 32, "medpack");
    geraItem(81 * 32, 36 * 32, "medpack");
    i = geraItem(33 * 32, 18 * 32, "caixa");
    //static_cast <Caixa*> (i)->setI1("pistola");
    static_cast <Caixa*> (i)->setI2("medpack");
    i = geraItem(101 * 32, 5 * 32, "porta");
    static_cast <Porta*> (i)->setString("A1");
    //i = geraItem(85 * 32, 9 * 32, "caixa");
    //static_cast <Caixa*> (i)->setI1("medpack");
    //static_cast <Caixa*> (i)->setI2("skorpion");
    geraItem(84 * 32, 9 * 32, "medpack");
    geraItem(86 * 32, 9 * 32, "pistola");
    i = geraItem(124 * 32 - 80, 37 * 32, "porta");
    static_cast <Porta*> (i)->setString("A2");
    i = geraItem(118 * 32, 38 * 32, "chave");
    static_cast <Chave*> (i)->setString("A2");
    i = geraItem(108 * 32, 38 * 32, "caixa");
    static_cast <Caixa*> (i)->setI1("chave-B2");
    static_cast <Caixa*> (i)->setI2("medpack");
    geraItem(119 * 32, 24 * 32, "mp5");
    geraItem(69 * 32, 46 * 32, "pistola");
    geraItem(49 * 32, 59 * 32, "medpack");
    geraItem(51 * 32, 59 * 32, "medpack");
    geraItem(53 * 32, 59 * 32, "medpack");
    i = geraItem(15 * 32, 53 * 32, "porta");
    static_cast <Porta*> (i)->setString("A3");
    i = geraItem(85 * 32, 5 * 32, "caixa");
    static_cast <Caixa*> (i)->setI1("chave-A3");
    i = geraItem(275 * 32, 5 * 32, "porta");
    static_cast <Porta*> (i)->setString("A4");
    geraItem(282 * 32, 5 * 32, "skorpion");
    geraItem(285 * 32, 5 * 32, "municaoskorpion");
    geraItem(286 * 32, 5 * 32, "municaoskorpion");
    i = geraItem(279 * 32, 5 * 32, "medpack");
    static_cast <Medpack*> (i)->setValor(30);
    i = geraItem(280 * 32, 5 * 32, "medpack");
    static_cast <Medpack*> (i)->setValor(20);
    geraItem(288 * 32, 5 * 32, "chave-B4");
    geraItem(74 * 32, 2 * 32, "chave-B1");

    i = geraItem(135 * 32, 54 * 32, "porta");
    static_cast <Porta*> (i)->setString("B1");
    i = geraItem(139 * 32, 48 * 32, "porta");
    static_cast <Porta*> (i)->setString("B2");
    i = geraItem(147 * 32, 48 * 32, "porta");
    static_cast <Porta*> (i)->setString("B3");
    i = geraItem(155 * 32, 48 * 32, "porta");
    static_cast <Porta*> (i)->setString("B4");

    i = geraItem(138 * 32, 56 * 32, "caixa");
    static_cast <Caixa*> (i)->setI1("medpack");
    static_cast <Caixa*> (i)->setI2("skorpion");
    i = geraItem(141 * 32, 58 * 32, "medpack");
    static_cast <Medpack*> (i)->setValor(47);

    //i = geraItem(400, 100, "municaomp5");
    //static_cast <MunicaoMP5*> (i)->setValor(63);
}

sf::Music* Fase3::getMusica() { return f1; }

Curupira* Fase3::geraCurupira(float x, float y) {
    Curupira* inimigo;
    inimigo = new Curupira(j1, j2, x, y);
    inimigo->setFase(this);

    inimigos->add(static_cast<Entidade*>(inimigo));
    lista->add(static_cast<Entidade*>(inimigo));

    return inimigo;
}
