/*	Actividades resueltas 6.1	(Recursividad)
	Factorial	*/
	
#include <iostream>
using namespace std;

float factorial (float n);

int main(){
	float num;
	char rpta;
	
	do{
		cout << "Digite numero: ";
		cin >> num;
		cout << factorial(num) << endl;


		cout << "Otro operacion? (Y/N): ";
		cin >> rpta;
	}while (rpta != 'N' && rpta != 'n');
	
	return 0;
}

float factorial(float n){
	
	if (n == 0)
		return 1;
	else
		return n*factorial(n-1);
}
