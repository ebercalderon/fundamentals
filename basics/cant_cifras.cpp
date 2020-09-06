#include <iostream>
using namespace std;
int main()
{
	int num;
	int cont=0;
	
	cout<<"Ingrese un numero a evaluar: ";
	cin>>num;
	
	while(num>=1)
	{
		num=num/10;
		cont++;
	}
	cout<<"El numero tiene: "<<cont<<" cifras";
	
}

