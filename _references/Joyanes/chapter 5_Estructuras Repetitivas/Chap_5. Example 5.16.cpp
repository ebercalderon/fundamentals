/*	Ejemplo 5.16
	Se conoce la población de cada una de las veinticinco ciudades más grandes de las ocho provincias de 
	Andalucía y se desea identificar y visualizar la población de la ciudad más grande de cada provincia.	*/

#include <iostream>
using namespace std;
int main(){
	int i, j, n;	//contador de provincias(i) y ciudades(j)
	int mayor, ciudad;	//ciudad de mayor población - población de la ciudad
	
	i=1;
	
	while (i<=8){
		mayor=0;
		j=1, n=1;
		while (j<=25){
			cout<<"Ingrese la poblacion de la ciudad ["<<n<<"]:";
			cin>>ciudad;
			if (ciudad > mayor)
				mayor=ciudad;
			
			j++;
			n++;
		}
		cout<<"La ciudad mayor es: "<<mayor<<endl;
		i++;
	}
	return 0;
}

/*	Solución
	El problema consistirá, en primer lugar, en la obtención de la población mayor de cada provincia y realizar 
	esta operación ocho veces, una para cada provincia.	
		1. Encontrar y visualizar la ciudad mayor de una provincia.
		2. Repetir el paso 1 para cada una de las ocho provincias andaluzas.
	El procedimiento para deducir la ciudad más grande de entre las veinticinco de una provincia se consigue creando 
	una variable auxiliar MAYOR —inicialmente de valor 0— que se va comparando sucesivamente con los veinticinco 
	valores de cada ciudad, de modo tal que, según el resultado de comparación, se intercambian valores de la ciudad
	por el de la variable MAYOR
*/
