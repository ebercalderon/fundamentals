#include <iostream>
using namespace std;
int main()
{
	int num;
	int acum=0;
	cout<<"Ingrese un numero a evaluar: ";
	cin>>num;
	
	while(num>=1)
	{
		acum=acum*10+num%10;
		num=num/10;
	}
	cout<<"El numero inverso es: "<<acum;	
}
