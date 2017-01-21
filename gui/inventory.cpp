#include "gui.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace gui {

	inventory::inventory(int width, int height) {
		this->rects = std::vector<sf::RectangleShape*>();
		this->floatrects = std::vector<sf::FloatRect>();
		int x = 200;
		int y = 200;
		for(int i=0; i < 10; i++) {
			this->rects.push_back(new sf::RectangleShape(sf::Vector2f(width, height)));
			this->rects[i]->setFillColor(sf::Color::Red);
			if(i == 4) {
				this->rects[i]->setPosition(sf::Vector2f(x,y));
				x = 200;
				y += 80;
			} else {
				this->rects[i]->setPosition(sf::Vector2f(x,y));
				x += 80;
			}
			this->floatrects.push_back(this->rects[i]->getGlobalBounds());
		}
	}

	void inventory::display(sf::RenderWindow &window) {
		for(int i=0; i < 10; i++) {
			window.draw(*this->rects[i]);
		}
	}

	void inventory::check(sf::RenderWindow &window) {
		for(int i=0; i < 10; i++) {
			if(this->floatrects[i].contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y)) {
				if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
					std::cout << "Slot pressed: " << i << std::endl;
				}
			}
		}
	}

	inventory::~inventory() {

	}
}