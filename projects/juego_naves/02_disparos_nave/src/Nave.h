#pragma once
#include <iostream>
#include <ncurses.h>

class Nave
{
public:
  void setup();
  void draw();
  void update();

  void setX(int x);
  void setY(int y);

  int getX();
  int getY();

  void setEnergia(int energia);
  int getEnergia();

  void setVidas(int vidas);
  int getVidas();

private:
  int m_x, m_y;
  int m_energia;
  int m_vidas;
  bool m_explotar;
};