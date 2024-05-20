/**
 * LABORATORIO 2
 * LISTAS ENLAZADAS SIMPLES
 */

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
const int TAM = 20;

/*                        Operaciones con listas   
------------------------------------------------------------------------*/
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

void unirListas(Tlista &a, Tlista &b, Tlista &c) // Punto 5
{
  Tlista aux, secundaria, primaria, unido;
  aux = a;
  secundaria = b;
  primaria = new (struct nodo);
  primaria->nro = aux->nro;
  primaria->sgte = NULL;
  c = primaria;
  aux = aux->sgte;

  while (aux != NULL)
  {
    primaria = new (struct nodo);
    primaria->nro = aux->nro;
    primaria->sgte = NULL;
    unido = c;

    while (unido->sgte != NULL)
      unido = unido->sgte;

    unido->sgte = primaria;
    aux = aux->sgte;
  }

  while (secundaria != NULL)
  {
    primaria = new (struct nodo);
    primaria->nro = secundaria->nro;
    primaria->sgte = NULL;
    unido = c;

    while (unido->sgte != NULL)
      unido = unido->sgte;

    unido->sgte = primaria;
    secundaria = secundaria->sgte;
  }
}

void listarNodos(Tlista lista)
{
  Tlista q = lista;

  while (q != NULL)
  {
    cout << q -> nro << "  ";
    q = q -> sgte;
  }
}

int contarNodos(Tlista lista)
{
  Tlista q = lista;
  int cont = 0;

  while (q != NULL)
  {
    cont++;
    q = q -> sgte;
  }

  return cont;
}

/*                        Operaciones con vector   
------------------------------------------------------------------------*/
void generarElementos(int vector[]) // Punto 1
{
  srand(time(NULL));

  for (int i = 0; i < TAM; i++)
    vector[i] = 1 + rand() % 100;
}

void mostrarVector(int vector[])
{
  for (int i = 0; i < TAM; i++)
    cout << vector[i] << "  ";
}

// Punto 2
void analizarListas(int vector[], Tlista &a, Tlista &b)
{
  for (int i = 0; i < TAM; i++)
  {
    if (vector[i] % 2 == 0)
      insertarInicio(a, vector[i]);
    else
      insertarInicio(b, vector[i]);
  }
}

// Punto 3
void convertirLista(Tlista &lista)
{
  Tlista q = lista;
  int cont = 0;

  while (q != NULL)
  {
    q -> nro += 1;
    q = q -> sgte;
  }
}

// Punto 4
int promediarLista(Tlista lista)
{
  Tlista q = lista;
  int pro, suma = 0, total = 0;

  while (q != NULL)
  {
    total++;
    suma += q -> nro;
    q = q -> sgte;
  }
  
  pro = suma/total;
  insertarFinal(lista, pro);

  return pro;
}

// Delimitador
void separador()
{
  cout << endl;
  for (int i = 0; i < 60; i++)
    cout << char(196);
}

int main()
{
  int vector[TAM]; // guarda los numeros generados
  Tlista listaPar = NULL;
  Tlista listaImpar = NULL;
  Tlista listaUnida = NULL;

  cout << "\n==============================="
       << "\n....:::: LABORATORIO 2 ::::...."
       << "\n===============================\n"
       << "\nCalderon Claudio, Eber Andres\t18200214";
       
  generarElementos(vector);
  analizarListas(vector, listaPar, listaImpar);

  cout << "\n\nVector generado: "; mostrarVector(vector);
  separador();

  cout << "\n\nLista Impar: "; listarNodos(listaImpar); cout << " | Total Impares: " << contarNodos(listaImpar); 
  cout << "\n\nLista Par: "; listarNodos(listaPar); cout << " | Total Pares: " << contarNodos(listaPar);
  separador();

  convertirLista(listaImpar); convertirLista(listaPar);
  cout << "\n\nLista Impar: "; listarNodos(listaImpar);
  cout << "\n\nLista Par: "; listarNodos(listaPar);
  separador();

  cout << "\n\nPromedio Lista 1 ---> " << promediarLista(listaImpar) << "   | "; listarNodos(listaImpar);
  cout << "\n\nPromedio Lista 2 ---> " << promediarLista(listaPar) << "   | "; listarNodos(listaPar);
  separador();

  unirListas(listaImpar, listaPar, listaUnida); cout << endl << endl; listarNodos(listaUnida);


  cout << endl;
  system("pause");

  return 0;
}