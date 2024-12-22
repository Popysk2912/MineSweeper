#include "DrawBatch.h"


std::vector<sf::RenderTexture*> DrawBatch::layers;

sf::RenderTexture* DrawBatch::getLayer(unsigned int index)
{
	return layers[index];
}

void DrawBatch::initLayers(unsigned int layersNum)
{
	for (int i = 0; i <= layersNum; i++)
	{
		sf::RenderTexture* layer = new sf::RenderTexture();
		layer->create(Pointers::getWindowPointer()->getSize().x, Pointers::getWindowPointer()->getSize().y);
		layers.push_back(layer);
	}
}

void DrawBatch::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < layers.size(); i++)
	{
		layers[i]->display();	
		sf::Sprite sprite(layers[i]->getTexture());
		window.draw(sprite);
	}
}

void DrawBatch::clear()
{
	for (int i = 0; i < layers.size(); i++)
	{
		layers[i]->clear();
	}
}

void DrawBatch::deleteLayers()
{
	for (int i = 0; i < layers.size(); i++)
	{
		delete layers[i];
	}
}