/*	Ejemplo 6.13	(Recursividad)
	Otro ejemplo típico de una función recursiva es la serie 
	Fibonacci. Esta serie fue concebida originalmente como
	modelo para el crecimiento de una granja de conejos 
	(multiplicación de conejos) por el matemático italiano 
	del siglo XVI, Fibonacci.	*/
	
#include <iostream>
using namespace std;

float fibonacci (float n);

int main(){
	float num;
	char rpta;
	
	do{
		cout << "Digite numero: ";
		cin >> num;
		cout << fibonacci(num) << endl;


		cout << "Otro operacion? (Y/N): ";
		cin >> rpta;
	}while (rpta != 'N' && rpta != 'n');
	
	return 0;
}

float fibonacci(float n){
	
	if (n == 1 || n == 2)
		return 1;
	else
		return fibonacci(n-2) + fibonacci(n-1);
}
