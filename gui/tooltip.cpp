#include "gui.hpp"

namespace gui {

	tooltip::tooltip(std::string text) {
		this->text = text;
		this->rectInner = new sf::RectangleShape(sf::Vector2f(10,10));
		this->rectOuter = new sf::RectangleShape(sf::Vector2f(8,8));
		this->rectInner->setPosition(sf::Vector2f(1,1));
	}

	tooltip::display() {
		window.draw(rectOuter);
		window.draw(rectInner);
	}

	tooltip::~tooltip() {
		
	}

}