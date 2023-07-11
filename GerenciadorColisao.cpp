#include "GerenciadorColisao.h"
#include <cmath>

using namespace Gerenciadores;

GerenciadorColisao::GerenciadorColisao(ListaEntes* ini, Mapa* m, Jogador* p1, Jogador* p2) {
	inimigos = ini;
	map = m;
	jogadores.push_back(p1);
	jogadores.push_back(p2);
}

GerenciadorColisao::GerenciadorColisao()
{
	inimigos = NULL;
	map = NULL;
}

GerenciadorColisao::~GerenciadorColisao(){}

const sf::Vector2f GerenciadorColisao::calculaColisaoIni(Ente* e1, Ente* e2) {
	sf::Vector2f pos1 = e1->getPos();
	sf::Vector2f pos2 = e2->getPos();
	sf::Vector2f tam1 = e1->getTam();
	sf::Vector2f tam2 = e2->getTam();
	sf::Vector2f distanciaEntreCentros{
		fabs((pos1.x + tam1.x / 2.0f) - (pos2.x + tam2.x / 2.0f)),
		fabs((pos1.y + tam1.y / 2.0f) - (pos2.y + tam2.y / 2.0f))
	};
	sf::Vector2f somaMetadeRetangulo(tam1.x / 2.0f + tam2.x / 2.0f, tam1.y / 2.0f + tam2.y / 2.0f);
	return sf::Vector2f(distanciaEntreCentros.x - somaMetadeRetangulo.x, distanciaEntreCentros.y - somaMetadeRetangulo.y);
	//Por Giovane Limas Salvi
}

const sf::Vector2f GerenciadorColisao::calculaColisaoPlat(Ente* e, Plataforma* p) {
	sf::Vector2f pos1 = e->getPos();
	sf::Vector2f pos2 = p->getPos();
	sf::Vector2f tam1 = e->getTam();
	sf::Vector2f tam2 = p->getTam();
	sf::Vector2f distanciaEntreCentros{
		fabs((pos1.x + tam1.x / 2.0f) - (pos2.x + tam2.x / 2.0f)),
		fabs((pos1.y + tam1.y / 2.0f) - (pos2.y + tam2.y / 2.0f))
	};
	sf::Vector2f somaMetadeRetangulo(tam1.x / 2.0f + tam2.x / 2.0f, tam1.y / 2.0f + tam2.y / 2.0f);
	return sf::Vector2f(distanciaEntreCentros.x - somaMetadeRetangulo.x, distanciaEntreCentros.y - somaMetadeRetangulo.y);
}

void GerenciadorColisao::executar() {
	Entidade* ent1;
	int i = 0;
	int j = 0;
	bool flag1 = false;
	bool flag2 = false;
	bool flag4 = false;
	bool flag3 = false;

	//for (int i = 0; i < inimigos->getLista()->getTam() - 1; i++) {
		//Entidade* ent1 = inimigos->getLista()->getElX(i)->getInfo();
		for (j = 0; j <= inimigos->getLista()->getTam(); j++) {
			Entidade* ent2 = inimigos->getLista()->getElX(j)->getInfo();
			if(ent2->getVivo()==true)
			{
				for(i=0;i<2;i++)
				{
					if(jogadores[i]->getVivo()==false) continue;
					ent1 = static_cast<Entidade*>(jogadores[i]);

					sf::Vector2f ds = calculaColisaoIni(ent1, ent2);
					if (ds.x < 0.0f && ds.y < 0.0f) {
						//std::cout << "Ocorre uma colisao 1.\n";
						
						if(ent2->getObstaculo()==false)
							jogadores[i]->colisaoInimigo(ent2);

						else
						{
							if(i==0)
								flag1 = jogadores[i]->colisaoMapaObs(ent2);
							else
								flag2 = jogadores[i]->colisaoMapaObs(ent2);
						}
					}
					
				}
			}
		}
	

		if(jogadores[0]->getSegue()==1)
			ent1 = static_cast<Entidade*>(jogadores[0]);
		
		else
			ent1 = static_cast<Entidade*>(jogadores[1]);

		GerenciadorGrafico *graf = GerenciadorGrafico::getGerenciadorGrafico();
		if (ent1->getPos().x < map->getIni() + map->getLen() * 0.2)map->setColidiveis(map->getC1());
		else if (ent1->getPos().x > map->getIni() + map->getLen() * 0.2 && ent1->getPos().x < map->getIni() + map->getLen() * 0.4) map->setColidiveis(map->getC1b());
		else if (ent1->getPos().x > map->getIni() + map->getLen() * 0.4 && ent1->getPos().x < map->getIni() + map->getLen() * 0.6) map->setColidiveis(map->getC2());
		else if (ent1->getPos().x > map->getIni() + map->getLen() * 0.6 && ent1->getPos().x < map->getIni() + map->getLen() * 0.8) map->setColidiveis(map->getC2b());
		else if (ent1->getPos().x > map->getIni() + map->getLen() * 0.8 && ent1->getPos().x < map->getIni() + map->getLen()) map->setColidiveis(map->getC3());

		for (j = 0; j < map->getColidiveis()->getTam(); j++) {
			Plataforma* hbx = map->getColidiveis()->getElX(j)->getInfo();
			if (hbx->getPos().x > graf->getCoorView().x + 320 || hbx->getPos().x < graf->getCoorView().x - 320 || hbx->getPos().y > graf->getCoorView().y + 240 || hbx->getPos().y < graf->getCoorView().y - 240) continue;
			
			for(i=0;i<2;i++)
			{ 
				if(jogadores[i]->getVivo()==false) continue;
				ent1 = static_cast<Entidade*>(jogadores[i]);

				sf::Vector2f ds = calculaColisaoPlat(ent1, hbx);
				if (ds.x < 0.0f && ds.y < 0.0f) {

					if(i==0)
						flag3 = jogadores[i]->colisaoMapaObs(static_cast<Entidade*>(hbx));
					else
						flag4 = jogadores[i]->colisaoMapaObs(static_cast<Entidade*>(hbx));

				}
			}
			//else pJogador->cair();
		}
		if (flag1 == 0 && flag3 == 0) jogadores[0]->cair();
		if (flag2 == 0 && flag4 == 0) jogadores[1]->cair();
		
		for (i = 0; i <= inimigos->getLista()->getTam(); i++) {
			flag2 = 0;
			ent1 = inimigos->getLista()->getElX(i)->getInfo();
			if (ent1->getVivo() == false) continue;
			if (ent1->getPos().x > graf->getCoorView().x + 500 || ent1->getPos().x < graf->getCoorView().x - 500 || ent1->getPos().y > graf->getCoorView().y + 400 || ent1->getPos().y < graf->getCoorView().y - 400) continue;
			for (j = 0; j < map->getColidiveis()->getTam(); j++) {
				Plataforma* hbx = map->getColidiveis()->getElX(j)->getInfo();
				if (hbx->getPos().x > graf->getCoorView().x + 500 || hbx->getPos().x < graf->getCoorView().x - 500 || hbx->getPos().y > graf->getCoorView().y + 400 || hbx->getPos().y < graf->getCoorView().y - 400) continue;
				sf::Vector2f ds = calculaColisaoPlat(ent1, hbx);
				if (ds.x < 0.0f && ds.y < 0.0f) {
					//std::cout << "Ocorre uma colisao 2 - Inimigo.\n";
					if (ent1->getPos().y + ent1->getTam().y >= hbx->getPos().y) {
						ent1->setVelY(0.0f);
						flag2 = 1;
					}

				}
				//else if (ent1->getPos().x + ent1->getTam().x >= hbx->getPos().x)
				//else pJogador->cair();
			}
			if (flag2 == 0) ent1->cair();
		}
	}


void GerenciadorColisao::incluirJogador(Jogador *p)
{
	jogadores.push_back(p);
}
void GerenciadorColisao::setInimigos (ListaEntes *l)
{
	inimigos = l;
}
void GerenciadorColisao::setMapa (Mapa *m)
{
	map = m;
}

Ente* GerenciadorColisao::hitscan(Jogador* j, Ente* e) {
	if (!j->getVirado()) {
		if ((e->getPos().y >= j->getPos().y + 40 && e->getPos().y <= j->getPos().y + 60) && e->getPos().x + e->getTam().x > j->getPos().x + j->getTam().x - 10) return e;
	}
	else if (j->getVirado()) {
		if ((e->getPos().y >= j->getPos().y + 40 && e->getPos().y <= j->getPos().y + 60) && e->getPos().x < j->getPos().x - 10) return e;
	}
	return NULL;
}