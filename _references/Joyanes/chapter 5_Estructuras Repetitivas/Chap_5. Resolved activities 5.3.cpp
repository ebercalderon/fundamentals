/*	Actividades resueltas 5.3
	Calcular la suma de los n primeros números enteros utilizando la estructura desde.	*/

#include <iostream>
using namespace std;
int main(){
	int n, suma;
	
	cout << "Digite n: ";
	cin >> n;
	
	for ( int i=1; i<=n; i++)
		suma=suma+i;
	
	cout << "La suma es: " << suma;
	return 0;
}
