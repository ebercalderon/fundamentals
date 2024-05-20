/*	Actividades resueltas 5.17 
	Detección de entradas numéricas —enteros— erróneas.	*/

#include <iostream>
using namespace std;
int main(){
	int sw;
	float n;
	
	sw=0;
	
	while ( sw==0 ){
		cin >> n;
		
		if ( n!= int(n)){
			cout << "Dato no valido" <<endl
				 << "Ejecute nuevamente";
			sw=1;	
		}else{
			cout << "Correcto " << n << " es entero";
		}
	}
	
	return 0;
}

/*	Soución
	Este algoritmo es una aplicación sencilla de «interruptor». 
	Se sitúa el valor inicial del interruptor (SW = 0) antes de 
	recibir la entrada de datos. La detección de números no 
	enteros se realizará con una estructura repetitiva mientras
	que se realizará si SW = 0.
	La instrucción que detecta si un número leído desde el 
	dispositivo de entradas es entero:
	
		leer(N)
		
	Realizará la comparación de N y parte entera de N:
	• si son iguales, N es entero,
	• si son diferentes, N no es entero.
	
	Un método para calcular la parte entera es utilizar la 
	función estándar ent (int) existente en muchos lenguajes 
	de programación.
*/
