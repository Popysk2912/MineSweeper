#include "Grid.h"

Grid::Grid(unsigned int size_x, unsigned int size_y)
{
    grid.resize(size_x);
    for (unsigned int x = 0; x < size_x; x++) {
        for (unsigned int y = 0; y < size_y; y++) {
            grid[x].emplace_back(std::make_unique<Tile>(32 * x, 32 * y));
        }
    }
}

void Grid::setTile(std::string name, int x, int y)
{

    grid[x][y] = std::make_unique<Tile>(name, 32*x, 32*y);

}

std::vector<std::unique_ptr<Tile>> Grid::getTiles()
{
    std::vector<std::unique_ptr<Tile>> tiles;
    for (const auto& row : grid) {
        for (const auto& tile : row) {
            tiles.push_back(std::make_unique<Tile>(*tile));
        }
    }
    return tiles;
}

void Grid::openCell(int x, int y)
{
    int num = grid[x][y]->getNum();

    grid[x][y]->open();
}

void Grid::draw(float offset_X, float offset_Y)
{
    for (const auto& row : grid) {
        for (const auto& tile : row) {
            tile->draw(offset_X, offset_Y);
        }
    }
    
}