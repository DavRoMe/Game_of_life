#include "screenGrid.h"

using namespace std;

ScrnGrid::ScrnGrid(int width, int height, int columns, int rows) {
  gridWidth = width;
  gridHeight = height;
  if(rows > 0) {
    this->rows = rows;
  } else {
    this->rows = 1;
  }
  if(columns > 0) {
    this->columns = columns;
  } else {
    this->columns = 1;
  }
  setPosition(0, 0);
  squareCells(false);
  updateCells();
}

ScrnGrid::~ScrnGrid() {
  gridLines.clear();
}

int ScrnGrid::getRows() {
  return rows;
}
int ScrnGrid::getCols() {
  return columns;
}
float ScrnGrid::getWdth() {
  return gridWidth;
}
float ScrnGrid::getHght() {
  return gridHeight;
}
float ScrnGrid::getCellW() {
  return cellWidth;
}
float ScrnGrid::getCellH() {
  return cellHeight;
}
sf::Vector2f ScrnGrid::getCenter() {
    return sf::Vector2f(xPos + gridWidth/2, yPos + gridHeight/2);
}

sf::Vector2i ScrnGrid::getAreaCorner(int x, int y) {
  x = int((x - xPos) / cellWidth) * cellWidth + xPos;
  y = int((y - yPos) / cellHeight) * cellHeight + yPos;

  return sf::Vector2i(x, y);
}

sf::Vector2i ScrnGrid::getAreaIndex(int x, int y) {
  x = (x - xPos) / cellWidth;
  y = (y - yPos) / cellHeight;

  return sf::Vector2i(x, y);    // x=[0,rows);  y=[0,columns)
}

sf::Vector2i ScrnGrid::getIndexPos(int i, int j) {
  i = i * cellWidth + xPos;
  j = j * cellHeight + yPos;

  return sf::Vector2i(i, j);    // i=[0,rows);  j=[0,columns)
}

bool ScrnGrid::isWithinGrid(int x, int y) {
  if(x >= xPos && x < xPos + gridWidth && y >= yPos && y < yPos + gridHeight) {
    return true;
  } else {
    return false;
  }
}

bool ScrnGrid::indexOfGrid(int i, int j) {
  if(i >= 0 && i < columns && j >= 0 && j < rows) return true;
  else {
    return false;
  }
}

void ScrnGrid::setPosition(int x, int y) {
  xPos = x;
  yPos = y;
  createLines();
}

void ScrnGrid::squareCells(bool b) {
  equalSides = b;
}

void ScrnGrid::showGrid(sf::RenderWindow& window) {
  std::list <linea>::iterator it;
  for(it = gridLines.begin(); it != gridLines.end(); it++) {
    it->show(window);
  }
}

void ScrnGrid::updateCells() {
  cellWidth = gridWidth / columns;
  cellHeight = gridHeight / rows;
  createLines();
}

void ScrnGrid::createLines() {
  gridLines.clear();
  for(int i = 0; i < columns + 1; i++) {
    gridLines.push_back(linea(xPos + i * cellWidth, yPos, xPos + i * cellWidth, yPos + 1, gridHeight));
  }
  for(int j = 0; j < rows + 1; j++) {
    gridLines.push_back(linea(xPos, yPos + j * cellHeight, xPos + 1, yPos + j * cellHeight, gridWidth));
  }
}
