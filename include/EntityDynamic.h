#ifndef ENTITY_DYNAMIC_H
#define ENTITY_DYNAMIC_H

#include "Entity.h"

class EntityDynamic : public Entity {
private:
public:
	EntityDynamic(b2Vec2&, std::string, b2World&);
	~EntityDynamic();

	void setLinearVelocity(b2Vec2);
	void applyForce(b2Vec2);
	void applyLinearImpulse(b2Vec2);
	b2Vec2 getLinearVelocity();
	float getMass();
};
#endif // !ENTITY_DYNAMIC_H
