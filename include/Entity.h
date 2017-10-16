#ifndef ENTITY_H
#define ENTITY_H

#include <Box2D\Box2D.h>
#include <string>
#include <SFML\Graphics.hpp>

#include "TextureManager.h"

class Entity {
protected:
	b2Body* body;
	sf::Sprite sprite;
public:
	Entity(std::string);
	~Entity();

	void draw(sf::RenderWindow&);
};

#endif // !ENTITY_H
