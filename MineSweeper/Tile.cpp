#include "Tile.h"

const int BOMB_CHANÑE = 10;

Tile::Tile(float x, float y, float offset_X, float offset_Y)
{
    flagSprite.setTexture(TextureManager::getTexture("flag"));
    position = sf::Vector2f(x, y);
    sprite.setPosition(sf::Vector2f(position.x + offset_X, position.y + offset_Y));
    flagSprite.setPosition(sf::Vector2f(position.x + offset_X, position.y + offset_Y));
    layer = DrawBatch::getLayer(0);
    int rn = Randomizer<int>::generate(1, 100);
    if(rn >= 100-BOMB_CHANÑE)
    {
        num = -1;
    }
    else
    {
        num = 0;
    }
    this->setImage();
}

void Tile::draw()
{
    if(hidden)
    {
        sprite.setTexture(TextureManager::getTexture("metal"));
    }
    else
    {
        sprite.setTexture(texture);
    }
    layer->draw(sprite);
    if(flagged)
    {
        layer->draw(flagSprite);
    }
}

void Tile::flag()
{
    flagged = !flagged;
}

void Tile::open()
{
    flagged = false;
    hidden = false;
}

void Tile::setImage()
{
    switch (num)
    {
    default:
        break;
    case -1:
        texture = TextureManager::getTexture("bomb");
        break;
    case 0:
        texture = TextureManager::getTexture("empty");
        break;
    case 1:
        texture = TextureManager::getTexture("1");
        break;
    case 2:
        texture = TextureManager::getTexture("2");
        break;
    case 3:
        texture = TextureManager::getTexture("3");
        break;
    case 4:
        texture = TextureManager::getTexture("4");
        break;
    case 5:
        texture = TextureManager::getTexture("5");
        break;
    case 6:
        texture = TextureManager::getTexture("6");
        break;
    case 7:
        texture = TextureManager::getTexture("7");
        break;
    case 8:
        texture = TextureManager::getTexture("8");
        break;
    }
}

int Tile::getNum()
{
    return num;
}

bool Tile::isOpen()
{
    return !hidden;
}

bool Tile::isFlagged()
{
    return flagged;
}

void Tile::setNum(int num)
{
    this->num = num;   
}