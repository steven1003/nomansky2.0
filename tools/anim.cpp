#include "anim.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Anim::Anim(std::string fileLocation, int width, int height, int parts, bool anim) {
	this->texture = new sf::Texture();
	this->texture->loadFromFile(fileLocation);
	this->width = width;
	this->height = height;
	this->parts = parts;
	this->anim = anim;
	this->rect = new sf::IntRect(width, 0, width, height);
	this->sprite = new sf::Sprite(*texture, *rect);
}

sf::Sprite Anim::getSprite() {
	return *(this->sprite);
}

void Anim::setTextureRect(int part) {
	rect->left = part * (this->width);
	sprite->setTextureRect(*rect);
}

Anim::~Anim() {

}