#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <list>
#include <SFML\Graphics.hpp>
#include "EntityDynamic.h"
#include "EntityPlayable.h"
#include "EntityStatic.h"

#include <iostream>

class EntityManager {
private:
	std::list<Entity> entitiesList;
public:
	EntityManager();
	~EntityManager();

	void addEntity(b2Vec2, std::string, bool, bool, b2World&);
	void draw(sf::RenderWindow&);
};

#endif // !ENTITY_MANAGER_H
