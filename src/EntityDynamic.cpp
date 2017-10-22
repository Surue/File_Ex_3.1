#include "..\include\EntityDynamic.h"

EntityDynamic::EntityDynamic(b2Vec2 & position, std::string textureName, b2World & world) : Entity(textureName) {
	//Body
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position = position;
	body = world.CreateBody(&bodyDef);

	//Fixture
	b2CircleShape circleShape;
	circleShape.m_p.Set(0, 0); //position, relative to body position
	circleShape.m_radius = 0.5; //radius

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &circleShape;
	body->CreateFixture(&fixtureDef);
}

EntityDynamic::~EntityDynamic() {
}

void EntityDynamic::setLinearVelocity(b2Vec2 vect) {
	body->SetLinearVelocity(vect);
}

void EntityDynamic::applyForce(b2Vec2 vect) {
	body->ApplyForce(vect, body->GetWorldCenter(), true);
}

void EntityDynamic::applyLinearImpulse(b2Vec2 vect) {
	body->ApplyLinearImpulse(vect, body->GetWorldCenter(), true);
}

b2Vec2 EntityDynamic::getLinearVelocity() {
	return body->GetLinearVelocity();
}

float EntityDynamic::getMass() {
	return body->GetMass();
}
