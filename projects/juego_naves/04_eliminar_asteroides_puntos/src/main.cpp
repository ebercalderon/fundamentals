// Verificaremos las colisiones entre los proyectiles y los asteroides
// para ir incrementando los puntos.

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

// Ahora vamos a guardar los asteroides en un vector. Crearemos los
// asteroides en el setup().
vector<Asteroide> Asteroides;

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

	// Cada vez que se inicia juego, después de perder por ejemplo, veremos
	// que la cantidad de Asteroides se va multiplicando. Para que eso no
	// suceda, tenemos que borrar todos los asteroides del vector y luego 
	// crearlos nuevamente.
	Asteroides.clear();

	// Hacemos lo mismo con los proyectiles, los eliminamos para que al 
	// reiniciar el juego no queden en la pantalla.
	Proyectiles.clear();

	// Creamos 5 asteroides con posiciones aleatorias en x (entre 1 y 119).
	for (int i = 0; i < 5; i++)
	{
		Asteroides.push_back(Asteroide(rand() % 119 + 1, 1));
	}
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

	// Ahora haremos los updates y las colisiones de los asteroides
	// recorriendo el vector Asteroides.
	for (int i = 0; i < Asteroides.size(); i++)
	{
		Asteroides[i].update();
		Asteroides[i].colision(miNave);
	}

	for (int i = 0; i < Proyectiles.size(); i++)
	{
		Proyectiles[i].update();

		if (Proyectiles[i].limite())
		{
			Proyectiles.erase(Proyectiles.begin() + i);
		}
	}

	// Hay dos formas en las que pueden colisionar el asteroide con el
  // proyectil, una es cuando coinciden en la misma posición y la
  // otra es cuando en un frame el proyectil y el asteroide están justo
  // enfrentados y en el siguiente frame intercambian de posición, no
	// llegando a estar en el mismo lugar nunga.

	// Recorremos todos los asteroides del vector y verificamos si algún
	// asteroide está colisionando con algún proyectil del vector.
	for (int i = 0; i < Asteroides.size(); i++)
	{
		for (int j = 0; j < Proyectiles.size(); j++)
		{
			// Si la posición del asteroide es igual a la del proyectil...
			if (Asteroides[i].getX() == Proyectiles[j].getX() 
			&& (Asteroides[i].getY() == Proyectiles[j].getY()
			// ...o si la posición siguiente es la que coincide con el proyectil.
			|| Asteroides[ i ].getY() + 1 == Proyectiles[ j ].getY()) )
			{
				// Eliminamos el asteroide del vector.
				Asteroides.erase(Asteroides.begin() + i);

				// Volvemos a crear un asteroide nuevo en el vector.
				Asteroides.push_back(Asteroide(rand() % 119 + 1, 1));

				// Incrementamos los puntos.
				puntaje++;
			}
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

	// Mostramos el puntaje.
	mvprintw(0, 5, "[ PUNTOS:     ]");
	mvprintw(0, 15, "%d", puntaje);

	miNave.draw();

	// Dibujamos los asteroides recorriendo el vector.
	for (int i = 0; i < Asteroides.size(); i++)
	{
		Asteroides[i].draw();
	}

	for (int i = 0; i < Proyectiles.size(); i++)
		Proyectiles[i].draw();

	refresh();
	delay_output(DELAY);
}

///////////////////////////////////////////////////////////////////////////
void gameover()
{
	for (int y = 10; y < 16; y++)
		mvhline(y, 40, ' ', 40);

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
