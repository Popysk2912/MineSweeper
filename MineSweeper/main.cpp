#include <iostream>
#include <SFML/Graphics.hpp>

#include "debugFuncs.h"
#include "Pointers.h"
#include "TextureManager.h"
#include "Grid.h"


static int OFFSET_X = 64;
static int OFFSET_Y = 64;

void LoadTextures()
{
    TextureManager::addTexture("assets/none.png", "none");
    TextureManager::addTexture("assets/metal.png", "metal");
    TextureManager::addTexture("assets/bomb.png", "bomb");
    TextureManager::addTexture("assets/empty.png", "empty");
    for (int i = 1; i <= 8; i++)
    {
        std::string filename = "assets/" + std::to_string(i) + ".png";
        std::string name = std::to_string(i);
        TextureManager::addTexture(filename, name);
    }
}

int main()
{   
    sf::RenderWindow window(sf::VideoMode(640, 640), "MineSweeper");
    Pointers::setWindowPointer(&window);
    DrawBatch::initLayers(10);
    LoadTextures();

    sf::Vector2i mPos;
    Grid g(16, 16);

    while (window.isOpen())
    {
        mPos = sf::Mouse::getPosition(window);
        mPos.x -= OFFSET_X;
        mPos.y -= OFFSET_X;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                int x = static_cast<int>(mPos.x / 32);
                int y = static_cast<int>(mPos.y / 32);

                g.openCell(x, y);
            }

        }
        /***************Drawing***************/
        DrawBatch::clear();
        window.clear();
       
        g.draw(OFFSET_X, OFFSET_Y);
       
        DrawBatch::draw(window);
        window.display();
        /***************Drawing***************/
    }
    DrawBatch::deleteLayers();
    return 0;
}