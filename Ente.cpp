#include "Ente.h"
#include "GerenciadorGrafico.h"

GerenciadorGrafico* Ente::gerente = GerenciadorGrafico::getGerenciadorGrafico();

Ente::Ente(sf::Vector2f xy)
{
    pos = xy;
    //textura = new sf::Texture;
    if(!textura.loadFromFile("Midia/Imagens/Roxo.png")) std::cout << "Erro na abertura da textura roxa para o ente." << std::endl;
    else {
        std::cout << "Foi criado um ente com a textura roxa." << std::endl;
        corpo.setTexture(textura);
    }
    //corpo.setTextureRect(sf::IntRect(0, 0, 288, 370));
    corpo.setPosition(sf::Vector2f(xy.x, xy.y));
}

Ente::~Ente() {  }

void Ente::imprimir()
{
    gerente->desenhaElemento(corpo);
}

sf::Vector2f Ente::getPos() { return pos; }

sf::Sprite Ente::getCorpo() { return corpo; }

void Ente::setGerente(GerenciadorGrafico* g)
{
    gerente = g;
}

void Ente::setPos(float x, float y) {
    pos.x = x;
    pos.y = y;
    corpo.setPosition(pos);
}

void Ente::setPos(sf::Vector2f k) {
    pos = k;
    corpo.setPosition(pos);
}

sf::Vector2f Ente::getTam() {
    sf::FloatRect res = corpo.getGlobalBounds();
    float x = res.width;
    float y = res.height;
    sf::Vector2f ret(x, y);
    return ret;
}

void Ente::setTextura(sf::Texture tx) { textura = tx; }

void Ente::setTextura(string s) { textura.loadFromFile(s); }