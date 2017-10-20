#include <iostream>
#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>

#include "PhysicalWorld.h"
#include "TextureManager.h"

#include "json.hpp"

/*
	TO DO:
	enum avec un state qui est mis en place par rapport au déplacement en cours du character plus bas
	possible de mettre genre IDLE, LEFT, RIGHT, JUMP
*/

int main() {
	bool isJumping = false;
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

	//Get the character player
	Character& character = world.getCharacter();

	/*
		TO DO:
		Instancié l'état du character
	*/

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

				/*
					TO DO:
					- Récupérer les touches lorsqu'elles sont pressée
					- Récupére quand les touches sont relâchées
					par rapport aux touche le state du character sera changé
				*/
			}
		}

		/*
			TO DO:
			- Machine d'état, elle passe par les états du character et par rapport à son état elle va réagir
			- gestion des forces horizontales. Elles dépendent de si on va à gauche ou à droite
			- gestion des forces verticales. Elles dépendent de si on appui sur le bouton jump
			- Envoié un vecteur de force composé de la force hoirizontal et vertical au character

			Pour appliquer ou récupérer des forces, va voir les fonctions dans la class EntityDynamic, les noms de 
			fonctions sont les mêmes que ceux utilisé par Box2D, du coup si tu veux savoir comment elles marchent
			il te suffit d'aller sur le site iforce2d.net il a un bon tuto
		*/

		//Clear - Draw all entity - Display
		window.clear();
		world.draw(window);
		window.display();
	}

	system("pause");
	return EXIT_SUCCESS;
}