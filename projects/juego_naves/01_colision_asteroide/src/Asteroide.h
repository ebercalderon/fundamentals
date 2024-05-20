#pragma once
#include <iostream>
#include <ncurses.h>

// Como la clase Asteroide será la encargado de evaluar si colisiona con
// la nave debemos incluir el archivo Nave.h en la clase Asteroide.
#include "Nave.h"

using namespace std;

class Asteroide
{
public:
  Asteroide(int x, int y);
  void update();
  void draw();

  // Crearemos el método colision() que servirá para implementar la
  // colisión con la nave. Necesitaremos como parámetro una referencia
  // al objeto del tipo nave. Por un lado usaremos una referencia para no 
  // crear un duplicado de la nave en la memoria, pero por otra parte, 
  // la referencia nos permitirá hacer cambios en el objeto, como por 
  // ejemplo disminuir la energía de la nave. Disminuir la energía en una
  // copia del objeto nave no nos serviría, porque no bajaría la energía
  // de la nave que estamos usando (que es la original).
  void colision( Nave &rNave );

private:
  float m_x, m_y;
};