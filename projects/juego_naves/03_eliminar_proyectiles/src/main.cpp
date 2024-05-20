// Eliminaremos los proyectiles de la pantalla.

#include <iostream>
#include <ncurses.h>
#include "Nave.h"
#include "Asteroide.h"
#include <vector>
#include "Proyectil.h"

using namespace std;

//=========================================================================
// DECLARACION DE LAS CONSTANTES
//=========================================================================

const int ANCHO = 120;
const int ALTO = 40;
const int DELAY = 30;

//=========================================================================
// DEFINICION DE LAS VARIABLES GLOBALES
//=========================================================================

bool game_over;
int puntaje;
bool salir;

Nave miNave;
Asteroide asteroide_01(10, 2);
Asteroide asteroide_02(4, 8), asteroide_03(15, 10);

vector<Proyectil> Proyectiles;

//=========================================================================
// DECLARACION DE LAS FUNCIONES GLOBALES
//=========================================================================

void setup();
void input();
void update();
void draw();
void gameover();

//=========================================================================
// MAIN
//=========================================================================

int main()
{
	initscr();
	noecho();
	curs_set(FALSE);
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);

	if (LINES < ALTO || COLS < ANCHO)
	{
		endwin();
		printf("La terminal tiene que tener como mínimo %dx%d\n\n", ANCHO, ALTO);
		exit(1);
	}

	setup();

	salir = false;

	while (!salir)
	{
		while (!game_over)
		{
			input();
			update();
			draw();
		}
		gameover();
	}

	endwin();

	cout << endl;
	return 0;
}

//=========================================================================
// DEFINICION DE LAS FUNCIONES GLOBALES
//=========================================================================

void setup()
{
	game_over = FALSE;
	puntaje = 0;

	miNave.setup();
}

///////////////////////////////////////////////////////////////////////////
void input()
{
	int tecla = getch();

	switch (tecla)
	{
	case KEY_UP:
		if (miNave.getY() > 1)
			miNave.setY(miNave.getY() - 1);
		break;
	case KEY_DOWN:
		if (miNave.getY() < ALTO - 4)
			miNave.setY(miNave.getY() + 1);
		break;
	case KEY_LEFT:
		if (miNave.getX() > 1)
			miNave.setX(miNave.getX() - 1);
		break;
	case KEY_RIGHT:
		if (miNave.getX() < ANCHO - 6)
			miNave.setX(miNave.getX() + 1);
		break;
	case 27:
		game_over = TRUE;
		break;
	case 'e':
		miNave.setEnergia(miNave.getEnergia() - 1);
		break;
	case 'z':
		Proyectiles.push_back(Proyectil(miNave.getX() + 2, miNave.getY()));
		break;
	default:
		break;
	}
}

///////////////////////////////////////////////////////////////////////////
void update()
{
	miNave.update();

	if (miNave.getVidas() <= 0)
		game_over = true;

	asteroide_01.update();
	asteroide_02.update();
	asteroide_03.update();

	asteroide_01.colision(miNave);
	asteroide_02.colision(miNave);
	asteroide_03.colision(miNave);

	for( int i = 0; i < Proyectiles.size(); i++ )
	{
		Proyectiles[i].update();

		// Vamos verificando si los proyectiles alcanzan el borde superior de
		// la pantalla.
		if (Proyectiles[i].limite())
		{
			// Si el proyectil llegó a arriba entonces lo eliminamos del vector.
			// El método erase necesita como argumento un iterador, por eso
			// tenemos que utilizar "Proyectiles.begin() + i".
			Proyectiles.erase(Proyectiles.begin() + i);
		}
	}
}

///////////////////////////////////////////////////////////////////////////
void draw()
{
	erase();
	box(stdscr, 0, 0);

	mvprintw(0, 80, "[ ENERGIA:     ]");
	for (int i = 0; i < miNave.getEnergia(); i++)
	{
		mvaddch(0, 91 + i, ACS_CKBOARD);
	}

	mvprintw(0, 100, "[ VIDAS:     ]");

	for (int i = 0; i < miNave.getVidas(); i++)
	{
		mvaddch(0, 109 + i, A_ALTCHARSET | 174);
	}

	miNave.draw();
	asteroide_01.draw();
	asteroide_02.draw();
	asteroide_03.draw();

	for( int i = 0; i < Proyectiles.size(); i++ ) Proyectiles[ i ].draw();

	refresh();
	delay_output(DELAY);
}

///////////////////////////////////////////////////////////////////////////
void gameover()
{
	for (int y = 10; y < 16; y++) mvhline(y, 40, ' ', 40);

	mvaddch(9, 39, ACS_ULCORNER);
	mvaddch(9, 80, ACS_URCORNER);
	mvaddch(16, 39, ACS_LLCORNER);
	mvaddch(16, 80, ACS_LRCORNER);

	mvhline(9, 40, ACS_HLINE, 40);
	mvhline(16, 40, ACS_HLINE, 40);

	mvvline(10, 39, ACS_VLINE, 6);
	mvvline(10, 80, ACS_VLINE, 6);

	mvprintw(12, 55, "GAME OVER");
	mvprintw(13, 50, "VOLVER A JUGAR? (S/N)");

	int opcion = getch();

	if (opcion == 's' || opcion == 'S')
	{
		game_over = false;
		setup();
	}
	else if (opcion == 'n' || opcion == 'N')
	{
		salir = TRUE;
	}
}
