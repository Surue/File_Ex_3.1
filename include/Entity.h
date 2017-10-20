#ifndef ENTITY_H
#define ENTITY_H

#include <Box2D\Box2D.h>
#include <string>
#include <SFML\Graphics.hpp>

#include "TextureManager.h"
#include <iostream>

class Entity {
protected:
	b2Body* body;
	sf::Sprite sprite;
public:
	Entity(std::string);
	virtual ~Entity();

	void draw(sf::RenderWindow&);

	b2Vec2 getPosition();
};

#endif // !ENTITY_H
