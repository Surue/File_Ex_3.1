#include "Entity.h"
#include "PhysicalWorld.h"


Entity::Entity(std::string textureName) {
	sprite.setTexture(TextureManager::Instance().getTexture(textureName));
}

Entity::~Entity() {
}

void Entity::draw(sf::RenderWindow & window) {
	sprite.setPosition(PhysicalWorld::meterToPixel(body->GetPosition()));
	window.draw(sprite);
}
