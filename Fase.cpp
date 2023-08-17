#include "Fase.h"
#include "Skorpion.h"
#include "Pistola.h"
#include "MP5.h"
#include "MedPack.h"
#include "Caixa.h"
#include "Soldado.h"
#include "Chave.h"
#include "Porta.h"
#include "MunicaoMP5.h"
#include "MunicaoSkorpion.h"
using namespace Itens;

using namespace Fases;


Fase::Fase() {
    pColi = NULL;
    pGraf = NULL;
    lista = NULL;
    pEvent = NULL;
    j1 = NULL;
    j2 = NULL;
    mapa2 = NULL;
    interf = new Interface();
    //obs = NULL;
}

Fase::Fase(GerenciadorColisao *c, GerenciadorGrafico *g, GerenciadorEvento *e)
{
    pColi = c;
    pGraf = g;
    lista = NULL;
    pEvent = e;
    j1 = NULL;
    j2 = NULL;
    mapa2 = NULL;
    interf = new Interface();
    //obs = NULL;
}

Fase::~Fase()
{
    mapa2->~Mapa();
    delete pColi;
    delete lista;
    delete j1;
    delete inimigos;
    delete j2;
    delete interf;
    pEvent = NULL;
    pGraf = NULL;
}

void Fase::setJogador1(Jogador *j)
{
    j1 = j;
    interf->setJogador(j);
}
void Fase::setJogador2(Jogador *j)
{
    j2 = j;
}

void Fase::setEntes(ListaEntes *l)
{
    lista = l;
}

void Fase::setInimigos(ListaEntes *i)
{
    inimigos =i;
}

void Fase::setMapa2(Mapa* m) { mapa2 = m; }

Mapa* Fase::getMapa2() { return mapa2; }

void Fase::setColi(GerenciadorColisao* c) { pColi = c; }

void Fase::setEvent(GerenciadorEvento* e) { pEvent = e; }

void Fase::setGraf(GerenciadorGrafico* g) { pGraf = g; }

ListaEntes* Fase::getLista() { return lista; }

ListaEntes* Fase::getInimigos() { return inimigos; }

Jogador* Fase::getJogador1() { return j1; }

Jogador* Fase::getJogador2() { return j2; }

void Fase::geraOnca(float x, float y)
{

    Onca* inimigo;
    inimigo = new Onca(j1, j2, x, y);
    inimigos->add(static_cast<Entidade*>(inimigo));
    lista->add(static_cast<Entidade*>(inimigo));

}

void Fase::geraArara(float x, float y)
{

    Arara *inimigo;
    inimigo = new Arara(j1, j2, x, y);
    inimigos->add(static_cast<Entidade*>(inimigo));
    lista->add(static_cast<Entidade*>(inimigo));

}

void Fase::geraSoldado(float x, float y, int s)
{
    Soldado *ini; 
    ini = new Soldado(j1, j2, x, y, s);
    inimigos->add(static_cast<Entidade*>(ini));
    lista->add(static_cast<Entidade*>(ini));
    ini->setFase(this);
}

void Fase::geraPedra(float x, float y)
{
    Pedra* p2 = new Pedra(x, y);
    lista->add(static_cast<Entidade*>(p2));
    inimigos->add(static_cast<Entidade*>(p2));
}
void Fase::geraEspinho(float x, float y, int tam)
{
    Espinho* e1 = new Espinho(x, y, tam);
    lista->add(static_cast<Entidade*>(e1));
    inimigos->add(static_cast<Entidade*>(e1));
}

Item* Fase::geraItem(float x, float y, string nome) {
    Item* i=NULL;
    if (nome == "skorpion") {
        i = new Skorpion(j1, x, y);
        static_cast <Skorpion*> (i)->setFase(this);
    }
    else if (nome == "pistola") {
        i = new Pistola(j1, x, y);
        static_cast <Pistola*> (i)->setFase(this);
    }
    else if (nome == "mp5") {
        i = new MP5(j1, x, y);
        static_cast <MP5*> (i)->setFase(this);
    }
    else if (nome == "medpack") {
        i = new Medpack(j1, x, y);
        static_cast <Medpack*> (i)->setFase(this);
    }
    else if (nome == "caixa") {
        i = new Caixa(j1, x, y);
        static_cast <Caixa*> (i)->setFase(this);
    }
    else if (nome == "chave") {
        i = new Chave(j1, x, y);
        static_cast <Chave*> (i)->setFase(this);
        
    }
    else if (nome[0] == 'c' && nome[1] == 'h') {
        i = new Chave(j1, x, y);
        string aux2;
        aux2.push_back(nome[6]);
        aux2.push_back(nome[7]);
        static_cast <Chave*> (i)->setString(aux2);
        static_cast <Chave*> (i)->setFase(this);
    }
    else if (nome == "porta") {
        i = new Porta(j1, x, y);
        static_cast <Porta*> (i)->setFase(this);
    }
    else if (nome == "municaomp5") {
        i = new MunicaoMP5(j1, x, y);
        static_cast <MunicaoMP5*> (i)->setFase(this);
    }
    else if (nome == "municaoskorpion") {
        i = new MunicaoSkorpion(j1, x, y);
        static_cast <MunicaoSkorpion*> (i)->setFase(this);
    }
    if (i != NULL) {
        lista->add(static_cast <Entidade*> (i));
        inimigos->add(static_cast <Entidade*> (i));
    }
    return i;
}


GerenciadorEvento* Fase::getEvent() { return pEvent; }

void Fase::moveLista()
{
    int contador;

    pColi->executar();
    pEvent->executar();
    if (pEvent->getDrop() == 1) jogador_soltarArma();

    //interface->atualiza();
    //interface->imprimir();

    for(contador=1; contador<lista->getLista()->getTam() + 1; contador++)
	{
        if (lista->getLista()->getElX(contador)->getInfo()->getVivo() == false) continue;
		lista->getLista()->getElX(contador)->getInfo()->move();//movimento do jogador eh atualizado na na funcao move(), que chama a funcao atualizaPos()
	}
}

Interface* Fase::getInterface() { return interf; }

void Fase::jogador_soltarArma() {
    if (dropclock.getElapsedTime().asSeconds() < 2) return;
    Arma* x = j1->getl_arma()->getElX(j1->getArmaSel())->getInfo();
    if (x->getNome() == "zero") return;
    if (x->getNome() == "pistola_d") {
        Arma* y = new Arma("pistola");
        j1->getl_arma()->incluirEl(y);
        j1->getl_arma()->removeElX(j1->getArmaSel());
        j1->setArmaSel(j1->getl_arma()->getTam());
        Item* i = geraItem(j1->getPos().x + 100 - j1->getVirado() * 200, j1->getPos().y + 30, "pistola");
        static_cast <Pistola*> (i)->setammo(x->getAmmo() / 2);
        static_cast <Pistola*> (i)->setmagvar(x->getMagvar() / 2);
    }
    else {
        string s = x->getNome();
        j1->getl_arma()->removeElX(j1->getArmaSel());
        Item* i = geraItem(j1->getPos().x + 100 - j1->getVirado() * 200, j1->getPos().y + 30, s);
        j1->setArmaSel(j1->getArmaSel() - 1);
        if (s == "skorpion") {
            static_cast <Skorpion*> (i)->setammo(x->getAmmo());
            static_cast <Skorpion*> (i)->setmagvar(x->getMagvar());
        }
        else if (s == "mp5") {
            static_cast <MP5*> (i)->setammo(x->getAmmo());
            static_cast <MP5*> (i)->setmagvar(x->getMagvar());
        }
        else if (s == "pistola") {
            static_cast <Pistola*> (i)->setammo(x->getAmmo());
            static_cast <Pistola*> (i)->setmagvar(x->getMagvar());
        }
    }
    dropclock.restart();
}