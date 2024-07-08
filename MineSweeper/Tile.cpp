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
        texture = TextureManager::getTexture("bomb");
        num = -1;
    }
    else
    {
        
        isBomb = false;
        texture = TextureManager::getTexture("empty");
        num = 0;
    }
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

int Tile::getNum()
{
    return num;
}

