/*	Realizar un algoritmo que permita ordenar tres números mediante un 
	procedimiento de intercambio en dos variables (paso de parámetros 
	por referencia).	*/

#include <iostream>
using namespace std;

float intercambio (float *a, float *b);

int main(){
	float x, y, z;
	
	cout << "Ingrese 3 numeros a evaluar: \n";
	cin >> x >> y >> z;
	
	if (x > y)
		intercambio (&x, &y);
	
	if (y > z)
		intercambio (&y, &z);
	
	if (x > y)
		intercambio (&x, &y);
	
	cout << "\n" << x << "\t" << y << "\t" << z;
	
	return 0;
}

float intercambio (float *a, float *b){
	float aux;
	
	aux = *a;
	*a = *b;
	*b = aux;
}
