#include "Tile.h"

const int BOMB_CHANSE = 25;

Tile::Tile(float x, float y)
{
    position = sf::Vector2f(x, y);
    int rn = rand() % 100;
    if(rn >= 100-BOMB_CHANSE)
    {
        num = -1;
    }
    else
    {
        num = 0;
    }
    this->setImage();
}

void Tile::draw(float offset_X, float offset_Y)
{
    sprite.setPosition(sf::Vector2f(position.x+offset_X, position.y + offset_Y));
    sf::RenderTexture* layer = DrawBatch::getLayer(0);
    if(hidden)
    {
        sprite.setTexture(TextureManager::getTexture("metal"));
    }
    else
    {
        sprite.setTexture(texture);
    }
    layer->draw(sprite);
    layer->display();
}

void Tile::open()
{
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

void Tile::setNum(int num)
{
    this->num = num;   
}