#pragma once
#include <iostream>
#include <ncurses.h>

using namespace std;

class Proyectil
{
public:
  Proyectil(int x, int y);
  
  void update();
  void draw();

  // Crearemos este método para verificar si los proyectiles alcanzaron el
  // límite superior de la pantalla.
  bool limite();

  // Métodos accesor para obtener la posición de los proyectiles.
  int getX();
  int getY();

private:
  int m_x, m_y;
};