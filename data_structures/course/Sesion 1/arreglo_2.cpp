#include <iostream>
#define N 10
using namespace std;

int main()
{
	float notas[N] = {10, 13, 12, 15, 14, 8, 6, 5, 20, 30};
	float suma = 0;
	float prom;
	int apro = 0;
	int desa = 0;
	// imprimir
	for (int i = 0; i < N; i++)
		cout << notas[i] << " ";

	// promedio
	cout << "" << endl;
	for (int i = 0; i < N; i++)
		suma = suma + notas[i];
	prom = suma / N;
	cout << "El promedio general es " << prom << endl;

	for (int i = 0; i < N; i++)
	{
		if (notas[i] >= 12)
		{
			apro = apro + 1;
		}
		else
		{
			desa = desa + 1;
		}
	}
	cout << "El numero de alumnos aprobados es: " << apro << endl;
	cout << "El numero de alumnos desaprobados es: " << desa << endl;
}
