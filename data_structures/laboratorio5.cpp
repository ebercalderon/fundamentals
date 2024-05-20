/**
 * LABORATORIO 5
 * C++ - Listas Doblemente Enlazadas en c++
 */

#include <stdlib.h> // srand(), rand()
#include <time.h>   // time()
#include <iomanip>  // setw()
#include <iostream>

using namespace std;

struct nivel
{
  int piso;
  int entran;
  int salen;
  int total;
};

/*                Estructura del nodo 
------------------------------------------------------------------------*/
struct nodo
{
  nivel ascensor;
  struct nodo *anterior;
  struct nodo *siguiente;
};

typedef struct nodo *Tlista;

/*                Insertar elemento al inicio     
------------------------------------------------------------------------*/
void insertarInicio(Tlista &lista, int p, int e, int s, int t)
{
  Tlista q = NULL;
  q = new (struct nodo);
  q->ascensor.piso = p;
  q->ascensor.entran = e;
  q->ascensor.salen = s;
  q->ascensor.total = t;
  q->siguiente = lista;
  q->anterior = NULL;

  if (lista != NULL)
    lista->anterior = q;

  lista = q;
}

int insertarFinal(Tlista &lista, int p, int e, int s, int t)
{
  Tlista q = lista, r = NULL;
  r = new (struct nodo);
  r->ascensor.piso = p;
  r->ascensor.entran = e;
  r->ascensor.salen = s;
  r->ascensor.total = t;
  r->anterior = NULL;
  r->siguiente = NULL;

  if (lista == NULL)
    lista = r;
  else
  {
    while (q->siguiente != NULL)
      q = q->siguiente;

    q->siguiente = r;
    r->anterior = q;
  }

  return lista->ascensor.piso;
}

void listarNodosAscendente(Tlista lista)
{
  Tlista q = lista;

  cout << "\nSubida del ascensor \n";
  cout << setw(11) << "Piso" << setw(11) << "Entran" << setw(11) << "Salen" << setw(11) << "Quedan" << endl;
  while (lista != NULL)
  {
    cout << setw(11) << lista->ascensor.piso << setw(11) << lista->ascensor.entran << setw(11) << lista->ascensor.salen << setw(11) << lista->ascensor.total << endl;
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

  cout << "\nBajada del ascensor \n";
  cout << setw(11) << "Piso" << setw(11) << "Entran" << setw(11) << "Salen" << setw(11) << "Quedan" << endl;
  while (q != NULL)
  {
    cout << setw(11) << q->ascensor.piso << setw(11) << q->ascensor.entran << setw(11) << q->ascensor.salen << setw(11) << q->ascensor.total << endl;
    q = q->anterior;
  }
}

nivel buscarPosicion(Tlista inicio, int pos)
{
  Tlista p = inicio;
  int cont = 1;

  while (p != NULL)
  {
    if (cont == pos)
      return p->ascensor;

    p = p->siguiente;

    cont++;
  }

  return {};
}

void modificarValor(Tlista inicio, int pos, int e, int s, int t)
{
  Tlista q = inicio;
  int cont = 1;
  while (q != NULL)
  {
    if (cont == pos)
    {
      q->ascensor.entran = e;
      q->ascensor.salen = s;
      q->ascensor.total = t;
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
       << "\n....:::: LABORATORIO 5 ::::...."
       << "\n===============================\n"
       << "\nCalderon Claudio, Eber Andres\t18200214\n\n";
}

/*                        Funcion Principal        
------------------------------------------------------------------------*/
int main()
{
  Tlista lista = NULL;
  int temp1 = 0, temp2 = 0;
  int sum1 = 0, sum2 =0;
  nivel aux = {};

  srand(time(NULL));
  presentacion();

  // SUBIDA
  for (int i = 1; i < 9; i++)
  {
    if (i == 1)
    {
      temp1 = gE();
      insertarFinal(lista, i, temp1, 0, temp1);
      sum1 += temp1;
    }
    else if (i < 8)
    {
      temp1 = gE();
      aux = buscarPosicion(lista, i - 1);
      temp2 = validar(aux.total);
      insertarFinal(lista, i, temp1, temp2, aux.total + temp1 - temp2);
      sum1 += temp1;
      sum2 += temp2;
    }
    else
    {
      temp1 = gE();
      aux = buscarPosicion(lista, i - 1);
      insertarFinal(lista, i, temp1, aux.total, temp1);
      sum1 += temp1;
      sum2 += temp2;
    }
  }

  listarNodosAscendente(lista);
  cout << "\nTotal entraron: " << sum1 << " | Total bajaron: " << sum2 << endl;

  // BAJADA
  aux = buscarPosicion(lista, 8);
  sum1 = aux.entran; 
  sum2 = aux.salen;
  for (int i = 7; i > 0; i--)
  {
    if (i > 1)
    {
      temp1 = gE();
      aux = buscarPosicion(lista, i + 1);
      temp2 = validar(aux.total);
      modificarValor(lista, i, temp1, temp2, aux.total + temp1 - temp2);
      sum1 += temp1;
      sum2 += temp2;
    }
    else
    {
      temp1 = gE();
      aux = buscarPosicion(lista, i + 1);
      modificarValor(lista, i, temp1, aux.total, temp1);
      sum1 += temp1;
      sum2 += temp2;
    }
  }

  listarNodosDescendente(lista);
  cout << "\nTotal entraron: " << sum1 << " | Total bajaron: " << sum2 << endl;

  cout << endl
       << endl;
  system("pause");

  return 0;
}