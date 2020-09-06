/*	Ejemplo 6.6
	Algoritmo que simplifique un quebrado, dividiendo numerador 
	y denominador por su maximo comun divisor	*/
	
#include <iostream>
using namespace std;

int MCD (int n, int d);

int main(){
	int n, d;
	char rpta;
	
	do{
		cout << "Digite numerador: ";
		cin >> n;
		cout << "Digite denomidador: ";
		cin >> d;
		cout << n << "/" << d << " = " << n/MCD(n,d) << "/" << d/MCD(n,d) << endl;
		cout << "Otra operacion? (Y/N): ";
		cin >> rpta;
	}while (rpta != 'N' && rpta != 'n');
	
	return 0;
}

int MCD(int n, int d){
	int r;
	
	r = n%d;
	
	while (r != 0){
		d = r;
		n = d;
		r = n%d;
	}
	return d;
}


