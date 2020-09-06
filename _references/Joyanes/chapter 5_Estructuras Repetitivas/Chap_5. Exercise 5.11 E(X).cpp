/*	Ejercicio 5.11
	Calcular:
	E(x) = 1 + x + x^2/2! + x^n/n!

	a) Para N que es un entero leído por teclado.
	b) Hasta que N sea tal que x^n/n < E (por ejemplo,E = 10^–4).	*/

#include <iostream>
#include <math.h>
using namespace std;
int main(){
	float E=1, acum=1, val;
	int n, x;
	
	//Ingreso de datos
	cout << "Ingrese el valor de X: ";
	cin >> x;
	do{
		cout << "Ingrese el valor de N: "; //a)
		cin >> n;
	}while (n<0);
	
	//Desarrollo
	for (int i=1; i<=n; i++){
		acum=acum*x/i*(1.0);
		E=E+acum;
	}
	
	//Validación b)
	val=pow(x,n)/n;
	system ("cls");
	
	//Salida
	if ( val < E )
		cout << "El resultado de E(x) es: " << E;
	else
		cout << "x^n/n > E(x)";
	
	return 0;
}
