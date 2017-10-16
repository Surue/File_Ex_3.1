#ifndef ENTITY_DYNAMIC_H
#define ENTITY_DYNAMIC_H

#include "Entity.h"

class EntityDynamic : public Entity {
private:
public:
	EntityDynamic(b2Vec2&, std::string, b2World&);
	~EntityDynamic();
};
#endif // !ENTITY_DYNAMIC_H
