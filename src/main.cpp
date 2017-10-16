#include <iostream>
#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>

#include "PhysicalWorld.h"
#include "TextureManager.h"

#include "json.hpp"

int main() {
	//Add folder containing images to the TextureManager
	TextureManager::Instance().addResourceDirectory("data/image/");

	//SFML - Window Instanciation
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Exercice 3.1");
	window.setFramerateLimit(60);

	//Box2D - Initialise world
	b2Vec2 gravity(0.f, 9.81f);
	PhysicalWorld world(gravity, 1.f/64.f, 1/60.f, (int32)8, (int32)3);
	if (!world.loadLevel("data/json/level_0.json")) {
		window.close();
		system("pause");
		return EXIT_FAILURE;
	}

	while (window.isOpen()) {
		world.step();

		sf::Event event;
		while (window.pollEvent(event)) {
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
				break;
			}
		}

		window.clear();
		world.draw(window);
		window.display();
	}

	system("pause");
	return EXIT_SUCCESS;
}