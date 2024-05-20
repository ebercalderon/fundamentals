/*	Ejercicio resuelto 5.2
	Ejecutar y visualizar el programa siguiente que imprime 
	una tabla de m filas por n columnas y un carácter prefijado.	*/

#include <iostream>
using namespace std;
int main(){
	int filas, columnas;
	char caracter;
	
	cout << "Numero de filas: "; 	
	cin >> filas;
	cout << "Numero de columnas: "; 
	cin >> columnas;
	cout << "Digite caracter: "; 	
	cin >> caracter;
	
	for (int i; i < filas; i++){
		for (int j = 0; j < columnas; j++)
			cout << caracter;
		
		cout <<"\n"; 
	}
	
	return 0;
}

