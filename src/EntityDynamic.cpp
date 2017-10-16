#include "..\include\EntityDynamic.h"

EntityDynamic::EntityDynamic(b2Vec2 & position, std::string textureName, b2World & world) : Entity(textureName) {
	//Body
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position = position;
	body = world.CreateBody(&bodyDef);

	//Fixture
	b2PolygonShape fixtureDef;
	fixtureDef.SetAsBox(1.f / 2.f, 1.f / 2.f);
	body->CreateFixture(&fixtureDef, 0.f);
}

EntityDynamic::~EntityDynamic() {
}
