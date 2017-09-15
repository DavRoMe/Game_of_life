#pragma once

#include <list>
#include "linea.h"

class ScrnGrid {
private:
    // Usando float en lugar de int para mejorar precision
    float gridWidth, gridHeight;
    float cellWidth, cellHeight;
    float xPos, yPos;
    int rows, columns;
    bool equalSides;
    std::list <linea> gridLines;

    void createLines();
    void updateCells();

public:
    ScrnGrid(int width, int height, int columns, int rows);
    ~ScrnGrid();

    int getRows();
    int getCols();
    float getWdth();
    float getHght();
    float getCellW();
    float getCellH();
    sf::Vector2f getCenter();
    sf::Vector2i getAreaCorner(int x, int y);
    sf::Vector2i getAreaIndex(int x, int y);
    sf::Vector2i getIndexPos(int i, int j);

    bool isWithinGrid(int x, int y);
    bool indexOfGrid(int i, int j);
    void setPosition(int x, int y);
    void squareCells(bool b);
    void showGrid(sf::RenderWindow& window);
};
