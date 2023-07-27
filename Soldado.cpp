#include "Soldado.h"

using namespace Entidades;
using namespace Personagens;

Soldado::Soldado(Jogador *j1, Jogador *j2, float x, float y, int s) :
Inimigo(j1, j2, x, y)
{
	contador = 0;
	corre = false;
    int i;
    //numVidas = 50;
    ataqueDistancia = true;
    voa = false;
	skin = s;

	if(s==1)
	{
		corpo.setTextureRect(sf::IntRect(0, 0, 329, 369));
		if(!textura.loadFromFile("Midia/Imagens/Soldado-E.png")) std::cout << "Erro na abertura da textura do inimigo." << std::endl;
		else {
			corpo.setTexture(textura);
		}
		arma = new Arma("mp5-s");

		Tdir.loadFromFile("Midia/Imagens/Soldado-D.png");
    	Tesq.loadFromFile("Midia/Imagens/Soldado-E.png");
    	Adir.loadFromFile("Midia/Imagens/Soldado-AD.png");
    	Aesq.loadFromFile("Midia/Imagens/Soldado-AE.png");
	}
	else
	{
		corpo.setTextureRect(sf::IntRect(0, 0, 367, 338));
		if(!textura.loadFromFile("Midia/Imagens/Soldado2-E.png")) std::cout << "Erro na abertura da textura do inimigo." << std::endl;
		else {
			corpo.setTexture(textura);
		}
		arma = new Arma("skorpion-s");

		Tdir.loadFromFile("Midia/Imagens/Soldado2-D.png");
    	Tesq.loadFromFile("Midia/Imagens/Soldado2-E.png");
    	Adir.loadFromFile("Midia/Imagens/Soldado2-AD.png");
    	Aesq.loadFromFile("Midia/Imagens/Soldado2-AE.png");
	}
    corpo.setScale(0.2, 0.2);

	
	

    /*srand(time(NULL));
    i = rand()%3 + 1;

    if(i==1)
        arma = new Arma("pistola", true);
    else if(i==2)
        arma = new Arma("mp5", true);
    else if(i=3)
        arma = new Arma("skorpion", true);
    */
}

Soldado::~Soldado()
{
	delete arma;
}

void Soldado::move()
{
    GerenciadorGrafico* graf = GerenciadorGrafico::getGerenciadorGrafico();
    if (pos.x > graf->getCoorView().x + 500 || pos.x < graf->getCoorView().x - 500 || pos.y > graf->getCoorView().y + 400 || pos.y < graf->getCoorView().y - 400) {
        congela();
    }
	else
	{
		sf::Vector2f posiJogador, posiJogador1, posiJogador2;

        posiJogador1 = jogador1->getPos();
        posiJogador2 = jogador2->getPos();

        if ((abs(posiJogador1.x - pos.x) <= abs(posiJogador2.x - pos.x)))
            posiJogador = posiJogador1;
            
        else
            posiJogador = posiJogador2;

		if(((abs(posiJogador.x - pos.x)<500 && abs(posiJogador.y - pos.y)<50)))
		{
			persegueJogador(posiJogador, 0.1);

			if(atacar==true)
			{
				//persegueJogador(posiJogador, 0.1);
				ataque(posiJogador);
				contador++;
			}

			/*if(arma->getMagvar() == 0)
				arma->setRecarregando(1);*/
		}
		/*else if((abs(posiJogador.x - pos.x)<1000 && abs(posiJogador.y - pos.y)<200) && corre == true)
			persegueJogador(posiJogador);*/

		/*else
		{
			movimentoAleatorio();
			atacar = false;
		}*/
		if(contador==3)
		{
			atacar = false;
			contador = 0;
		}

		dt = relogio.getElapsedTime().asSeconds();
    	if(dt>=2)
    	{
        	relogio.restart();
        	atacar = true;
    	}


				//cair();

		pos.y = pos.y + vel.y;
		pos.x = pos.x + vel.x;

		corpo.setPosition(pos.x, pos.y);
		verifImg();

		vel.x = 0;
	}
}

void Soldado::afastar(sf::Vector2f posiJogador)
{
	int v;
	v = 3;

    vel.x = 0.0;

	if((posiJogador.x - pos.x)<0) {  vel.x = vel.x + v; }

    else if((posiJogador.x - pos.x)>0) { vel.x = vel.x - v; }

	//if(vel.y==0) { vel.y = -2; }
}

void Soldado::viradoEsq()
{
	corpo.setTexture(Tesq);
	if(skin==1){
		corpo.setTextureRect(sf::IntRect(0, 0, 329, 369));
	}
	else{
		corpo.setTextureRect(sf::IntRect(0, 0, 367, 338));
	}
}
void Soldado::viradoDir()
{
    corpo.setTexture(Tdir);
	if(skin==1){
		corpo.setTextureRect(sf::IntRect(0, 0, 331, 371));
	}
	else{
		corpo.setTextureRect(sf::IntRect(0, 0, 368, 337));
	}
}

void Soldado::ataqueDir()
{
	corpo.setTexture(Adir);
	if(skin==1){
		corpo.setTextureRect(sf::IntRect(0, 0, 399, 371));
	}
	else{
		corpo.setTextureRect(sf::IntRect(0, 0, 441, 337));
	}
}

void Soldado::ataqueEsq()
{
	corpo.setTexture(Aesq);
	if(skin==1){
		corpo.setTextureRect(sf::IntRect(0, 0, 400, 369));
	}
	else{
		corpo.setTextureRect(sf::IntRect(0, 0, 443, 337));
	}
}

Ente* Soldado::hitscan(Ente* e) {
	if (virado == 0) {
		if (((e->getPos().y <= this->getPos().y + 40 && e->getPos().y + e->getTam().y >= this->getPos().y + 40) || e->getPos().y <= this->getPos().y + 60 && e->getPos().y + e->getTam().y > this->getPos().y + 60) && (e->getPos().x + e->getTam().x > this->getPos().x + this->getTam().x - 10) && e->getPos().x < this->getPos().x + this->getTam().x + arma->getAlc()) return e;
	}
	else if (virado == 1) {
		if (((e->getPos().y <= this->getPos().y + 40 && e->getPos().y + e->getTam().y >= this->getPos().y + 40) || e->getPos().y <= this->getPos().y + 60 && e->getPos().y + e->getTam().y > this->getPos().y + 60) && (e->getPos().x < this->getPos().x - 10) && e->getPos().x + e->getTam().x > this->getPos().x - arma->getAlc()) return e;
	}
	return NULL;
}

void Soldado::ataque(sf::Vector2f posiJogador)
{
	clock_t t1 = clock();

	/*if (t1 / (float)CLOCKS_PER_SEC - arma->getTR() / (float)CLOCKS_PER_SEC > arma->getRec() && arma->getRecarregando() == 1) {
		arma->setDry(0);
		arma->setMagvar(arma->getMag());
		arma->setRecarregando(0);
	}
	else if (arma->getRecarregando() == 1) arma->setDry(1);
	if (arma->getDry() == 1) {
		s1.setBuffer(*(arma->getSomDry()));
		s1.play();
		return;
	}*/
	/*if (t1 / (float) CLOCKS_PER_SEC - arma->getClock() / (float) CLOCKS_PER_SEC < 1.0 / arma->getCad()) {
		if (virado == 0) this->setTextura(&Tdir);//mudei
		else this->setTextura(&Tesq);//mudei
		return;
	}*/
	//std::cout << t1 / (float) CLOCKS_PER_SEC << " - " << arma->getClock() / (float) CLOCKS_PER_SEC << " = " << t1 / (float) CLOCKS_PER_SEC - arma->getClock() / (float) CLOCKS_PER_SEC << "\n";
	arma->setClock(t1);
	s1.setBuffer(*(arma->getSom()));
	s1.play();
	Ente* e = NULL, *e1 = NULL;
	//int min=99999999999;
	
		e = hitscan(jogador1);
		if (e != NULL) if (static_cast <Jogador*> (e)->getVivo() == false) {
			e = NULL;
			//cont++;
		}
		if (e != NULL){ //if (fabs(e->getPos().x - this->getPos().x) < min) {
			//min = e->getPos().x - this->getPos().x;
			e1 = e;
		}
		//std::cout << e->getPos().x << "\ne.y = " << e->getPos().y << "\nj.x = " << this->getPos().x << "\nj.y = " << this->getPos().y << "\n";
		//Sleep(1000);
		//cont++;
	
	e = e1;
	/*if (e == NULL) {
		std::cout << "e == NULL.\n" ;
	}*/
	//else std::cout << "e != NULL.\n";
	//Sleep(1000);
	arma->setMagvar(arma->getMagvar() - 1);
	arma->setAmmo(arma->getAmmo() - 1);
	if (e == NULL) return;
	//std::cout << "ATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\nATIRAR FOI CHAMADO\n";

	static_cast <Jogador*> (e)->setVidas(static_cast <Jogador*> (e)->getVidas() - arma->getDano());
	
}