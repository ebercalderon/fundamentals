#include <iostream>

using namespace std;

// constantes
const int N = 10;

int main()
{
	float notas[N] = {10, 13, 12, 15, 14, 8, 6, 5, 20, 30};
	float suma = 0;
	float prom;

	// imprimir
	for (int i = 0; i < N; i++)
		cout << notas[i] << " ";

	// promedio

	for (int i = 0; i < N; i++)
		suma = suma + notas[i];

	prom = suma / N;

	cout << "El promedio es " << prom << endl;

}
