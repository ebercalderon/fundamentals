/*	Ejemplo 5.17
	Calcular el factorial de n números leídos del terminal	*/

#include <iostream>
using namespace std;
int main(){
	int n, num; 
	double fact;
	int i;
	
	cout<<"Ingrese la cantidad de numeros: ";
	cin>>n;
	
	for (i=1;i<=n;i++){
		cout<<"Ingrese numero: ";
		cin>>num;
		
		fact=1;
		
		for (int j=1;j<=num;j++){
			fact=fact*j;
		}
		cout<<"El factorial del numero es: "<<fact<<endl;
	}
	return 0;
}

/*	Solución
	El problema consistirá en realizar una estructura repetitiva de n iteraciones 
	del algoritmo del problema ya conocido del cálculo del factorial de un entero
*/
