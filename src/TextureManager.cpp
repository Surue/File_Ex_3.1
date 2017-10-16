#include <map>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"

TextureManager TextureManager::instance = TextureManager();

TextureManager::TextureManager() : texturesMap(), resourceDirectories() {
}

TextureManager::~TextureManager() {
	texturesMap.clear();
	resourceDirectories.clear();
}

const sf::Texture& TextureManager::getTexture( const std::string& filename ) {
	// Check, whether the image already exists
	for( auto it = texturesMap.begin(); it != texturesMap.end(); ++it) {
		if( filename == it->first ) {
			return it->second;
		}
	}
	
	// The image doesen't exists. Create it and save it.
	sf::Texture texture;

	// Search project's main directory
	if( texture.loadFromFile( filename ) ) {
		texturesMap[filename] = texture;
		return texturesMap[filename];
	}

	// If the image has still not been found, search all registered directories
	for( auto it = resourceDirectories.begin(); it != resourceDirectories.end(); ++it) {
		if( texture.loadFromFile( (*it) + filename )) {
			texturesMap[filename] = texture;
			std::cout << "DEBUG_MESSAGE: " << filename << " loading image.\n";
			return texturesMap[filename];
		}
	}

	std::cout << "GAME_ERROR: Image was not found. It is filled with an empty image.\n";
	texturesMap[filename] = texture;
	return texturesMap[filename];
}

void TextureManager::deleteTexture( const sf::Texture& image ) {
	for(auto it = texturesMap.begin(); it != texturesMap.end(); ++it) {
		if( &image == &it->second ) {
			texturesMap.erase( it );
			return;
		}
	}
}

void TextureManager::deleteTexture( const std::string& filename ) {
	auto it = texturesMap.find( filename );
	if (it != texturesMap.end()) {
		texturesMap.erase(it);
	}
}

void TextureManager::addResourceDirectory( const std::string& directory ) {
	// Check whether the path already exists
	for(auto it  = resourceDirectories.begin(); it != resourceDirectories.end(); ++it) {
		// The path exists. So it isn't necessary to add id once more.
		if (directory == (*it)) {
			return;
		}
	}

	// insert the directory
	resourceDirectories.push_back( directory );
}

void TextureManager::removeResourceDirectory( const std::string& directory ) {
	for(auto it  = resourceDirectories.begin(); it != resourceDirectories.end(); ) {
		// The path exists. So it isn't necessary to add id once more.
		if (directory == (*it)) {
			it = resourceDirectories.erase(it);
		}
		else {
			++it;
		}
	}
}

TextureManager & TextureManager::Instance() {
	return instance;
}
