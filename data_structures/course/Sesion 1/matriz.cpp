#include <iostream>
#define N 4
#define M 5
using namespace std;

int main()
{
	int ventas[N][M] = {{1, 11234, 13245, 10123, 15021}, {2, 10, 13, 14, 15}, {3, 40, 12, 30, 15}, {4, 11, 13, 14, 15}};
	int sumaAnual;
	// mostrar
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << ventas[i][j] << " ";
		cout << endl;
	}
	// ventas anuales
	cout << "La venta anual " << endl;
	for (int i = 0; i < N; i++)
	{
		sumaAnual = 0;
		for (int j = 1; j < M; j++)
			sumaAnual = sumaAnual + ventas[i][j];
		cout << "Ciudad " << i + 1 << " es " << sumaAnual << endl;
	}
}
