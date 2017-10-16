#include "EntityManager.h"

EntityManager::EntityManager() {
}

EntityManager::~EntityManager() {
}

void EntityManager::addEntity(b2Vec2 position, std::string textureName, bool isDynamic, bool isPlayable, b2World& world) {
	if (!isDynamic) {
		entitiesList.push_back(EntityStatic(position, textureName, world));
	} else if (!isPlayable) {
		entitiesList.push_back(EntityDynamic(position, textureName, world));
	} else{
		entitiesList.push_back(EntityPlayable(position, textureName, world));
	}
}

void EntityManager::draw(sf::RenderWindow & window) {
	for (auto entity : entitiesList) {
		entity.draw(window);
	}
}
