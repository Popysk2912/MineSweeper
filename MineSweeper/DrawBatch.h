#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Pointers.h"

class DrawBatch
{
private:
	static std::vector<sf::RenderTexture*> layers;

public:
	static sf::RenderTexture* getLayer(unsigned int index);
	static void initLayers(unsigned int layersNum);
	static void draw(sf::RenderWindow& window);
	static void clear();
	static void deleteLayers();
};