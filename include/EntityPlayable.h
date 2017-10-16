#ifndef ENTITY_PLAYABLE_H
#define ENTITY_PLAYABLE_H

#include "EntityDynamic.h"

class EntityPlayable : public EntityDynamic {
private:
public:
	EntityPlayable(b2Vec2&, std::string, b2World&);
	~EntityPlayable();
};

#endif // !ENTITY_PLAYABLE_H
