/*	Ejercicio 5.11
	Calcular el enésimo término de la serie de Fibonacci.	*/

#include <iostream>
using namespace std;
int main(){
	double v1=0, v2=1, v3, n;
	
	do{
	system("cls");
	cout<<"Ingrese la cantidad de numeros de la serie: ";
	cin>>n;
	}while( n<=0 || n!=int(n) );
	
	cout <<"Serie Fibonacci: ";
	if (n==1)
		cout << v1;
	else
		cout << v1 << ", " << v2;
	
	for(int i=1;i<=n-2;i++)
	{
		v3=v1+v2;
		cout<<", "<<v3;
		v1=v2;
		v2=v3;
	}
	
	cout << "\nTermino " << n << ": " <<v3;
	return 0;
}
