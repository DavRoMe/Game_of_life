#pragma once

#include <unordered_map>
#include <screenGrid.h>
#include "golCells.h"

using namespace std;

class CellsGrid: public ScrnGrid {
private:
    sf::Texture txtr;
    unordered_map<int, unordered_map<int, LifeCell>> cells;

    void fillCells();
    bool computeNext(int cX, int cY);
    sf::Color computeColor(int cX, int cY);

public:
    CellsGrid(int width, int height, int columns, int rows, sf::Texture& texture);

    void setPosition(int x, int y);
    void clickCell(int x, int y, bool state, sf::RenderWindow& window);
    void nextCycle();
    void drawCells(sf::RenderWindow& window);
    void clearCells();

};
