#ifndef PHYSICAL_WORLD_H
#define PHYSICAL_WORLD_H

#include <Box2D\Box2D.h>
#include "EntityManager.h"
#include <iostream>
#include "json.hpp"
#include <fstream>

using json = nlohmann::json;

class PhysicalWorld {
private:
	b2World* world;
	EntityManager* entitiesManager;

	static float scale;
	float32 timeStep;
	int32 velocityIterations;
	int32 positionIterations;
public:
	PhysicalWorld(b2Vec2, float, float32, int32, int32);
	~PhysicalWorld();

	void step();
	void draw(sf::RenderWindow&);
	void addEntity(sf::Vector2f, std::string, bool = false, bool = false);
	void addEntity(b2Vec2, std::string, bool = false, bool = false);
	bool loadLevel(std::string);

	static b2Vec2 pixelToMeter(sf::Vector2f);
	static float pixelToMeter(float);
	static sf::Vector2f meterToPixel(b2Vec2);
	static float meterToPixel(float);
	static void setScale(const float);
};

#endif // !PHYSICAL_WORLD_H
