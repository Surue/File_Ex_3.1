#include "EntityManager.h"

EntityManager::EntityManager() {
}

EntityManager::~EntityManager() {
	delete character;
}

void EntityManager::addEntity(b2Vec2 position, std::string textureName, bool isDynamic, bool isPlayable, b2World& world) {
	if (!isDynamic) {
		entitiesList.push_back(EntityStatic(position, textureName, world));
	} else if (!isPlayable) {
		entitiesList.push_back(EntityDynamic(position, textureName, world));
	} else{
		character = new Character(position, textureName, world);
	}
}

Character & EntityManager::getCharacter() {
	return *character;
}

void EntityManager::draw(sf::RenderWindow & window) {
	for (auto entity : entitiesList) {
		entity.draw(window);
	}

	character->draw(window);
}
