#include "gui.hpp"

namespace gui {

	tooltip::tooltip(std::string text) {
		this->text = text;
		this->rectInner = new sf::RectangleShape(sf::Vector2f(10,10));
		this->rectOuter = new sf::RectangleShape(sf::Vector2f(8,8));
		this->rectInner->setPosition(sf::Vector2f(1,1));
	}

	void tooltip::display(sf::RenderWindow &window) {
		window.draw(*rectOuter);
		window.draw(*rectInner);
	}

	tooltip::~tooltip() {
		
	}

}