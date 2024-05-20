/**
 * EXAMEN PARCIAL
 * C++ - Listas Circulares Enlazadas y Pilas
 */

#include <stdlib.h> // srand(), rand()
#include <time.h>   // time()
#include <iomanip>  // setw()
#include <iostream>

using namespace std;

/*                        Estructura del contenedor
------------------------------------------------------------------------*/
struct datos
{
  char id;
  int peso;
};

/*                        Estructura del nodo 
------------------------------------------------------------------------*/
struct nodo
{
  datos contenedor;
  struct nodo *siguiente;
};

typedef struct nodo *Tlista;

/*                        Insertar elemento al inicio     
------------------------------------------------------------------------*/
void insertarInicio(Tlista &lista, nodo *&ultimo, char id, int pe)
{
  Tlista q = new (struct nodo);

  q->contenedor.id = id;
  q->contenedor.peso = pe;

  q->siguiente = NULL;

  if (lista == NULL)
  {
    lista = q;
    lista->siguiente = lista;
    ultimo = q;
  }
  else
  {
    q->siguiente = lista;
    lista = q;
    ultimo->siguiente = lista;
  }
}

/*                        Insertar elemento al final     
------------------------------------------------------------------------*/
void insertarFinal(Tlista &lista, nodo *&ultimo, char id, int pe)
{
  Tlista p = new (struct nodo);

  p->contenedor.id = id;
  p->contenedor.peso = pe;

  p->siguiente = NULL;

  if (lista == NULL)
  {
    lista = p;
    lista->siguiente = lista;
    ultimo = p;
  }
  else
  {
    ultimo->siguiente = p;
    p->siguiente = lista;
    ultimo = p;
  }
}

/*                        Mostrar los nodos     
------------------------------------------------------------------------*/
void listarNodos(Tlista lista)
{
  Tlista q = new (struct nodo);
  q = lista;

  if (lista != NULL)
  {
    cout << "\nFaja transportadora\n\n";
    cout << setw(11) << "Contenedor" << setw(11) << "Peso" << endl;
    do
    {
      cout << setw(11) << q->contenedor.id << setw(11) << q->contenedor.peso << endl;
      q = q->siguiente;
    } while (q != lista);
  }
  else
    cout << "\nNo hay contenedores\n";
}

/*                        Eliminar nodo     
------------------------------------------------------------------------
void eliminarNodo(int cod, Tlista lista, nodo *&ultimo)
{
  nodo *aux, *r, *q;
  int i = 1, flag = 0;

  if (lista != NULL)
  {
    aux = lista;

    do
    {
      if (aux->contenedor.cod == cod)
      {
        if (aux == lista) // si es que el dato a eliminar es el primero
        {
          r = lista;
          lista = lista->siguiente;
          aux = aux->siguiente;
          ultimo->siguiente = lista;
          r->siguiente = NULL;
          if (ultimo->siguiente == NULL)
          {
            lista == NULL;
            aux == NULL;
            delete (r);
          }
          else
          {
            delete (r);
          }
        }
        else
        {
          if (aux == ultimo) // si es que el dato a eliminar es al que apunta a fin
          {
            r = aux;
            aux = aux->siguiente;
            q->siguiente = aux;
            ultimo = q;
            r->siguiente = NULL;
            delete (r);
          }
          else
          {
            r = aux;
            aux = aux->siguiente;
            q->siguiente = aux;
            r->siguiente = NULL;
            delete (r);
          }
        }
        flag = 1;
      }
      else
      {
        q = aux;
        aux = aux->siguiente;
        i++;
      }
    } while (aux != lista);
  }
}
*/

/*                        Apilar elemento      
------------------------------------------------------------------------*/
void push(Tlista &p, char id, int pe)
{
  Tlista aux = new (struct nodo); // apuntamos al nuevo nodo creado
  aux->contenedor.id = id;
  aux->contenedor.peso = pe;

  aux->siguiente = p;
  p = aux;
}

/*                Desapilar elemento (devuelve elemento)      
------------------------------------------------------------------------*/
datos pop(Tlista &p)
{
  Tlista aux;
  datos contenedor;

  aux = p;
  contenedor.id = aux->contenedor.id; // asignamos el primer vamor de la pila
  contenedor.peso = aux->contenedor.peso;

  p = aux->siguiente;
  delete (aux);

  return contenedor;
}

/*                     Muestra elementos de la pila      
------------------------------------------------------------------------*/
void mostrarPila(Tlista p)
{
  Tlista aux;
  aux = p; // apunta al inicio de la lista

  while (aux != NULL)
  {
    cout << "\t[" << aux->contenedor.id << "|" << aux->contenedor.peso << "]   " << endl;
    aux = aux->siguiente;
  }
}

/*                        Punto 1    
------------------------------------------------------------------------*/
char generarTipo()
{
  char tipo;
  rand() % 2 != 1 ? tipo = 'A' : tipo = 'B';

  return tipo;
}

int validar(char tipo)
{
  int peso;
  tipo == 'A' ? peso = 1 + rand() % 15 : peso = 1 + rand() % 10;

  return peso;
}

void colocarContenedores(Tlista &lista, nodo *&ultimo)
{
  char tipo;

  if (lista == NULL)
  {
    for (int i = 0; i < 10; i++)
    {
      tipo = generarTipo();
      insertarFinal(lista, ultimo, tipo, validar(tipo));
    }
  }
  else
    cout << "\nYa se colocaron los contenedores\n";
}

/*                        Punto 2    
------------------------------------------------------------------------*/
void despacharPilas(Tlista lista, Tlista &pilaA, Tlista &pilaB)
{
  Tlista q = new (struct nodo);
  q = lista;

  if (lista != NULL)
  {
    do
    {
      if (q->contenedor.id == 'A')
      {
        if (q->contenedor.peso >= 1) // min 20
          push(pilaA, q->contenedor.id, q->contenedor.peso);
      }
      else
      {
        if (q->contenedor.peso >= 1) // min 30
          push(pilaB, q->contenedor.id, q->contenedor.peso);
      }

      q = q->siguiente;
    } while (q != lista);
  }
  else
    cout << "\nNo hay contenedores\n";
}

/*                        Punto 3    
------------------------------------------------------------------------*/
void despacharContenedor(Tlista &pilaA, Tlista &pilaB)
{
  datos aux;

  aux = pop(pilaA);
  cout << "\n\n\t\tContenedor: " << aux.id << " | " << aux.peso << " desencolado...\n\n";
  pop(pilaB);
  cout << "\n\n\t\tContenedor: " << aux.id << " | " << aux.peso << " desencolado...\n\n";

  cout << "\nPila A:\n"; mostrarPila(pilaA);
  cout << "\nPila B:\n";mostrarPila(pilaB);
  
}

/*                        Presentacion    
------------------------------------------------------------------------*/
int menu()
{
  int opcion;
  system("cls");

  cout << "\n================================"
       << "\n....:::: EXAMEN PARCIAL ::::...."
       << "\n================================\n"
       << "\nCalderon Claudio, Eber Andres\t18200214\n\n"
       << "\n1.- Colocar contenedores"
       << "\n2.- Recargar contenedores"
       << "\n3.- Mostrar contenedores"
       << "\n4.- Empilar contenedores"
       << "\n0.- Salir\n";

  do
  {
    cout << "\nIngresar opcion: ";
    cin >> opcion;
  } while (opcion < 0 || opcion > 4);

  return opcion;
}

/*                        Funcion Principal        
------------------------------------------------------------------------*/
int main()
{
  Tlista lista = NULL;
  nodo *ultimo = NULL;

  Tlista pilaA = NULL; // creando pila tipo A
  Tlista pilaB = NULL; // creando pila tipo B

  int op;

  srand(time(NULL));

  do
  {
    op = menu();

    switch (op)
    {
    case 1:
      colocarContenedores(lista, ultimo);
      listarNodos(lista);
      break;

    case 2:
      despacharPilas(lista, pilaA, pilaB);
      cout << "\nPila A:\n"; mostrarPila(pilaA);
      cout << "\nPila B:\n";mostrarPila(pilaB);

      break;

    case 3:
      listarNodos(lista);
      break;

    case 4:
      despacharContenedor(pilaA, pilaB);
      break;
    }

    cout << endl
         << endl;
    system("pause");

  } while (op != 0);

  return 0;
}