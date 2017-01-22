#include "gui.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace gui {

	inventory::inventory(int width, int height) {
		this->rects = std::vector<sf::RectangleShape*>();
		this->floatrects = std::vector<sf::FloatRect>();
		this->items = std::vector<RscEntity>();
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
			sf::IntRect rect = sf::IntRect(0, 0, this->rects[i]->getPosition().x, this->rects[i]->getPosition().y);
			sf::Sprite sprite = sf::Sprite(this->items[i].getTexture(), rect);
		}
	}

	bool inventory::addItem(RscEntity item) {
		for(int i=0; i < this->items.size(); i++) {
			if(item.getName() == this->items[i].getName()) {
				this->items[i].addItem(item.getNum());
				return true;
			}
		}

		if(this->items.size() == 10) {
			return false;
		} else {
			this->items.push_back(item);
			return false;
		}
	}

	bool inventory::removeItem(std::string name, int amount) {
		for(int i=0; i < this->items.size(); i++) {
			if(name == this->items[i].getName()) {
				if(this->items[i].getNum() < amount) {
					return false;
				} else {
					return true;
				}
			}
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