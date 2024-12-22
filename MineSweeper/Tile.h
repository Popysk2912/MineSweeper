#pragma once
#include <SFML/Graphics.hpp>
#include "DrawBatch.h"
#include "TextureManager.h"
#include "Randomizer.h"

class Tile
{
private:
	sf::Vector2f position;
	sf::Sprite sprite;
	sf::Sprite flagSprite;
	sf::Texture texture;
	sf::RenderTexture* layer;

	bool hidden = true;
	bool flagged = false;
	int num;

public:
	Tile(float x, float y, float offset_X, float offset_Y);
	void setImage();

	bool isOpen();
	bool isFlagged();

	void flag();
	void open();

	int getNum();
	void setNum(int num);
	
	void draw();
};