#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27
#define TAB 9

class Textbox {
private:
	sf::Text textbox;
	std::ostringstream text;
	bool isSelected;
	bool hasLimit;
	int limit;
	void inputLogic(int charTyped);
	void backspace();

public:
	Textbox();
	Textbox(int size, sf::Color color, bool sel);
	~Textbox();
	void setFont(sf::Font* font);
	void setPosition(sf::Vector2f pos);
	void setLimit(bool l, int lim);
	void setSelected(bool sel);
	std::string getText();
	void draw(sf::RenderWindow* w);
	void digitar(sf::Event input);
	void setText(std::string s);
};