#ifndef ENTITY_PLAYABLE_H
#define ENTITY_PLAYABLE_H

#include "EntityDynamic.h"

class Character : public EntityDynamic {
private:
public:
	Character(b2Vec2&, std::string, b2World&);
	~Character();
};

#endif // !ENTITY_PLAYABLE_H
