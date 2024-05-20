/**
 * LABORATORIO 1
 * ESTRUCTURAS ESTATICAS
 */

#include <stdlib.h> // srand(), rand()
#include <time.h>   // time()
#include <iomanip>  // setw()
#include <iostream>

using namespace std;

// Constantes
const int FILAS = 20;
const int COLUMNAS = 2;

void generar_elementos(int matriz[][COLUMNAS])
{
  int num;
  srand(time(NULL));

  for (int i = 0; i < FILAS; i++)
  {
    for (int j = 0; j < COLUMNAS; j++)
    {
      do
      {
        num = -30 + rand() % 100;
      } while (num == 0);

      matriz[i][j] = num;
    }
  }
}

void mostrar_matriz(int matriz[][COLUMNAS])
{
  for (int i = 0; i < FILAS; i++)
  {
    for (int j = 0; j < COLUMNAS; j++)
    {
      cout << setw(11) << matriz[i][j] << "  ";
    }
    cout << endl;
  }
}

void mostrar_vector(int vector[], int TAM)
{
  for (int i = 0; i < TAM; i++)
  {
    cout << setw(5) << vector[i] << "  ";
  }
  cout << setw(11) << "|| Primero: " << vector[0] << setw(11) << "Ultimo: " << vector[TAM - 1] << setw(11) << "Medio: " << vector[TAM / 2] << endl;
}

void analizar(int matriz[][COLUMNAS], int a[], int b[], int c[], int d[])
{
  int pp = 0, pi = 0, np = 0, ni = 0;

  for (int i = 0; i < FILAS; i++)
  {
    for (int j = 0; j < COLUMNAS; j++)
    {
      if (matriz[i][j] > 0)
      {
        if (matriz[i][j] % 2 == 0)
        {
          a[pp] = matriz[i][j];
          pp++;
        }
        else
        {
          b[pi] = matriz[i][j];
          pi++;
        }
      }
      else
      {
        if (matriz[i][j] % 2 == 0)
        {
          c[np] = matriz[i][j];
          np++;
        }
        else
        {
          d[ni] = matriz[i][j];
          ni++;
        }
      }
    }
  }

  cout << "\nPositivo par  :";
  mostrar_vector(a, pp);
  cout << "\nPositivo impar:";
  mostrar_vector(b, pi);
  cout << "\nNegativo par  :";
  mostrar_vector(c, np);
  cout << "\nNegativo impar:";
  mostrar_vector(d, ni);
}

int main()
{
  int matriz[FILAS][COLUMNAS]; // guarda los numeros generados
  int positivo_par[30];
  int positivo_impar[30];
  int negativo_par[30];
  int negativo_impar[30];

  cout << "\n==============================="
       << "\n....:::: LABORATORIO 1 ::::...."
       << "\n===============================\n"
       << "\nCalderon Claudio, Eber Andres\t18200214\n"
       << "\nMatriz generada:\n\n";

  generar_elementos(matriz);
  mostrar_matriz(matriz);

  cout << "\nVectores:\n";
  analizar(matriz, positivo_par, positivo_impar, negativo_par, negativo_impar);

  system("pause");

  return 0;
}