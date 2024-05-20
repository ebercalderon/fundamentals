#include <stdlib.h> // srand(), rand()
#include <time.h>   // time()
#include <iostream>

using namespace std;

struct nodo
{
  int nro;
  struct nodo *sgte;
};

typedef struct nodo *Tlista;

// Operaciones listas
void insertarInicio(Tlista &lista, int valor)
{
  Tlista q;
  q = new (struct nodo);
  q->nro = valor;
  q->sgte = lista;
  lista = q;
}

void insertarFinal(Tlista &lista, int valor)
{
  Tlista t, q = new (struct nodo);

  q->nro = valor;
  q->sgte = NULL;

  t = lista;

  while (t->sgte != NULL)
    t = t->sgte;

  t->sgte = q;
}

void listarNodos(Tlista lista)
{
  Tlista q = lista;

  while (q != NULL)
  {
    cout << q->nro << "  ";
    q = q->sgte;
  }
}

int contarNodos(Tlista lista)
{
  Tlista q = lista;
  int cont = 0;

  while (q != NULL)
  {
    cont++;
    q = q->sgte;
  }

  return cont;
}

// Punto 1
void insertarDosNodos(Tlista &lista)
{
  srand(time(NULL));

  for (int i = 0; i < 2; i++)
    insertarInicio(lista, 1 + rand() % 20);
}

// Punto 2
void insertarNodoSuma(Tlista &lista)
{
  Tlista q = lista;
  int a = 0, b = 0;

  while (q != NULL)
  {
    b = a;
    a = q->nro;
    q = q->sgte;
  }

  insertarFinal(lista, a + b);

  cout << "\nElemento agregado: " << a + b;
}

// Punto 3
void insertarPromedio(Tlista lista1, Tlista &lista2)
{
  Tlista q = lista1;
  int suma = 0, total = 0;

  while (q != NULL)
  {
    total++;
    suma += q->nro;
    q = q->sgte;
  }

  insertarInicio(lista2, suma / total);
}

// Punto 5
int promediarLista(Tlista lista)
{
  Tlista q = lista;
  int pro, suma = 0, total = 0;

  while (q != NULL)
  {
    total++;
    suma += q->nro;
    q = q->sgte;
  }

  pro = suma / total;

  return pro;
}

// Punto 4
Tlista intercambio(Tlista ptr1, Tlista ptr2)
{
  Tlista tmp = ptr2->sgte;

  ptr2->sgte = ptr1;
  ptr1->sgte = tmp;
  return ptr2;
}

void transferirLista(Tlista &lista1, Tlista &lista2)
{
  Tlista p = lista1;
  Tlista t, q = new (struct nodo);
  int pro = promediarLista(lista1);

  while (p != NULL)
  {
    if (p->nro < pro)
    {
      cout << "\nElemento transferido: " << p->nro;
      /*
      q->nro = valor;
      q->sgte = NULL;

      t = lista;

      while (t->sgte != NULL)
        t = t->sgte;

      t->sgte = q;
      */
    }
    p = p->sgte;
  }
}

// Punto 6
void eliminarMayores(Tlista &lista, int valor)
{
  Tlista q, ant;
  q = lista;
  ant = lista;

  while (q != NULL)
  {
    if (q->nro > valor)
    {
      cout << "\nElemento eliminado: " << q->nro;
      if (q == lista) // primero elemento
      {
        lista = lista->sgte;
        delete (q);
        q = lista;
      }
      else
      {
        ant->sgte = q->sgte;
        delete (q);
        q = ant->sgte;
      }
    }
    else
    {
      ant = q;
      q = q->sgte;
    }
  }
}

// Menu de opciones
int menu()
{
  int opcion;
  system("cls");

  cout << "\n==============================="
       << "\n....:::: LABORATORIO 3 ::::...."
       << "\n===============================\n"
       << "\nCalderon Claudio, Eber Andres\t18200214\n"
       << "\nOpciones de Listas"
       << "\n1.- Crear lista 1"
       << "\n2.- Insertar nodo suma al final de la lista 1"
       << "\n3.- Crear lista 2"
       << "\n4.- Mostrar listas"
       << "\n5.- Mostrar promedios de listas"
       << "\n6.- Eliminar nodos mayores al promedio de la lista 2\n"
       << "\n0.- Salir\n";
  do
  {
    cout << "\nIngresar opcion: ";
    cin >> opcion;
  } while (opcion < 0 || opcion > 6);

  return opcion;
}

int main()
{
  Tlista lista1 = NULL;
  Tlista lista2 = NULL;
  int op;

  do
  {
    op = menu();

    switch (op)
    {
    case 1:
      if (lista1 == NULL)
      {
        insertarDosNodos(lista1);
        cout << "\nLista 1 creada: ";
        listarNodos(lista1);
      }
      else
        cout << "\nLa lista ya existe";
      break;

    case 2:
      if (lista1 != NULL)
        insertarNodoSuma(lista1);
      else
        cout << "\nLa lista 1 no existe";
      break;

    case 3:
      if (lista1 != NULL)
      {
        insertarPromedio(lista1, lista2);
        cout << "\nLista 2 creada: ";
        //insertarFinal(lista2, 40); // TEST
        listarNodos(lista2);
      }
      else
        cout << "\nLa lista 1 no existe, no se puede crear la lista 2";
      break;

    case 4:
      if (lista1 != NULL)
      {
        cout << "\nLista 1: ";
        listarNodos(lista1);
      }
      else
        cout << "\nLa lista 1 no existe";

      if (lista2 != NULL)
      {
        cout << "\nLista 2: ";
        listarNodos(lista2);
        transferirLista(lista1, lista2);
      }
      else
        cout << "\nLa lista 2 no existe";

      break;

    case 5:
      if (lista1 != NULL)
        cout << "\nPromedio lista 1 = " << promediarLista(lista1);
      else
        cout << "\nLa lista 1 no existe";

      if (lista2 != NULL)
        cout << "\nPromedio lista 2 = " << promediarLista(lista2);
      else
        cout << "\nLa lista 2 no existe";
      break;

    case 6:
      if (lista2 != NULL)
        eliminarMayores(lista2, promediarLista(lista2));
      else
        cout << "\nLa lista 2 no existe";
      break;
    }

    cout << endl
         << endl;
    system("pause");
  } while (op != 0);

  return 0;
}