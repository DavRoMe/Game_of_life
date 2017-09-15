#include "cellsGrid.h"

using namespace std;

CellsGrid::CellsGrid(int width, int height, int columns, int rows, sf::Texture& texture): ScrnGrid(width, height, columns, rows) {
  txtr = texture;
  fillCells();
}

void CellsGrid::setPosition(int x, int y) {
  ScrnGrid::setPosition(x, y);
  for(int i = 0; i < getCols(); i++) {
    for(int j = 0; j < getRows(); j++) {
      sf::Vector2i v = getIndexPos(i, j);
      cells.find(i)->second.find(j)->second.setPosition(v.x, v.y);
    }
  }
}

void CellsGrid::clickCell(int x, int y, bool state, sf::RenderWindow& window) {
  if(indexOfGrid(x, y)) {
    sf::Vector2i p(getAreaIndex(x, y));
    cells.find(x)->second.find(y)->second.setState(state);
    cells.find(x)->second.find(y)->second.setColor(computeColor(x, y));
    cells.find(x)->second.find(y)->second.show(window);
  }
}

void CellsGrid::nextCycle() {
  for(int i = 0; i < getCols(); i++) { /**Agregar iteradores en un futuro**/
    for(int j = 0; j < getRows(); j++) {
      cells.find(i)->second.find(j)->second.setNextSt(computeNext(i, j));
      cells.find(i)->second.find(j)->second.setColor(computeColor(i, j));
    }
  }

  for(unordered_map<int, unordered_map<int, LifeCell>>::iterator itEx = cells.begin(); itEx != cells.end(); ++itEx) {
    for(unordered_map<int, LifeCell>::iterator itIn = itEx->second.begin(); itIn != itEx->second.end(); ++itIn) {
      itIn->second.setSize(getCellW(), getCellH());
      itIn->second.update();
    }
  }
}

void CellsGrid::drawCells(sf::RenderWindow& window) {
  for(unordered_map<int, unordered_map<int, LifeCell>>::iterator itEx = cells.begin(); itEx != cells.end(); ++itEx) {
    for(unordered_map<int, LifeCell>::iterator itIn = itEx->second.begin(); itIn != itEx->second.end(); ++itIn) {
      itIn->second.show(window);
    }
  }
}

bool CellsGrid::computeNext(int cX, int cY) {
  int neighbors = 0;

  for(int i = cX - 1; i <= cX + 1; i++) {
//    if(i >= 0 && i < getCols())       // Reemplazado por indexOfGrid(i, j)
    for(int j = cY - 1; j <= cY + 1; j++) {
//        if(j >= 0 && j < getRows())   // Reemplazado por indexOfGrid(i, j)
      if(indexOfGrid(i, j))             /// Revisando que la posicion exista
        if(cells.find(i)->second.find(j)->second.getState()) {    /// Si existe se revisa su estado
          neighbors++;
        }
    }
  }
// Si la celula actual tambien se sumó se le resta 1
  if(cells.find(cX)->second.find(cY)->second.getState()) neighbors--;

  switch(neighbors) {
  case 2: // La celula se mantiene en su estado
    if(cells.find(cX)->second.find(cY)->second.getState()) return true;
    else return false;
    break;
  case 3:
    return true;
    break;
  default:
    return false;
    break;
  }
}

void CellsGrid::fillCells() {
  for(int i = 0; i < getCols(); i++) {
    for(int j = 0; j < getRows(); j++) {
      sf::Vector2i v = getIndexPos(i, j);
      cells[i].insert(make_pair(j, LifeCell(txtr, v.x, v.y)));
    }
  }
  for(unordered_map<int, unordered_map<int, LifeCell>>::iterator itEx = cells.begin(); itEx != cells.end(); ++itEx) {
    for(unordered_map<int, LifeCell>::iterator itIn = itEx->second.begin(); itIn != itEx->second.end(); ++itIn) {
      itIn->second.setSize(getCellW(), getCellH());
    }
  }
}
void CellsGrid::clearCells() {
    for(unordered_map<int, unordered_map<int, LifeCell>>::iterator itEx = cells.begin(); itEx != cells.end(); ++itEx) {
    for(unordered_map<int, LifeCell>::iterator itIn = itEx->second.begin(); itIn != itEx->second.end(); ++itIn) {
      itIn->second.setState(false);
      itIn->second.setColor(LifeCell::deadcolor);
    }
  }
}

sf::Color CellsGrid::computeColor(int cX, int cY) {
  int neighbors = 0;
// Si la celula actual tambien se suma se le resta 1
  if(cells.find(cX)->second.find(cY)->second.getState()) neighbors--;
  else {
    return LifeCell::deadcolor;
  }
  for(int i = cX - 1; i <= cX + 1; i++) {
    for(int j = cY - 1; j <= cY + 1; j++) {
      if(indexOfGrid(i, j))             /// Revisando que la posicion exista
        if(cells.find(i)->second.find(j)->second.getState()) {    /// Si existe se revisa su estado
          neighbors++;
        }
    }
  }
  if(cells.find(cX)->second.find(cY)->second.getState()) {  // Si la celula esta viva entra al switch
    switch(neighbors) {
    case 0:
      return sf::Color(0, 255, 243);
    case 1:
      return sf::Color(0, 255, 126);
    case 2:
      return sf::Color(12, 255, 15);
    case 3:
      return sf::Color(120, 255, 0);
    case 4:
      return sf::Color(240, 242, 0);
    case 5:
      return sf::Color(255, 132, 0);
    case 6:
      return sf::Color(255, 14, 13);
    case 7:
      return sf::Color(255, 0, 123);
    case 8:
      return sf::Color(255, 0, 240);
    default:
      return LifeCell::deadcolor;
    }
  } else return LifeCell::deadcolor;
}
