#include "..\include\Character.h"
#include <iostream>

Character::Character(b2Vec2 & position, std::string textureName, b2World & world) : EntityDynamic(position, textureName, world) {
}

Character::~Character() {
}


