#include "Nave.h"

///////////////////////////////////////////////////////////////////////////
void Nave::setup()
{
  m_x = 60;
  m_y = 20;
  
  m_energia = 3;
  m_vidas = 3;

  m_explotar = false;
}

///////////////////////////////////////////////////////////////////////////
void Nave::update()
{
  if (m_energia <= 0)
	{
    m_explotar = true;
    m_vidas--;
    m_energia = 3;
  }
}

///////////////////////////////////////////////////////////////////////////
void Nave::draw()
{
  if (!m_explotar)
  {
    mvaddch(m_y, m_x + 2, '^');
    mvaddch(m_y + 1, m_x + 1, '(');
    mvaddch(m_y + 1, m_x + 2, ACS_PLMINUS);
    mvaddch(m_y + 1, m_x + 3, ')');
    mvaddch(m_y + 2, m_x, ACS_ULCORNER);
    mvaddch(m_y + 2, m_x + 1, '#');
    mvaddch(m_y + 2, m_x + 2, ' ');
    mvaddch(m_y + 2, m_x + 3, '#');
    mvaddch(m_y + 2, m_x + 4, ACS_URCORNER);
  }
  else
  {
    mvprintw(m_y, m_x - 2, "   ***   ");
    mvprintw(m_y + 1, m_x - 2, "  *****  ");
    mvprintw(m_y + 2, m_x - 2, "   ***   ");    
    
    refresh();
    delay_output(200);

    mvprintw(m_y - 1, m_x - 3, ".    *    .");
    mvprintw(m_y, m_x - 2, "*  * *  *");
    mvprintw(m_y + 1, m_x - 3, "*  *   *  *");
    mvprintw(m_y + 2, m_x - 2, "*  * *  *");
    mvprintw(m_y + 3, m_x - 3, "'    *    '");

    refresh();
    delay_output(200);
    
    m_explotar = false;
  }
}

///////////////////////////////////////////////////////////////////////////
void Nave::setX(int x) { m_x = x; }
void Nave::setY(int y) { m_y = y; }
int Nave::getX() { return m_x; }
int Nave::getY() { return m_y; }
void Nave::setEnergia(int energia) { m_energia = energia; }
int Nave::getEnergia() { return m_energia; }
void Nave::setVidas(int vidas) { m_vidas = vidas; }
int Nave::getVidas() { return m_vidas; }