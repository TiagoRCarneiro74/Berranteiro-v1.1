#include "ListaEntes.h"

using namespace Listas;

ListaEntes::ListaEntes() {}

ListaEntes::~ListaEntes() 
{
	lista.~Lista();
}


void ListaEntes::add(Entidade* x) {
	lista.incluirEl(x);
}

void ListaEntes::reposLista(float x, float y)
{
	Lista<Entidade>::Elemento<Entidade> *aux;
	Entidade* info;
	aux = lista.getPrimeiro();

	while(aux!=NULL)
	{
		info = aux->getInfo();
		info->repos(x,y);
		aux = aux->getProximo();
	}
}

void ListaEntes::desenhaLista()
{
	Lista<Entidade>::Elemento<Entidade> *aux;
	Entidade* info;

	aux = lista.getPrimeiro();

	while(aux!=NULL)
	{
		info = aux->getInfo();
		
		if(info->getVivo()==true)
			info->imprimir();

		aux = aux->getProximo();
	}
}

Lista<Entidade>* ListaEntes::getLista() { return &lista; }