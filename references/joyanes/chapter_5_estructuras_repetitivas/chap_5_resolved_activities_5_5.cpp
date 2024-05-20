/*	Actividades resueltas 5.5
	Dados dos números enteros, realizar el algoritmo que calcule su cociente y su resto.	*/

#include <iostream>
using namespace std;
int main(){
	int dividendo, divisor;
	int r, q, d;
	
	do{
	cout << "Digite un numero: ";
	cin >> dividendo;
	cout << "Digite otro numero: ";
	cin >> divisor;
	system("cls");
	}while(dividendo<divisor || dividendo<divisor*(-1) );
	
	r=dividendo;
	d=divisor;
	q=0;
	
	if ( divisor==0){
		cout << "Indeterminado";
	}else{ 
		
		if ( divisor < 0 )
			d=d*(-1);
		
		if (dividendo < 0)
			r=r*(-1);
		
		do{
			r = r - d;
			if ( (divisor<0 && dividendo<0) || (divisor>0 && dividendo>0))
				q++;
			else
				q--;		
		}while(r>=d);
		
		if ( q<0 )
			r=r*(-1);
	
		cout << "Dividendo: " << dividendo <<endl
			 << "Divisor: " << divisor <<endl	
		 	 << "Cociente: " << q <<endl
		 	 << "Residuo: "<< r;
	}

	return 0;
}
