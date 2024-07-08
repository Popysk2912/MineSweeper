#include <iostream>
#include <SFML/Graphics.hpp>

#include "debugFuncs.h"
#include "Pointers.h"
#include "TextureManager.h"
#include "Grid.h"


int main()
{   
    int offsetX = 64;
    int offsetY = 64;
    sf::RenderWindow window(sf::VideoMode(640, 640), "SFML");
    Pointers::setWindowPointer(&window);
    sf::Vector2i mPos;
    DrawBatch::initLayers(10);
    TextureManager::addTexture("assets/metal.png", "metal");
    TextureManager::addTexture("assets/bomb.png", "bomb");
    TextureManager::addTexture("assets/empty.png", "empty");
    Grid g(16, 16);

  
 
    while (window.isOpen())
    {
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

        mPos = sf::Mouse::getPosition(window);

        DrawBatch::clear();
        window.clear();
       
        g.draw(0, 0);
       
        DrawBatch::draw(window);
        window.display();
    }
    DrawBatch::deleteLayers();
    return 0;
}