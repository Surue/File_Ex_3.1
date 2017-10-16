#ifndef TEXTURE_MANAGER_H_
#define TEXTURE_MANAGER_H_
class TextureManager {
private:
	TextureManager( const TextureManager& );
	TextureManager& operator =( const TextureManager& );
	std::map< std::string, sf::Texture > texturesMap;
	std::vector< std::string > resourceDirectories;

	static TextureManager instance;

	TextureManager();
	~TextureManager();


public:

	const sf::Texture& getTexture( const std::string&);
	void deleteTexture( const sf::Texture&);
	void deleteTexture( const std::string&);
	void addResourceDirectory( const std::string&);
	void removeResourceDirectory( const std::string&);

	static TextureManager& Instance();
};
#endif