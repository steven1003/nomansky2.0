#include "gui.hpp"
#include <iostream>

namespace gui {

	tooltip::tooltip(std::string text, int width, int height, int posx, int posy) {
		this->text = text;
		this->rectInner = new sf::RectangleShape(sf::Vector2f(width-4,height-4));
		this->rectOuter = new sf::RectangleShape(sf::Vector2f(width,height));
		this->rectInner->setPosition(sf::Vector2f(posx+2,posy+2));
		this->rectOuter->setPosition(sf::Vector2f(posx, posy));
		this->rectOuter->setFillColor(sf::Color::Red);
	}

	void tooltip::display(sf::RenderWindow &window) {
		window.draw(*rectOuter);
		window.draw(*rectInner);
	}

	tooltip::~tooltip() {
		
	}

}