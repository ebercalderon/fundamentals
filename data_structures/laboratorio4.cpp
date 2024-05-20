#include <stdlib.h> // srand(), rand()
#include <time.h>   // time()
#include <string.h>
#include <iostream>

using namespace std;

/*                Constantes    
------------------------------------------------------------------------*/
const int PEDIDOS = 10;
const int CONTENEDORtope = 500;
const int CAMIONpe = 200;
const int CAMIONnp = 100;

/*                Estructura del tipo de caja     
------------------------------------------------------------------------*/
struct caja
{
  int nro;
  string tp;
};

/*                Estructura de los nodos de la cola      
------------------------------------------------------------------------*/
struct nodo
{
  caja pedido;
  struct nodo *sgte;
};

/*                      Estructura de la cola      
------------------------------------------------------------------------*/
struct cola
{
  nodo *delante;
  nodo *atras;
};

typedef nodo *ptrPila; // creando nodo tipo puntero( tipo de dato )

/*                        Encolar elemento      
------------------------------------------------------------------------*/
void encolar(struct cola &q, int valor, string tipo)
{
  struct nodo *aux = new (struct nodo);

  aux->pedido.nro = valor;
  aux->pedido.tp = tipo;
  aux->sgte = NULL;

  if (q.delante == NULL)
    q.delante = aux; // encola el primer elemento
  else
    (q.atras)->sgte = aux;

  q.atras = aux; // puntero que siempre apunta al ultimo elemento
}

/*                        Desencolar elemento      
------------------------------------------------------------------------*/
caja desencolar(struct cola &q)
{
  struct nodo *aux;
  caja pedido;

  aux = q.delante; // aux apunta al inicio de la cola
  pedido.nro = aux->pedido.nro;
  pedido.tp = aux->pedido.tp;
  q.delante = (q.delante)->sgte;
  delete (aux); // libera memoria a donde apuntaba aux

  return pedido;
}

/*                        Mostrar Cola      
------------------------------------------------------------------------*/
void mostrarCola(struct cola q)
{
  struct nodo *aux;

  aux = q.delante;

  while (aux != NULL)
  {
    cout << "[" << aux->pedido.nro << "|" << aux->pedido.tp << "]   ";
    aux = aux->sgte;
  }
}

/*                        Apilar elemento      
------------------------------------------------------------------------*/
void push(ptrPila &p, int valor, string tipo)
{
  ptrPila aux;
  aux = new (struct nodo); // apuntamos al nuevo nodo creado
  aux->pedido.nro = valor;
  aux->pedido.tp = tipo;

  aux->sgte = p;
  p = aux;
}

/*                Desapilar elemento (devuelve elemento)      
------------------------------------------------------------------------*/
caja pop(ptrPila &p)
{
  ptrPila aux;
  caja pedido;

  aux = p;
  pedido.nro = aux->pedido.nro; // asignamos el primer vamor de la pila
  pedido.tp = aux->pedido.tp;

  p = aux->sgte;
  delete (aux);

  return pedido;
}

/*                     Muestra elementos de la pila      
------------------------------------------------------------------------*/
void mostrarPila(ptrPila p)
{
  ptrPila aux;
  aux = p; // apunta al inicio de la lista

  while (aux != NULL)
  {
    cout << "\t[" << aux->pedido.nro << "|" << aux->pedido.tp << "]   " << endl;
    aux = aux->sgte;
  }
}

/*                        1.- Recibir pedidos    
------------------------------------------------------------------------*/
void insertarPedidos(struct cola &q)
{
  srand(time(NULL));
  string tipo;

  for (int i = 0; i < PEDIDOS; i++)
  {
    rand() % 2 ? tipo = "NP" : tipo = "PE";
    encolar(q, 1 + rand() % 50, tipo);
  }
}

/*                        2.- Extraer y clasificar   
------------------------------------------------------------------------*/
void extraerPedidos(struct cola &q, ptrPila &pe, ptrPila &np)
{
  struct nodo *aux;
  int acumulador = 0;

  aux = q.delante;

  cout << "\n\tTRANSFERIDOS\n";
  while (aux != NULL && acumulador < CONTENEDORtope)
  {
    acumulador += aux->pedido.nro;

    if (acumulador < CONTENEDORtope)
    {
      cout << "[" << aux->pedido.nro << "|" << aux->pedido.tp << "]   ";
      
      if (aux->pedido.tp == "PE")
      {
        push(pe, aux->pedido.nro, aux->pedido.tp);
      }
      else
      {
        push(np, aux->pedido.nro, aux->pedido.tp);
      }
    }

    aux = aux->sgte;
  }
}

/*                        Menu de opciones    
------------------------------------------------------------------------*/
int menu()
{
  int opcion;
  system("cls");

  cout << "\n==============================="
       << "\n....:::: LABORATORIO 4 ::::...."
       << "\n===============================\n"
       << "\nCalderon Claudio, Eber Andres\t18200214\n"
       << "\n1.- Encolar pedidos"
       << "\n2.- Desencolar pedidos y apilar contenedores"
       << "\n3.- Desapilar contenedores"
       << "\n4.- Mostrar estatus de pedidos\n"
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
  struct cola q;
  q.delante = NULL;
  q.atras = NULL;

  ptrPila np = NULL; // creando pila  no perecibles
  ptrPila pe = NULL; // creando pila perecibles

  int op; // opcion del menu
  caja x; // numero que devuelve la funcon pop

  do
  {
    op = menu();

    switch (op)
    {
    case 1:
      if (q.delante == NULL)
      {
        insertarPedidos(q);
        cout << "\n\tTotal de pedidos generados en cola: " << PEDIDOS;
      }
      else
      {
        cout << "\n\tPedidos ya generados:\n\n\t";
        mostrarCola(q);
      }
      break;

    case 2:
      if (q.delante != NULL)
      {
        extraerPedidos(q, pe, np);
        //x = desencolar(q);
        //cout << "\n\n\t\tNumero " << x.nro << " | " << x.tp << " desencolado...\n\n";
      }
      else
      {
        cout << "\n\tNecesita encolar los pedidos";
      }

      break;

    case 4:
      cout << "\n\tPEDIDOS EN COLA\n\t";
      if (q.delante != NULL)
        mostrarCola(q);
      else
        cout << "\n\tCola vacia" << endl;
      
      cout << "\n\n\tPILA NO PERECIBLES\n";
      if (pe != NULL)
        mostrarPila(np);
      else
        cout << "\n\tPila vacia" << endl;

      cout << "\n\n\tPILA PERECIBLES\n";
      if (pe != NULL)
        mostrarPila(pe);
      else
        cout << "\n\tPila vacia" << endl;
      
      break;
    }

    cout << endl
         << endl;
    system("pause");

  } while (op != 0);

  return 0;
}