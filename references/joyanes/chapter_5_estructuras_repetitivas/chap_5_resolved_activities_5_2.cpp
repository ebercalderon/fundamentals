/*	Actividades resueltas 5.2
	Imprimir las treinta primeras potencias de 4, es decir, 4 elevado a 1, 4 elevado a 2, etc.	*/

#include <iostream>
#include <math.h>
using namespace std;
int main(){
	
	for ( int n=1; n<=30; n++)
		cout << pow (4,n) << endl;
	
}

