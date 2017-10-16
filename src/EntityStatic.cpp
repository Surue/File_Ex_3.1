#include "..\include\EntityStatic.h"

EntityStatic::EntityStatic(b2Vec2 & position, std::string str, b2World& world) : Entity(str) {
	//Body
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position = position;
	body = world.CreateBody(&bodyDef);

	//Fixture
	b2PolygonShape fixtureDef;
	fixtureDef.SetAsBox(1.f / 2.f, 1.f / 2.f);
	body->CreateFixture(&fixtureDef, 0.f);
}

EntityStatic::~EntityStatic() {
}
