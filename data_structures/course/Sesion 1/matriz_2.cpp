#include <iostream>
#define N 4
#define M 5
using namespace std;

int main()
{
	int ventas[N][M] = {{1, 11234, 13245, 10123, 15021}, {2, 10234, 11445, 11423, 13025}, {3, 10234, 15245, 13123, 12021}, {4, 10236, 14645, 11123, 14021}};
	int sumaAnual;
	// mostrar
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << ventas[i][j] << " ";
		cout << endl;
	}
	// ventas anuales
	cout << "" << endl;
	cout << "La venta anual por ciudad " << endl;
	for (int i = 0; i < N; i++)
	{
		sumaAnual = 0;
		for (int j = 1; j < M; j++)
			sumaAnual = sumaAnual + ventas[i][j];
		cout << "Ciudad " << i + 1 << " es " << sumaAnual << endl;
	}

	// ventas totales por trimestre
	cout << "" << endl;
	cout << "La venta total por trimestre" << endl;
	for (int j = 0; j < N; j++)
	{
		sumaAnual = 0;
		for (int i = 1; i < M; i++)
			sumaAnual = sumaAnual + ventas[j][i];
		cout << "Trimestre " << j + 1 << " es " << sumaAnual << endl;
	}
}
