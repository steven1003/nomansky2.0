#ifndef GUI_HPP
#define GUI_HPP

#include <SFML/Graphics.hpp>

namespace gui {

	class inventory {
	public:
		inventory(int width, int height);
		virtual ~inventory();
		void display(sf::RenderWindow &window);
		void check(sf::RenderWindow &window);
	private:
		std::vector<sf::RectangleShape* > rects;
		std::vector<sf::FloatRect> floatrects;
	};
}

#endif