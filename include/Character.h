#ifndef ENTITY_PLAYABLE_H
#define ENTITY_PLAYABLE_H

#include "EntityDynamic.h"

class Character : public EntityDynamic {
private:
	enum moveState {
		IDLE,
		LEFT,
		RIGHT,
		JUMP,
		IN_AIR
	};

	moveState state;
	float speed;
public:
	Character(b2Vec2&, std::string, b2World&);
	~Character();

	void handleEvent(sf::Event& event);
	void update();
};

#endif // !ENTITY_PLAYABLE_H
