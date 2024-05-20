/*	Ejemplo 5.20
	Aplicación de bucles anidados	*/

#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	
	cout << setw(16) << " i " << setw(5) << " j " << endl;
	
	for (int i = 0; i < 4; i++){
		cout << "Externo " << setw(7) << i << endl;
		for (int j = 0; j < i; j++){
			cout << setw(10) << "Interno " << setw(10) << j << endl;
		}
	}// fin del bucle externo
	
}
