#include "..\include\EntityPlayable.h"

EntityPlayable::EntityPlayable(b2Vec2 & position, std::string textureName, b2World & world) : EntityDynamic(position, textureName, world) {
}

EntityPlayable::~EntityPlayable() {
}
