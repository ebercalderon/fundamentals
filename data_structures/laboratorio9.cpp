/**
 * LABORATORIO 9
 * C++ - ARBOL BINARIO DE BUSQUEDA
 */

#include <iostream>
#include <time.h>   // time()
#include <stdlib.h> // srand(), rand()

using namespace std;

/*                        Estructura del nodo  
------------------------------------------------------------------------*/
struct nodo
{
  int nro;
  struct nodo *izquierdo;
  struct nodo *derecho;
} * aux, *ant;

typedef struct nodo *ABB;

ABB crearNodo(int nro)
{
  ABB q = new (struct nodo);
  q->nro = nro;
  q->izquierdo = NULL;
  q->derecho = NULL;

  return q;
}

/*
void insertar(ABB &arbol, int nro)
{
  if (arbol == NULL)
  {
    arbol = crearNodo(nro);
  }
  else if (nro < arbol->nro)
    insertar(arbol->izquierdo, nro);
  else if (nro > arbol->nro)
    insertar(arbol->derecho, nro);
}
*/
int buscar(ABB &arbol, int nro)
{
  if (!arbol)
  {
    cout << "No hay arbol";
    return (0);
  }
  ant = NULL;
  aux = arbol;
  while (aux)
  {
    if (nro == aux->nro)
      return (1);
    else
    {
      ant = aux;
      if (nro > aux->nro)
        aux = aux->derecho;
      else
        aux = aux->izquierdo;
    }
  }
  return (0);
}

void insertar(ABB &arbol, int nro)
{
  if (!arbol)
  {
    arbol = new (struct nodo);
    arbol->nro = nro;
    arbol->derecho = NULL;
    arbol->izquierdo = NULL;
    return;
  }

  if (!buscar(arbol, nro))
  {
    aux = new (struct nodo);
    ;
    aux->nro = nro;
    aux->izquierdo = NULL;
    aux->derecho = NULL;
    if (nro > ant->nro)
      ant->derecho = aux;
    else
      ant->izquierdo = aux;
  }
  else
    cout << "\n\nEl elemento existente";
}

void preOrden(ABB arbol)
{
  if (arbol != NULL)
  {
    cout << arbol->nro << " ";
    preOrden(arbol->izquierdo);
    preOrden(arbol->derecho);
  }
}

void enOrden(ABB arbol)
{
  if (arbol != NULL)
  {
    enOrden(arbol->izquierdo);
    cout << arbol->nro << " ";
    enOrden(arbol->derecho);
  }
}

void postOrden(ABB arbol)
{
  if (arbol != NULL)
  {
    postOrden(arbol->izquierdo);
    postOrden(arbol->derecho);
    cout << arbol->nro << " ";
  }
}

void mostrarArbol(ABB arbol, int n)
{
  if (arbol == NULL)
    return;
  mostrarArbol(arbol->derecho, n + 1);

  for (int i = 0; i < n; i++)
    cout << "   ";

  cout << arbol->nro << endl;

  mostrarArbol(arbol->izquierdo, n + 1);
}

/*                        Menu de opciones    
------------------------------------------------------------------------*/
int menu()
{
  int opcion;
  system("cls");

  cout << "\n==============================="
       << "\n....:::: LABORATORIO 9 ::::...."
       << "\n===============================\n"
       << "\nCalderon Claudio, Eber Andres\t18200214\n"
       << "\n1.- Ingresar elementos al ABB"
       << "\n2.- Mostrar elementos del ABB"
       << "\n0.- Salir\n";
  do
  {
    cout << "\nIngresar opcion: ";
    cin >> opcion;
  } while (opcion < 0 || opcion > 4);

  return opcion;
}

int gE()
{
  return 10 + rand() % 20;
}

int main()
{
  ABB arbol = NULL;

  int op;  // opcion del menu
  int raiz, aux;
  int nro; // elemento a insertar en cada nodo

  srand(time(NULL));

  do
  {
    op = menu();

    switch (op)
    {
    case 1:
      //cout << "Elemento a ingresar: ";
      //cin >> nro;
      //insertar(arbol, nro);

      insertar(arbol, 10);
      insertar(arbol, 5);
      insertar(arbol, 15);
      insertar(arbol, 4);
      insertar(arbol, 6);
      insertar(arbol, 14);
      insertar(arbol, 16);
      
      break;

    case 2:
      if (arbol != NULL)
      {
        cout << "\n Mostrando ABB \n\n";
        mostrarArbol(arbol, 0);

        cout << "\n Recorridos del ABB";

        cout << "\n\n En orden   :  ";
        enOrden(arbol);
        cout << "\n\n Pre Orden  :  ";
        preOrden(arbol);
        cout << "\n\n Post Orden :  ";
        postOrden(arbol);
      }
      else
      {
        cout << "\n\tABB vacio";
      }
      break;
    }

    cout << endl
         << endl;
    system("pause");

  } while (op != 0);

  return 0;
}