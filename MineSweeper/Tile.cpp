#include "Tile.h"


Tile::Tile(std::string& name, float x, float y)
{
    position = sf::Vector2f(x, y);
    texture = TextureManager::getTexture(name);
    sprite.setTexture(TextureManager::getTexture(name));
    isBomb = 0;
    num = 0;
}

Tile::Tile(float x, float y)
{
    position = sf::Vector2f(x, y);
    int rn = rand() % 100;
    if(rn >= 90)
    {
        isBomb = true;
        num = -1;
    }
    else
    {
        isBomb = false;
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

