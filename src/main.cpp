
#include <cstdio>
#include <SFML/Graphics.hpp>
#include <screenGrid.h>
#include "cellsGrid.h"

using namespace std;

const int ANCHO = 1120;
const int ALTO = 560;

const int filas = 16 * 5;
const  int columnas = 9 * 5;

const float FPS = 30;

int main() {
  sf::RenderWindow ventana(sf::VideoMode(ANCHO, ALTO), "Juego de la vida");
  sf::Texture textura;
  if(!textura.loadFromFile("cell.png")) {
    printf("Error al cargar cell.png\n");
  } else
    textura.setSmooth(true);
  CellsGrid grid(ANCHO * 2, ALTO * 2, filas, columnas, textura);
  sf::View vista(grid.getCenter(), sf::Vector2f((float)ANCHO, (float)ALTO));

  sf::Time drawTime = sf::milliseconds(1000 / 10);  // Control de generaciones por segundo
  sf::Time elapsed;
  sf::Clock crono;
  sf::Clock delay;

  bool play = false;

  ventana.setFramerateLimit(FPS);
  while(ventana.isOpen()) {
//////////////////////////////////////////////////////////////////////////////////////
    ventana.setView(vista);
    sf::Event evento;
    while(ventana.pollEvent(evento)) {

      if(evento.type == sf::Event::Closed) {
        ventana.close();
      }

      if(sf::Event::KeyPressed) {
        switch(evento.key.code) {
        case sf::Keyboard::C:
          vista.setCenter(grid.getCenter().x, grid.getCenter().y);
          ventana.setView(vista);
          break;
        case sf::Keyboard::Delete:
          grid.clearCells();
          play = false;
          break;
        case sf::Keyboard::Return:
          play = true;
          break;
        case sf::Keyboard::Space:
          play = false;
          break;
        case sf::Keyboard::F:
          elapsed = delay.getElapsedTime();
          if(elapsed >= sf::milliseconds(1000 / 5)) {   // Retardo para ejecutar uno a la vez
            delay.restart();
            grid.nextCycle();
          }
          break;
        default:
          break;
        }
      }
    }

    // Control de camara
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
      vista.zoom(0.98);
      ventana.setView(vista);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
      vista.zoom(1.02);
      ventana.setView(vista);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
      vista.move(0, -10);
      ventana.setView(vista);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      vista.move(0, 10);
      ventana.setView(vista);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
      vista.move(-10, 0);
      ventana.setView(vista);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
      vista.move(10, 0);
      ventana.setView(vista);
    }

    // Mouse click
    sf::Vector2f worldPos = ventana.mapPixelToCoords(sf::Mouse::getPosition(ventana));
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      sf::Vector2i indice(grid.getAreaIndex(worldPos.x, worldPos.y));
      grid.clickCell(indice.x, indice.y, true, ventana);
    }
    if(sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
      sf::Vector2i indice(grid.getAreaIndex(worldPos.x, worldPos.y));
      grid.clickCell(indice.x, indice.y, false, ventana);
    }
//////////////////////////////////////////////////////////////////////////////////////
    elapsed = crono.getElapsedTime();
    if(elapsed >= drawTime) {       // Control de generaciones por segundo
      crono.restart();
      if(play)
        grid.nextCycle();
    }
    ventana.clear(sf::Color::Black);
    grid.drawCells(ventana);
    ventana.display();
  }
  return 0;
}
