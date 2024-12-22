#include "TextureManager.h"

std::unordered_map<std::string, sf::Texture> TextureManager::textures;

void TextureManager::addTexture(const std::string& path, const std::string& name)
{
	sf::Texture texture;
	if (!texture.loadFromFile(path))
	{

	}
	else
	{
		textures[name] = std::move(texture);
	}
}

sf::Texture& TextureManager::getTexture(std::string name)
{
	if(textures.count(name) > 0)
	{
		return textures[name];
	}
	else
	{
		return textures["none"];
	}
}