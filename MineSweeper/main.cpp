#include <iostream>
#include <SFML/Graphics.hpp>

#include "debugFuncs.h"
#include "Pointers.h"
#include "TextureManager.h"
#include "Grid.h"

#define FPS 60
#define OFFSET_X 64
#define OFFSET_Y 64

sf::Texture renderTextureToTexture(const sf::RenderTexture& renderTexture) {
    sf::Vector2u size = renderTexture.getSize();
    sf::Texture texture;
    texture.create(size.x, size.y);
    sf::Image image = renderTexture.getTexture().copyToImage();
    image.flipVertically();
    texture.update(image);
    return texture;
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
    TextureManager::addTexture("assets/flag.png", "flag");
}

void restart(Grid& g, int& mines, int& flags)
{
    g = Grid(16, 16, OFFSET_X, OFFSET_Y);
    mines = g.getMines();
    flags = g.getFlags();
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 640), "MineSweeper");
    window.setFramerateLimit(FPS);
    Pointers::setWindowPointer(&window);
    DrawBatch::initLayers(10);
    LoadTextures();

    sf::Font font;
    if (!font.loadFromFile("assets/p_emu.otf")) {
        return EXIT_FAILURE;
    }

    sf::Text text;
    text.setPosition(528, 16);
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);

    sf::RectangleShape rect(sf::Vector2f(64, 32));
    rect.setPosition(512, 16);
    rect.setFillColor(sf::Color::Black);

    sf::Sprite frame;
    frame.setTexture(TextureManager::getTexture("frame"));
    frame.setPosition(0, 0);

    sf::Vector2i mPos;
    Grid g(16, 16, OFFSET_X, OFFSET_Y);
    sf::RenderTexture* layer0 = DrawBatch::getLayer(0);
    int mines = g.getMines();
    int flags = g.getFlags();

    bool leftMousePressed = false;
    bool rightMousePressed = false;

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
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::R) {
                restart(g, mines, flags);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (!leftMousePressed) {
                leftMousePressed = true;
                int x = static_cast<int>(mPos.x / 32);
                int y = static_cast<int>(mPos.y / 32);

                if (g.openCell(x, y) == -1) {
                    g.openAll();
                }
            }
        }
        else {
            leftMousePressed = false;
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
            if (!rightMousePressed) {
                rightMousePressed = true;
                int x = static_cast<int>(mPos.x / 32);
                int y = static_cast<int>(mPos.y / 32);

                g.setFlag(x, y);
            }
        }
        else {
            rightMousePressed = false;
        }

        int mines = g.getMines();
        int flags = g.getFlags();
        text.setString(std::to_string(mines - flags));

        layer0->draw(frame);
        g.draw();
        layer0->draw(rect);
        layer0->draw(text);

        sf::Texture texture = renderTextureToTexture(*layer0);
        sf::Sprite sprite;
        sprite.setTexture(texture);

        window.draw(sprite);
        window.display();
    }
    DrawBatch::deleteLayers();
    return 0;
}
