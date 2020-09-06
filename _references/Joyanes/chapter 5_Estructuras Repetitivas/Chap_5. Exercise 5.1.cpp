/*	Ejercicio 5.1
	Determinar la media de una lista indefinida de 
	números positivos, terminados con un número negativo	*/

#include <iostream>
using namespace std;
int main(){
	float suma=0;
	int n, cont=0;
	
	do{
		cin >> n;
		if (n>=0){
			suma = suma+n;
			cont++;
		}
	}while(n>=0);
	
	system ("cls");
	cout << "El promedio es: " << suma/cont;
	
	return 0;
}
