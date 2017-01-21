#include "screenpausemenu.hpp"
#include <SFML/Graphics.hpp>

ScreenPauseMenu::ScreenPauseMenu() {}

int ScreenPauseMenu::run(sf::RenderWindow &window) {
    sf::Event Event;
    sf::Font font;
    if(!font.loadFromFile("rsc/font.ttf"))
    {
      return EXIT_FAILURE;
    }
    sf::Text title("Pause Menu", font, 50);
    title.setPosition(275, 10);

    sf::Text o1("Continue",font, 35);
    o1.setPosition(325, 100);

	sf::Text o2("Main Menu",font, 35);
    o2.setPosition(325, 150);

	sf::Text o3("Options",font, 35);
    o3.setPosition(325, 200);

	sf::Text o4("Quit",font, 35);
    o4.setPosition(325, 250);

    while (window.isOpen()) {
        while (window.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed) {
                return (-1);
            }
            else if (Event.type == sf::Event::KeyPressed) {
                switch (Event.key.code) {
                case sf::Keyboard::Escape:
                    return 1; //Goes back to the game
                }
            }
        }

        window.clear(sf::Color(0, 0, 0, 0));
        window.draw(title);
        window.draw(o1);
        window.draw(o2);
        window.draw(o3);
        window.draw(o4);
        window.display();

    }

    return (-1);
}
ScreenPauseMenu::~ScreenPauseMenu()
{

}
