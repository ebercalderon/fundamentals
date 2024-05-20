#pragma once
#include <iostream>
#include <ncurses.h>
#include "Nave.h"

using namespace std;

class Asteroide
{
public:
  Asteroide(int x, int y);
  void update();
  void draw();

  void colision( Nave &rNave );

private:
  float m_x, m_y;
};