#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>


class TextureManager
{
private:
	static std::unordered_map<std::string, sf::Texture> textures;
public:
	static void addTexture(const std::string& path, const std::string& name);
	static sf::Texture& getTexture(std::string name);

	TextureManager() = default;
};