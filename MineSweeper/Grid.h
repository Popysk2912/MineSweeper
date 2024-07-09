#pragma once
#include <vector>

#include <SFML/Graphics.hpp>

#include "Tile.h"
#include "DrawBatch.h"

class Grid {
public:
    Grid(unsigned int size_x, unsigned int size_y);
    void draw(float offset_X, float offset_Y);
    void openCell(int x, int y);

private:
    void setNums();
    int checkBombs(int x, int y);
    
    std::vector<std::vector<std::unique_ptr<Tile>>> grid;
};