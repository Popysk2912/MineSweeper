#pragma once
#include <vector>

#include <SFML/Graphics.hpp>

#include "Tile.h"
#include "DrawBatch.h"

class Grid {
public:
    Grid(unsigned int size_x, unsigned int size_y);
    void setTile(std::string name, int x, int y);
    std::vector<std::unique_ptr<Tile>> getTiles();
    void openCell(int x, int y);
    void draw(float offset_X, float offset_Y);

private:
    std::vector<std::vector<std::unique_ptr<Tile>>> grid;
};

