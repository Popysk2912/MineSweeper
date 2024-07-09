#include <iostream>
#include <SFML/Graphics.hpp>

#include "debugFuncs.h"
#include "Pointers.h"
#include "TextureManager.h"
#include "Grid.h"


static float OFFSET_X = 64;
static float OFFSET_Y = 64;

void restart(Grid& g)
{
    g = Grid(16, 16);
}


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
    TextureManager::addTexture("assets/frame.png", "frame");
}

int main()
{   
    sf::RenderWindow window(sf::VideoMode(640, 640), "MineSweeper");
    Pointers::setWindowPointer(&window);
    DrawBatch::initLayers(10);
    LoadTextures();

    sf::Sprite frame;
    frame.setTexture(TextureManager::getTexture("frame"));
    frame.setPosition(0, 0);


    sf::Vector2i mPos;
    Grid g(16, 16);
    sf::RenderTexture* layer0 = DrawBatch::getLayer(0);
    

    while (window.isOpen())
    {
        mPos = sf::Mouse::getPosition(window);
        mPos.x -= static_cast<int>(OFFSET_X);
        mPos.y -= static_cast<int>(OFFSET_Y);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                int x = static_cast<int>(mPos.x / 32);
                int y = static_cast<int>(mPos.y / 32);

                if (g.openCell(x, y) == -1) 
                {
                    g.openAll();
                };
            }
            if (event.type == sf::Event::KeyPressed) 
            {
                if (event.key.code == sf::Keyboard::Key::R) {
                    // Действие при нажатии клавиши A
                    restart(g);
                }
            }

        }
        /***************Drawing***************/
        DrawBatch::clear();
        window.clear();
       
        layer0->draw(frame);
        g.draw(OFFSET_X, OFFSET_Y);

        DrawBatch::draw(window);
        window.display();
        /***************Drawing***************/
    }
    DrawBatch::deleteLayers();
    return 0;
}