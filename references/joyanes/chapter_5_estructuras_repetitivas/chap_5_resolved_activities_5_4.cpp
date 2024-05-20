/*	Actividades resueltas 5.4
	Diseñar el algoritmo para imprimir la suma de los números impares menores o iguales que n	*/

#include <iostream>
using namespace std;
int main(){
	int n, suma;
	
	cout << "Digite n: ";
	cin >> n;
	
	for ( int i=1; i<=n; i+=2)
		suma=suma+i;
	
	cout << "La suma es: " << suma;
	return 0;
}
