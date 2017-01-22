#include "screens/screens.hpp"
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include "gameplay/rscentity.hpp"
#include "gameplay/recipes.hpp"

int main() {
    srand(time(NULL));

    std::vector<CScreen *> Screens;
    int screen = 0;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");



    ScreenMainMenu s0; //0
    Screens.push_back(&s0);

    GroundScene s4;
    Screens.push_back(&s4);

    SpaceScene s1(&s4); //1
    Screens.push_back(&s1);

    StarMap s2(&s1); //2
    Screens.push_back(&s2);

    ScreenPauseMenu s3; //3
    Screens.push_back(&s3);


    // SpaceScene s3;
    // Screens.push_back(&s3);



    while (screen >= 0) {
        screen = Screens[screen]->run(window);
    }
    return 0;
}
