#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <iostream>

using namespace std;

// Constante
const int LIM = 64;

// Funcion para realizar las operaciones correspondientes
void operaciones(int a[][LIM], int b[][LIM], int c[][LIM],  int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == 0 || j == n-1)
                c[i][j] = b[i][j] * a[i][j];
            else
                c[i][j] = b[i][j] + a[i][j];
        }
    }
}

// Funcion de utilidad para imprimir un arreglo de tamanio nxn
void imprimir_arreglo(int a[][LIM], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(5) << a[i][j] << " ";

        cout << endl;
    }
}

// Funcion de utilidad ingresar elementos al segundo arreglo
void ingresar_datos_2(int a[][LIM], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            a[i][j] = 1 + rand() % 9;
    }
}

// Funcion de utilidad ingresar elementos al primer arreglo
void ingresar_datos_1(int a[][LIM], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            a[i][j] = 30 + rand() % 30;
    }
}

// Funcion de utilidad para pedir el tamanio del arreglo
int pedir_tamanio()
{
    int n;
    do
    {
        cout << "Ingrese el tamanio del arreglo: ";
        cin >> n;
    } while (n < 2);

    return n;
}

/* Principal */
int main()
{
    int n;
    int arreglo1[LIM][LIM], arreglo2[LIM][LIM], arreglo3[LIM][LIM];

    n = pedir_tamanio();
    ingresar_datos_1(arreglo1, n);
    ingresar_datos_2(arreglo2, n);

    cout << "Arreglo 1" << endl;
    imprimir_arreglo(arreglo1, n);
    cout << "\nArreglo 2" << endl;
    imprimir_arreglo(arreglo2, n);

    operaciones(arreglo1, arreglo2, arreglo3, n);

    cout << "\nArreglo 3" << endl;
    imprimir_arreglo(arreglo3, n);

    system("pause");

    return 0;
}