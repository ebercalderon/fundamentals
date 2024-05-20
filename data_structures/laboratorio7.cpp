/**
 * LABORATORIO 7
 * METODOS DE ORDENAMIENTO CON ESTRUCTURAS DINAMICAS
 */

#include <stdlib.h> // srand(), rand()
#include <time.h>   // time()
#include <iostream>

using namespace std;

struct nodo
{
  int nro;
  int pos;
  struct nodo *sgte;
};

typedef struct nodo *Tlista;

/*                        Insertar al inicio    
------------------------------------------------------------------------*/
void insertarInicio(Tlista &lista, int valor)
{
  Tlista q;
  q = new (struct nodo);
  q->nro = valor;
  q->sgte = lista;
  lista = q;
}

/*                        Insertar al final  
------------------------------------------------------------------------*/
void insertarFinal(Tlista &lista, int valor, int pos)
{
  Tlista t, q = new (struct nodo);

  q->nro = valor;
  q->pos = pos;
  q->sgte = NULL;

  t = lista;

  if (lista == NULL)
  {
    lista = q;
  }
  else
  {
    t = lista;
    while (t->sgte != NULL)
    {
      t = t->sgte;
    }
    t->sgte = q;
  }
}

/*                        Listar nodos  
------------------------------------------------------------------------*/
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

/*                        Punto 1  
------------------------------------------------------------------------*/
void generarElementos(Tlista &lista)
{
  srand(time(NULL));

  for (int i = 0; i < 12; i++)
    insertarFinal(lista, -50 + rand() % 120, i + 1);
}

/*                        Punto 2  
------------------------------------------------------------------------*/
void dividirListas(Tlista lista, Tlista &positivos, Tlista &negativos)
{
  int p = 0, n = 0;

  //Tlista lista;

  while (lista != NULL)
  {
    if (lista->nro >= 0){
      p++;
      insertarFinal(positivos, lista->nro, p);
    }

    else
    {
      n++;
      insertarFinal(negativos, lista->nro, n);
    }
    lista = lista->sgte;
  }
}

/*                         Punto 3 - Metodo Burbuja 
------------------------------------------------------------------------*/
Tlista intercambio(Tlista ptr1, Tlista ptr2)
{
  Tlista tmp = ptr2->sgte;
  int aux;

  ptr2->sgte = ptr1;
  aux = ptr1->pos;
  ptr1->pos = ptr2->pos;
  ptr2->pos = aux;

  ptr1->sgte = tmp;
  return ptr2;
}

void metodoBurbuja(Tlista *lista, int cont)
{
  struct nodo **h;
  int i, j, aux;

  for (i = 0; i <= cont; i++)
  {

    h = lista;
    aux = 0;

    for (j = 0; j < cont - i - 1; j++)
    {

      struct nodo *p1 = *h;
      struct nodo *p2 = p1->sgte;

      if (p1->nro > p2->nro)
      {

        *h = intercambio(p1, p2);

        aux = 1;
      }

      h = &(*h)->sgte;
    }

    if (aux == 0)
      break;
  }
}

/*                        Punto 4 - Metodo de seleccion  
------------------------------------------------------------------------*/
nodo *metodoSeleccion(nodo *lista)
{
  nodo *a, *b, *c, *d, *r;

  a = b = lista;

  while (b->sgte)
  {

    c = d = b->sgte;

    while (d)
    {

      if (b->nro > d->nro)
      {

        if (b->sgte == d)
        {

          if (b == lista)
          {

            b->sgte = d->sgte;
            d->sgte = b;

            r = b;
            b = d;
            d = r;

            c = d;

            lista = b;

            d = d->sgte;
          }
          else
          {

            b->sgte = d->sgte;
            d->sgte = b;
            a->sgte = d;

            r = b;
            b = d;
            d = r;

            c = d;

            d = d->sgte;
          }
        }
        else
        {

          if (b == lista)
          {

            r = b->sgte;
            b->sgte = d->sgte;
            d->sgte = r;
            c->sgte = b;

            r = b;
            b = d;
            d = r;

            c = d;

            d = d->sgte;

            lista = b;
          }
          else
          {

            r = b->sgte;
            b->sgte = d->sgte;
            d->sgte = r;
            c->sgte = b;
            a->sgte = d;

            r = b;
            b = d;
            d = r;

            c = d;

            d = d->sgte;
          }
        }
      }
      else
      {

        c = d;
        d = d->sgte;
      }
    }

    a = b;
    b = b->sgte;
  }

  return lista;
}

/*                         Punto 5 - Busqueda binaria 
------------------------------------------------------------------------*/
struct nodo *medio(nodo *inicio, nodo *final)
{
  if (inicio == NULL)
    return NULL;

  struct nodo *temp1 = inicio;
  struct nodo *temp2 = inicio->sgte;

  while (temp2 != final)
  {
    temp2 = temp2->sgte;
    if (temp2 != final)
    {
      temp1 = temp1->sgte;
      temp2 = temp2->sgte;
    }
  }

  return temp1;
}

struct nodo *busquedaBinaria(nodo *lista, int valor)
{
  struct nodo *inicio = lista;
  struct nodo *final = NULL;
  int cont = 0;

  do
  {
    nodo *mitad = medio(inicio, final);

    if (mitad == NULL)
      return NULL;

    if (mitad->nro == valor)
      return mitad;

    else if (mitad->nro < valor)
      inicio = mitad->sgte;

    else
      final = mitad;

  } while (final == NULL || final != inicio);

  return NULL;
}

/*                        Presentacion    
------------------------------------------------------------------------*/
void presentacion()
{
  system("cls");

  cout << "\n==============================="
       << "\n....:::: LABORATORIO 7 ::::...."
       << "\n===============================\n"
       << "\nCalderon Claudio, Eber Andres\t18200214\n\n";
}

void separador()
{
  cout << endl
       << endl;
  for (int i = 0; i < 60; i++)
    cout << char(196);
  cout << endl
       << endl;
}

int main()
{
  Tlista lista = NULL;
  Tlista positivos = NULL;
  Tlista negativos= NULL;

  int x = 0;
  struct nodo *aux;

  presentacion();

  cout << "Punto 1:\n\n";
  generarElementos(lista);
  listarNodos(lista);
  separador();

  cout << "Punto 2:\n";
  dividirListas(lista, positivos, negativos);
  cout << "\nPositivos: ";listarNodos(positivos);
  cout << "\nNegativos: ";listarNodos(negativos);
  separador();

  cout << "Punto 3:\n\n";
  metodoBurbuja(&positivos, contarNodos(positivos));
  listarNodos(positivos);
  separador();

  cout << "Punto 4:\n\n";
  negativos = metodoSeleccion(negativos);
  listarNodos(negativos);
  separador();

  cout << "Punto 5:\n\nIngrese valor positivo a buscar: "; cin >> x;
  aux = busquedaBinaria(positivos, x);
  aux != NULL ? cout << "Se encontro el valor: " << aux->nro << " en la posicion " << aux->pos : cout << "No existe el valor";

  cout << "\n\nIngrese valor negativo a buscar: "; cin >> x;
  aux = busquedaBinaria(negativos, x);
  aux != NULL ? cout << "Se encontro el valor: " << aux->nro : cout << "No existe el valor";

  cout << endl
       << endl;
  system("pause");

  return 0;
}