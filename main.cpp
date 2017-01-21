#include "screens/screens.hpp"
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

int main() {
    srand(time(NULL));

    std::vector<CScreen *> Screens;
    int screen = 0;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    ScreenMainMenu s0;
    Screens.push_back(&s0);

    GroundScene s1;
    Screens.push_back(&s1);

    while (screen >= 0) {
        screen = Screens[screen]->run(window);
    }
    return 0;
}
