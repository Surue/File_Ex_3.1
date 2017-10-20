#include "..\include\PhysicalWorld.h"

float PhysicalWorld::scale = 0.f;

PhysicalWorld::PhysicalWorld(b2Vec2 gravity, float scale, float32 timeStep, int32 velocityIterations, int32 positionIterations) : 
	timeStep(timeStep), velocityIterations(velocityIterations), positionIterations(positionIterations) {
	world = new b2World(gravity);
	entitiesManager = new EntityManager();
	setScale(scale);
}

PhysicalWorld::~PhysicalWorld() {
	delete entitiesManager;
	delete world;
}

void PhysicalWorld::step() {
	world->Step(timeStep, velocityIterations, positionIterations);
}

void PhysicalWorld::draw(sf::RenderWindow& window) {
	entitiesManager->draw(window);
}

void PhysicalWorld::addEntity(sf::Vector2f position, std::string textureName, bool isDynamic, bool isPlayable) {
	if (!isDynamic && isPlayable) {
		std::cout << "ERROR: A entity can't be playable if is static.\n";
		return;
	}
	entitiesManager->addEntity(pixelToMeter(position), textureName, isDynamic, isPlayable, *world);
}

void PhysicalWorld::addEntity(b2Vec2 position, std::string textureName, bool isDynamic, bool isPlayable) {
	if (!isDynamic && isPlayable) {
		std::cout << "ERROR: A entity can't be playable if is static.\n";
		return;
	}
	entitiesManager->addEntity(position, textureName, isDynamic, isPlayable, *world);
}

bool PhysicalWorld::loadLevel(std::string levelPath) {
	std::ifstream file(levelPath);

	if (!file) {
		std::cout << "File failed to open";
		return false;
	}

	json j;
	file >> j;

	//Read all the file
	for (auto it = j.begin(); it != j.end(); ++it) {
		
		//tmp value, only purpuse is to create a new Entity
		bool coordIsInBox2D = true;
		std::string tmpTexture;
		std::map<std::string, float> tmpEntity;
		 
		//Read only one input
		for (auto entity = it.value().begin(); entity != it.value().end(); ++entity) {
			if (entity.key() == "textureName") {
				tmpTexture = entity.value().get<std::string>();
			} else if (entity.key() == "typeCoord") {
				if (entity.value().get<std::string>() != "Box2D") {
					coordIsInBox2D = false;
				}
			} else {
				tmpEntity.insert(std::pair<std::string, float>(entity.key(), entity.value().get<float>()));
			}
		}
		
		//Complete data if something is missing
		if (tmpEntity.find("isDynamic") == tmpEntity.end()) {
			tmpEntity.insert(std::pair<std::string, float>("isDynamic", 0));
		}

		if (tmpEntity.find("isPlayable") == tmpEntity.end()) {
			tmpEntity.insert(std::pair<std::string, float>("isPlayable", 0));
		}

		//Add entity depending on coordinates
		if (coordIsInBox2D) {
			addEntity(
				b2Vec2(tmpEntity.find("x")->second, tmpEntity.find("y")->second),
				tmpTexture,
				(bool)tmpEntity.find("isDynamic")->second,
				(bool)tmpEntity.find("isPlayable")->second
			);
		} else {
			std::cout << "OCU\n";
			addEntity(
				sf::Vector2f(tmpEntity.find("x")->second, tmpEntity.find("y")->second),
				tmpTexture,
				(bool)tmpEntity.find("isDynamic")->second,
				(bool)tmpEntity.find("isPlayable")->second
			);
		}
	}

	return true;
}

Character & PhysicalWorld::getCharacter() {
	return entitiesManager->getCharacter();
}

b2Vec2 PhysicalWorld::pixelToMeter(sf::Vector2f vect) {
	return b2Vec2(vect.x * scale, vect.y * scale);
}

float PhysicalWorld::pixelToMeter(float pixels) {
	return pixels * scale;
}

sf::Vector2f PhysicalWorld::meterToPixel(b2Vec2 vect) {
	return sf::Vector2f(vect.x / scale, vect.y / scale);
}

float PhysicalWorld::meterToPixel(float meters) {
	return meters / scale;
}

void PhysicalWorld::setScale(const float newScale) {
	scale = newScale;
}
