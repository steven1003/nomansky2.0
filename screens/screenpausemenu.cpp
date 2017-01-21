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

    sf::FloatRect op1 = o1.getGlobalBounds();
    sf::FloatRect op2 = o2.getGlobalBounds();
    sf::FloatRect op3 = o3.getGlobalBounds();
    sf::FloatRect op4 = o4.getGlobalBounds();

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
        if(op1.contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y))
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                return 1;
            }
        }

        if(op2.contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y))
        {
             if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                return 0;
            }
        }

        if(op3.contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y))
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                //Will open the options screen when ready
                std::cout << "Button 3 Works!" << std::endl;
            }
        }

        if(op4.contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y))
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                return -1;
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
