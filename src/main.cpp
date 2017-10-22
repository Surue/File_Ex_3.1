#include <iostream>
#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>

#include "PhysicalWorld.h"
#include "TextureManager.h"

#include "json.hpp"
#include <fstream>

int main() {
	json j;

	std::ifstream file("data/json/data.json");
	if (!file) {
		std::cout << "ERROR: File not found.\n";
		system("pause");
		return EXIT_FAILURE;
	}

	j << file;

	bool isJumping = false;
	//Add folder containing images to the TextureManager
	TextureManager::Instance().addResourceDirectory("data/image/");

	//SFML - Window Instanciation
	sf::RenderWindow window(sf::VideoMode(j["window_x"], j["window_y"]), j["title"].get<std::string>());
	window.setFramerateLimit(j["framerate"]);
	
	//Box2D - Initialise world
	b2Vec2 gravity(0.f, (float)j["gravity"]);
	PhysicalWorld world(gravity, 1.f / (float)j["scale"], 1 / (float)j["framerate"], (int32)j["velocityIteration"], (int32)j["positionIteration"]);
	if (!world.loadLevel("data/json/level_0.json")) {
		window.close();
		system("pause");
		return EXIT_FAILURE;            
	}

	//Get the character player
	Character& character = world.getCharacter();

	while (window.isOpen()) {
		world.step();

		sf::Event event;
		while (window.pollEvent(event)) {
			character.handleEvent(event);
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				switch (event.key.code) {
				case sf::Keyboard::Escape:
					window.close();
					break;
				}

			}
		}

		character.update();

		window.clear();
		world.draw(window);
		window.display();
	}

	system("pause");
	return EXIT_SUCCESS;
}