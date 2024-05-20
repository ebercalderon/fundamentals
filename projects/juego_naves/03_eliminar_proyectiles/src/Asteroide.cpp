#include "Asteroide.h"

///////////////////////////////////////////////////////////////////////////
Asteroide::Asteroide(int x, int y)
{
  m_x = x;
  m_y = y;
}

///////////////////////////////////////////////////////////////////////////
void Asteroide::update()
{
  m_y = m_y + 0.4f;

  if (m_y >= 39)
  {
    m_x = rand() % 119 + 1;
    m_y = 1;
  }
}

///////////////////////////////////////////////////////////////////////////
void Asteroide::draw()
{
  mvaddch(m_y, m_x, '*');
}

///////////////////////////////////////////////////////////////////////////
void Asteroide::colision( Nave &rNave )
{
  if( m_x >= rNave.getX() && m_x <= rNave.getX() + 4 && m_y >= rNave.getY() && m_y <= rNave.getY() + 2 )
  {
    rNave.setEnergia(rNave.getEnergia() - 1);

    m_x = rand() % 119 + 1;
    m_y = 1;
  }
}