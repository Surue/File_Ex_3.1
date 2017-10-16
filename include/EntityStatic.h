#ifndef ENTITY_STATIC_H
#define ENTITY_STATIC_H

#include "Entity.h"

class EntityStatic : public Entity{
private:
public:
	EntityStatic(b2Vec2&, std::string, b2World&);
	~EntityStatic();
};
#endif // !ENTITY_STATIC_H
