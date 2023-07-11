#pragma once
#include <stdlib.h>

namespace Listas
{

  template <class TIPO>
  class Lista
  {

    public:

      template <class TIPO1>
      class Elemento
      {
        private:
          TIPO1 * info;
          Elemento<TIPO1>* proximo;
          Elemento<TIPO1>* anterior;

        public:
          Elemento(){
            proximo = NULL;
            anterior = NULL;
            info = NULL;
          }

          ~Elemento()
          {
            proximo = NULL;
            info = NULL;
          }


          void setInfo(TIPO1 *i)
          {
            info = i;
          }

          TIPO1* getInfo()
          {
            return info;
          }

          void setProximo(Elemento<TIPO1> *p)
          {
              proximo = p;
          }

          void setAnterior(Elemento<TIPO1> *p)
          {
              anterior = p;
          }

          Elemento<TIPO1>* getProximo()
          {
              return proximo;
          }

          Elemento<TIPO1>* getAnterior()
          {
              return anterior;
          }
      };
      Lista();
      ~Lista();
      void incluirEl(TIPO *elemento);
      void removeEl(Elemento<TIPO>* elemento);
      Elemento<TIPO>* getPrimeiro();
      Elemento<TIPO>* getElX(int x);
      int getTam();

      
    private:
      Elemento<TIPO> *primeiro;
      Elemento<TIPO> *ultimo;
      int cont;

  };


  //--------Lista--------//


  template <class TIPO>
  Lista<TIPO>::Lista()
  {
    primeiro = NULL;
    ultimo = NULL;
    cont = 0;
  }

  template <class TIPO>
  Lista<TIPO>::~Lista()
  {
    Lista<TIPO>::Elemento<TIPO> *aux;

    while(primeiro!=NULL)
      {
        aux = primeiro;
        primeiro = primeiro->getProximo();
        delete(aux);
      }
    cont = 0;
  }

  template <class TIPO>
  void Lista<TIPO>::incluirEl(TIPO *elemento)
  {
    
      Lista<TIPO>::Elemento<TIPO> *aux=NULL;
      
      aux = new Lista<TIPO>::Elemento<TIPO>();
      aux->setInfo(elemento);
      if(primeiro==NULL)
      {
        primeiro = aux;
        ultimo = aux;
        cont++;
      }
      else
      {
        ultimo->setProximo(aux);
        ultimo = ultimo->getProximo();
        cont++;
      }
    
  }

  template<class TIPO>
  void Lista<TIPO>::removeEl(Lista<TIPO>::Elemento<TIPO>* elemento)
  {
    Lista<TIPO>::Elemento<TIPO>  *anterior, *proximo;
    anterior = elemento->getAnterior();
    proximo = elemento->getProximo();
    anterior->setProximo(proximo);
    proximo->setAnterior(anterior);
    delete elemento;
    cont--;
  }

  template<class TIPO>
  Lista<TIPO>::Elemento<TIPO>* Lista<TIPO>::getPrimeiro()
  {
    return primeiro;
  }

  template <class TIPO>
  int Lista<TIPO>::getTam() { return cont; }

  template <class TIPO>
  Lista<TIPO>::Elemento<TIPO>* Lista<TIPO>::getElX(int x) 
  {
      int c = 1;
      Lista<TIPO>::Elemento<TIPO>* it = getPrimeiro();
      while (c < x) {
          it = it->getProximo();
          c++;
      }
      return it;
  }

}