/**
 * LABORATORIO 6
 * C++ - Listas Circulares Doblemente Enlazadas en c++
 */

#include <stdlib.h> // srand(), rand()
#include <time.h>   // time()
#include <iomanip>  // setw()
#include <iostream>

using namespace std;

/*                Estructura de cada estacion
------------------------------------------------------------------------*/
struct estacion
{
  char id;
  int peso;
  int recorrido;
};

/*                Estructura del nodo 
------------------------------------------------------------------------*/
struct nodo
{
  estacion punto;
  struct nodo *anterior;
  struct nodo *siguiente;
};

typedef struct nodo *Tlista;

/*                Insertar elemento al inicio     
------------------------------------------------------------------------*/
void insertarInicio(Tlista &lista, char id, int pe, int re)
{
  Tlista q = NULL;
  q = new (struct nodo);
  q->punto.id = id;
  q->punto.peso = pe;
  q->punto.recorrido = re;

  q->siguiente = q;
  q->anterior = q;

  lista->anterior->siguiente = q;
  q->anterior = lista->anterior;
  q->siguiente = lista;

  lista = q;
}

/*                Insertar elemento al final     
------------------------------------------------------------------------*/
void insertarFinal(Tlista &lista, char id, int pe, int re)
{
  Tlista r = NULL;
  r = new (struct nodo);
  r->punto.id = id;
  r->punto.peso = pe;
  r->punto.recorrido = re;

  r->siguiente = r;
  r->anterior = r;

  lista->anterior->siguiente = r;
  r->siguiente = lista;
  r->anterior = lista->anterior;

  lista->anterior = r;
}

/*                Mostrar los nodos     
------------------------------------------------------------------------*/
void listarNodosAscendente(Tlista lista)
{
  Tlista q = lista;

  cout << "\nRecorrido de ida\n";
  cout << setw(11) << "Punto" << setw(11) << "Peso" << setw(11) << "Recorrido al proximo punto" << endl;
  while (lista != NULL)
  {
    cout << setw(11) << lista->punto.id << setw(11) << lista->punto.peso << setw(11) << lista->punto.recorrido << endl;
    q = lista;
    lista = lista->siguiente;
  }
}

void listarNodosDescendente(Tlista lista)
{
  Tlista q = lista;

  while (lista != NULL)
  {
    q = lista;
    lista = lista->siguiente;
  }

  cout << "\nBajada del punto \n";
  cout << setw(11) << "id" << setw(11) << "peso" << setw(11) << "recorrido" << setw(11) << "Quedan" << endl;
  while (q != NULL)
  {
    cout << setw(11) << q->punto.id << setw(11) << q->punto.peso << setw(11) << q->punto.recorrido << endl;
    q = q->anterior;
  }
}

estacion buscarPosicion(Tlista inicio, int pos)
{
  Tlista p = inicio;
  int cont = 1;

  while (p != NULL)
  {
    if (cont == pos)
      return p->punto;

    p = p->siguiente;

    cont++;
  }

  return {};
}

void modificarValor(Tlista inicio, int pos, int pe, int re)
{
  Tlista q = inicio;
  int cont = 1;
  while (q != NULL)
  {
    if (cont == pos)
    {
      q->punto.peso = pe;
      q->punto.recorrido = re;
    }
    q = q->siguiente;

    cont++;
  }
}

int gE()
{
  //srand(time(NULL));

  return 1 + rand() % 9;
}

int validar(int a)
{
  int aux = 0;
  do
  {
    aux = gE();
  } while (aux >= a);

  return aux;
}

/*                        Presentacion    
------------------------------------------------------------------------*/
void presentacion()
{
  int opcion;
  system("cls");

  cout << "\n==============================="
       << "\n....:::: LABORATORIO 6 ::::...."
       << "\n===============================\n"
       << "\nCalderon Claudio, Eber Andres\t18200214\n\n";
}

/*                        Funcion Principal        
------------------------------------------------------------------------*/
int main()
{
  Tlista lista = NULL;
  //int temp1 = 0, temp2 = 0;
  //int sum1 = 0, sum2 = 0;
  //estacion aux = {};

  srand(time(NULL));
  presentacion();

  for (int i = 1; i < 6; i++)
  {
    if (i == 1)
      insertarInicio(lista, 'A', gE(), gE());
    else
      insertarFinal(lista, 'B', gE(), gE());
  }

  listarNodosAscendente(lista);



  cout << endl
       << endl;
  system("pause");

  return 0;
}