#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <memory>
#include <stdexcept>
#include <string>

class Anim {
public:
    Anim();
    void init(std::string fileLocation, int width, int height, int parts, bool anim);
    virtual ~Anim();
    sf::Sprite getSprite();
    void setTextureRect(int part);
    void setPosition(sf::Vector2f &pos);
private:
	sf::Texture* texture;
	int width;
	int height;
	int parts;
	bool anim;
	sf::IntRect* rect;
	sf::Sprite* sprite;
};

#endif
