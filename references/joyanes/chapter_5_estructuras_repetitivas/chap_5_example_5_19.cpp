/*	Ejemplo 5.19
	El segmento de programa siguiente visualiza una tabla de multiplicación 
	por cálculo y visualización de productos de la forma x * y para cada x 
	en el rango de 1 a Xultimo y desde cada y en el rango 1 a Yultimo (donde
	Xultimo, e Yultimo son enteros prefijados).	*/

#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	int Xultimo=12;
	int Yultimo=12;
	int producto;
	
	for (int x = 1; x <= Xultimo; x++){
		cout<< "Tabla del " << x << endl;
		for (int y = 1; y <= Yultimo; y++){
			producto = x * y;		
			cout<< setw(2) << x << " * "
				<< setw(2) << y << " = "
				<< setw(3) << producto << endl;
		}
		cout<<"\n";
	}
	return 0;
}
