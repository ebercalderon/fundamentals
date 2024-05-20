// librer�a
#include <iostream>
#define N 3
#define T 3
using namespace std;
int main()
{
	// mostrar mensajes
	cout << "Hola\n";
	// declarar variables
	int x, i;
	float y;
	bool z;
	char c;
	// asignar valores
	i = 0;
	x = 10;
	y = 2.3;
	z = true;
	c = 'a';
	// mostrar valores
	cout << x << endl;
	cout << y << endl;
	cout << z << endl;
	cout << c << endl;
	// leer
	cout << "Ingrese el valor de x: ";
	cin >> x;
	cout << "El nuevo valor de x es " << x << endl;
	// Estructura de Control Condicional
	if (x > 50)
		cout << "Es mayor a 50" << endl;
	else
		cout << "No es mayor a 50" << endl;
	// Estrutura de Control Repetitiva
	while (i < x)
	{
		cout << i << endl;
		i = i + 1;
	}

	for (int j = 1; j < 10; j++)
		cout << j << " ";

	// arreglos
	// declaraci�n
	int A[5];
	// ingresamos datos al arreglo
	A[0] = 20;
	A[4] = 3;
	A[10] = 100;
	// acceder al arreglo
	cout << endl
		 << A[10] << endl;
	// error com�n

	float B[N];
	// un arreglo es una ED est�tica por lo tanto no puedes definir su tama�o en la ejecuci�n.
	for (int k = 0; k < N; k++)
		cin >> B[k];
	for (int k = 0; k < N; k++)
		cout << B[k] << " ";

	// una matriz
	char M[2][3];
	M[1][1] = 'a';
	cout << endl
		 << M[1][1] << endl;

	int R[N][T];
	// leer
	for (int i = 0; i < N; i++){
		for (int j = 0; j < T; j++)
			cin >> R[i][j];
	}
	// mostrar
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < T; j++)
			cout << R[i][j] << " ";
		cout << endl;
	}
} // fin main()
