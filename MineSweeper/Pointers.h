#pragma once
#include <SFML/Graphics.hpp>


class Pointers
{
    
    static sf::RenderWindow* window_p;
public:
    static void setWindowPointer(sf::RenderWindow* p)
    {
        window_p = p;
    }

    static sf::RenderWindow* getWindowPointer()
    {
        return window_p;
    }
};

