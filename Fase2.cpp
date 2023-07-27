#include "Fase2.h"
#include "Pedra.h"
#include "Espinho.h"

using namespace Fases;

Fase2::Fase2(GerenciadorColisao* c, GerenciadorGrafico* g, GerenciadorEvento* e) :
    Fase(c, g, e)
{

}

Fase2::Fase2() : Fase() {
    lista = new ListaEntes();
    inimigos = new ListaEntes();
    //obs = new Lista<Obstaculo>;

    f1 = new sf::Music();
    f1->openFromFile("Midia/Musicas/S8M4.ogg");
    f2 = new sf::Music();
    f2->openFromFile("Midia/Musicas/S9M4.ogg");
    sf::Image i;
    i.loadFromFile("Midia/Imagens/Fase2.png");
    Plataforma::setImagem(i);
    Mapa* mapa = new Mapa(sf::Vector2f(4192.0f, 32.0f), sf::Vector2f(12768.0f, 1792.0f));
    mapa2 = mapa;
    cout << "O mapa foi criado.\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    j1 = new Jogador(1);
    interf->setJogador(j1);
    j1->setMapa2(mapa2);
    j1->setPos(4320, 800);

    j2 = new Jogador(2);
    //j2->setMapa2(mapa2);
    j2->setPos(4320, 800);
    

    pGraf = GerenciadorGrafico::getGerenciadorGrafico();
    pEvent = GerenciadorEvento::getGerenciadorEvento();
    pGraf->setView(sf::Vector2f(4320, 800));

    lista->add(static_cast<Entidade*>(j1));
    lista->add(static_cast<Entidade*>(j2));
    geraInimigos();
    geraObstaculos();
    geraItens();
    /*Pedra* p1 = new Pedra(150, 150);
    lista->add(p1);
    inimigos->add(p1);
    Pedra* p2 = new Pedra(500, 100);
    lista->add(p2);
    inimigos->add(p2);*/

    pEvent->setJogador1(j1);
    pEvent->setJogador2(j2);
    pColi = new GerenciadorColisao(inimigos, mapa2, j1, j2);

    f1->play();
}

Fase2::~Fase2() {
    delete f1;
    delete f2;
}

void Fase2::executar()
{
    //float legacy = 0.0, atual = 0.0;
    //Elemento<Hitbox>* itobs = obs->getPrimeiro();


    if (j1) while ((j1->getVidas() > 0 || j2->getVidas() > 0) && GerenciadorGrafico::getGerenciadorGrafico()->verifJanelaAberta())
    {
        if (!GerenciadorGrafico::getGerenciadorGrafico()->verifJanelaAberta()) break;

        moveLista();

        if ((j1->getPos().x >= 12086 || j2->getPos().x >= 12086) && f2->getStatus() != sf::Music::Playing) {
            if (f1->getStatus() == sf::Music::Playing) f1->stop();
            f2->play();
        }
        //atual = j1->getMapa()->getincx();

        /*if (atual != legacy) {
            inimigos->reposLista(-j1->getVel().x, 0);
            while (itobs != NULL) {
                itobs->getInfo()->reposX(-j1->getVel().x);
                itobs = itobs->getProximo();
            }
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
    }
    std::cout << "O loop de execucao da fase terminou.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    if (f1->getStatus() == sf::Music::Playing) f1->pause();
    else if (f2->getStatus() == sf::Music::Playing) f2->pause();
}


void Fase2::geraInimigos()
{

    srand(time(NULL));
    int verif;
    int lim = 0;
    int contador = 0;
    float x = 300;
    float y = 100;
    Curupira* c;
    geraSoldado(4830, 888, 2);
    geraOnca(7912, 472);
    geraOnca(9110, 855);
    geraOnca(9286, 855);
    geraOnca(9526, 728);
    geraOnca(12142, 823);
    geraOnca(12342, 823);
    geraArara(5344, 544);
    geraSoldado(6592, 544, 1);
    geraArara(8320, 192);
    geraArara(9184, 768);
    geraArara(9536, 576);
    geraArara(12384, 640);
    verif = rand() % 4;
    if (verif == 1) geraOnca(5382, 950);
    verif = rand() % 4;
    if (verif == 1) geraOnca(5816, 792);
    verif = rand() % 4;
    if (verif == 1) geraOnca(6382, 500);
    verif = rand() % 4;
    if (verif == 1) geraOnca(6630, 300);
    verif = rand() % 4;
    if (verif == 1) geraOnca(6912, 438);
    verif = rand() % 4;
    if (verif == 1) geraOnca(8110, 920);
    verif = rand() % 4;
    if (verif == 1) geraSoldado(9406, 1496, 1);
    verif = rand() % 4;
    if (verif == 1) geraOnca(10126, 728);
    verif = rand() % 3;
    if (verif == 1) geraArara(8640, 224);
    verif = rand() % 3;
    if (verif == 1) geraArara(10144, 288);
    verif = rand() % 3;
    if (verif == 1) geraArara(12192, 640);

    c = geraCurupira(12598, 800);

    inimigos->add(static_cast<Entidade*>(c->getFogo()));
    lista->add(static_cast<Entidade*>(c->getFogo()));

    c->setLista(inimigos);
    j1->setl_ini(inimigos);
}

void Fase2::geraObstaculos() {
    srand(time(NULL));

    geraEspinho(6976, 768, 4);
    geraEspinho(7296, 768, 4);
    geraEspinho(7424, 832, 12);
    geraEspinho(8256, 1024, 8);
    geraEspinho(8448, 704, 2);
    geraEspinho(9152, 1600, 4);
    geraEspinho(9536, 1600, 4);
    geraEspinho(9792, 1728, 8);
    geraEspinho(10304, 1024, 15);
    geraPedra(5440, 544);
    geraPedra(6400, 480);
    geraPedra(9856, 256);

    int verif;
    verif = rand() % 3;
    if (verif == 1) {
        geraPedra(11040, 448);
    }
    verif = rand() % 3;
    if (verif == 1) {
        geraPedra(12320, 608);
    }
    verif = rand() % 3;
    if (verif == 1) {
        geraPedra(11840, 608);
    }
    verif = rand() % 3;
    if (verif == 1) {
        geraEspinho(5670, 960, 5);
    }
    verif = rand() % 3;
    if (verif == 1) {
        geraEspinho(7808, 512, 4);
    }
}

Curupira* Fase2::geraCurupira(float x, float y)
{
    Curupira *inimigo;
    inimigo = new Curupira(j1, j2, x, y);

    inimigos->add(static_cast<Entidade*>(inimigo));
    lista->add(static_cast<Entidade*>(inimigo));

    return inimigo;
}

void Fase2::geraItens() {
    geraItem(4900, 900, "pistola");
    geraItem(9200, 768, "mp5");
}

sf::Music* Fase2::getMusica() { return f1; }