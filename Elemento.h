/*#pragma once

template <class TIPO>
class Elemento
{
  private:
    TIPO * info;
    Elemento<TIPO>* proximo;
    Elemento<TIPO>* anterior;

  public:
    Elemento();
    ~Elemento();
    void setInfo(TIPO* i);
    TIPO* getInfo();
    void setProximo(Elemento<TIPO> *p);
    void setAnterior(Elemento<TIPO> *p);
    Elemento<TIPO>* getProximo();
    Elemento<TIPO>* getAnterior();

};

template <class TIPO>
Elemento<TIPO>::Elemento()
{
  proximo = NULL;
  anterior = NULL;
  info = NULL;
}

template <class TIPO>
Elemento<TIPO>::~Elemento()
{
  proximo = NULL;
  info = NULL;
}

template <class TIPO>
void Elemento<TIPO>::setInfo(TIPO *i)
{
  info = i;
}

template <class TIPO>
TIPO* Elemento<TIPO>::getInfo()
{
  return info;
}

template <class TIPO>
void Elemento<TIPO>::setProximo(Elemento<TIPO> *p)
{
    proximo = p;
}

template <class TIPO>
void Elemento<TIPO>::setAnterior(Elemento<TIPO> *p)
{
    anterior = p;
}

template <class TIPO>
Elemento<TIPO>* Elemento<TIPO>::getProximo()
{
    return proximo;
}

template <class TIPO>
Elemento<TIPO>* Elemento<TIPO>::getAnterior()
{
    return anterior;
}*/