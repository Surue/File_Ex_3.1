#include "..\include\Character.h"
#include <iostream>

Character::Character(b2Vec2 & position, std::string textureName, b2World & world) : EntityDynamic(position, textureName, world) {
	state = moveState::IDLE;
	speed = 3;
}

Character::~Character() {
}

void Character::handleEvent(sf::Event & event) {
	int keyForce = 0;
	
	if (state == moveState::IN_AIR) {
		return;
	}

	switch (event.type) {
	case sf::Event::KeyPressed:
		switch (event.key.code) {
		case sf::Keyboard::D:
		case sf::Keyboard::Right:
			state = moveState::RIGHT;
			break;

		case sf::Keyboard::A:
		case sf::Keyboard::Left:
			state = moveState::LEFT;
			break;
		}
		break;

	case sf::Event::KeyReleased:
		switch (event.key.code) {
		case sf::Keyboard::D:
		case sf::Keyboard::Right:
			state = moveState::IDLE;
			break;

		case sf::Keyboard::A:
		case sf::Keyboard::Left:
			state = moveState::IDLE;
			break;
		}
		break;

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && getLinearVelocity().y == 0) { //if velocity != 0 => is in air
		state = moveState::JUMP;
	}
}

void Character::update() {
	float acceleration = 1.f;

	if (getLinearVelocity().y == 0.0f && state == moveState::IN_AIR) {
		state = moveState::IDLE;
	}

	if (state == moveState::JUMP) {
		applyForce(b2Vec2(0.f, -450.f));
		state = moveState::IN_AIR;
	} 

	float desiredVelocity = 0;
	if (state == moveState::LEFT) {
		desiredVelocity = -5;
	} else if (state == moveState::RIGHT) {
		desiredVelocity = 5;
	} else if (state == moveState::IN_AIR) {
		desiredVelocity = getLinearVelocity().x * 0.99f;
	} else {
		desiredVelocity = getLinearVelocity().x * 0.1f;
	}
	float velocityChange = desiredVelocity - getLinearVelocity().x;
	float impulse = getMass() * velocityChange;

	applyLinearImpulse(b2Vec2(impulse, 0));
}


