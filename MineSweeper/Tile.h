#pragma once
#include <SFML/Graphics.hpp>
#include "DrawBatch.h"
#include "TextureManager.h"

class Tile
{
private:
	sf::Vector2f position;
	sf::Sprite sprite;
	sf::Texture texture;

	bool hidden = true;
	int num;

public:
	Tile(float x, float y);
	void setImage();

	bool isOpen();
	void open();

	int getNum();
	void setNum(int num);
	
	void draw(float offset_X, float offset_Y);
};