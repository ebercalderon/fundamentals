/*	Actividades resueltas 5.9
	Escribir un algoritmo que permita escribir en una pantalla la frase 
	‘¿Desea continuar? S/N’ hasta que la respuesta sea 'S' o 'N'	*/

#include <iostream>
using namespace std;
int main(){
	char rpta;
	
	do{
		cout << "Desea continuar? : ";
		cin >> rpta;
	}while(rpta!='n' && rpta!='s');
	
	return 0;
}
