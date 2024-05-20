#include <iostream>
#include "cola.h"
using namespace std;
int main()
{
	cola c;
	int x,i;
	cout<<"Encolando elementos: " <<endl<<endl;
	for(i=1;i<=5;i++)
	{
		cout<<"Ingrese un dato : ";
		cin>>x;
		c.encolar(x);
		c.imprimir();
	}
	cout<<endl<<"Desencolando elementos: "<<endl;
	while ( !c.estavacia())
	{
		x = c.desencolar();
		cout<<"Dato desencolado: "<<x<<endl;
		c.imprimir();
	}

}
