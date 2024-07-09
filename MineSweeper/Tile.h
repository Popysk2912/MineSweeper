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
	bool isBomb;
	int num;
public:
	Tile(std::string& name, float x, float y);
	Tile(float x, float y);
	void setImage();
	void open();
	int getNum();
	bool isOpen()
	{
		return !hidden;
	}
	void setNum(int num)
	{
		this->num = num;
	}
	void draw(float offset_X, float offset_Y);
};

