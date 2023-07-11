#include "Textbox.h"


Textbox::Textbox() {}

Textbox::Textbox(int size, sf::Color color, bool sel) {
	textbox.setCharacterSize(size);
	textbox.setFillColor(color);
	isSelected = sel;
	if (sel) {
		textbox.setString("_");
	}
	else {
		textbox.setString("");
	}
}

Textbox::~Textbox() {}

void Textbox::inputLogic(int charTyped) {
	if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY && charTyped != TAB) {
		text << static_cast<char>(charTyped);
	}
	else if (charTyped == DELETE_KEY) {
		if (text.str().length() > 0) {
			backspace();
		}
	}
	textbox.setString(text.str() + "_");
}

void Textbox::backspace() {
	std::string t = text.str();
	std::string newT = "";
	for (int i = 0; i < t.length() - 1; i++) {
		newT += t[i];
	}
	text.str("");
	text << newT;
	textbox.setString(text.str());
}

void Textbox::setFont(sf::Font* f) { textbox.setFont(*f); }

void Textbox::setPosition(sf::Vector2f pos) { textbox.setPosition(pos); }

void Textbox::setLimit(bool l, int lim) { hasLimit = l; limit = lim; }

void Textbox::setSelected(bool sel) { 
	isSelected = sel;
	if (!sel) {
		std::string t = text.str();
		std::string newT = "";
		for (int i = 0; i < t.length() - 1; i++) {
			newT += t[i];
		}
		textbox.setString(newT);
	}
}

std::string Textbox::getText() { return text.str(); }

void Textbox::draw(sf::RenderWindow* w) { w->draw(textbox); }

void Textbox::digitar(sf::Event input) {
	if (isSelected) {
		int charTyped = input.text.unicode;
		if (charTyped < 128) {
			if (hasLimit) {
				if (text.str().length() <= limit) {
					inputLogic(charTyped);
				}
				else if (text.str().length() > limit && charTyped == DELETE_KEY) {
					backspace();
				}
			}
			else {
				inputLogic(charTyped);
			}
		}
	}
}

void Textbox::setText(std::string s) { textbox.setString(s); }