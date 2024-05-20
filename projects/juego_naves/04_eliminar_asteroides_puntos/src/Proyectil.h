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

  bool limite();

  int getX();
  int getY();

private:
  int m_x, m_y;
};