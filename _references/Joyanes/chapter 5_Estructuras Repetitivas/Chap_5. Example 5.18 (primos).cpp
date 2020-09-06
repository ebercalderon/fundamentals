/*	Ejemplo 5.18
	Imprimir todos los número primos entre 2 y 100 inclusive	*/

#include <iostream>
#include <math.h>
using namespace std;
int main(){
	int i, divisor;
	bool primo;
	
	for (i=2;i<=100;i++){
		primo=true;
		divisor=2;
		while(divisor<=sqrt(i) && primo){
			if (i%divisor==0)
				primo=false;
			else
				divisor++;
		}
		if (primo)
			cout<<i<<endl;
	}
	return 0;
}
/*	Solución
	Para saber si un número es primo basta con probar si el número 
	no es divisible por los primos hasta su raiz cuadrada
*/

/*	Variante
	
	int n, i;
	int divisores;
	
	for (n=2;n<=100;n++){
		divisores=0;
		for (i=2;i<=n;i++){
			if (n%i==0)
				divisores++;
		}
		if (divisores<2)
			cout<<n<<endl;
	}
*/
