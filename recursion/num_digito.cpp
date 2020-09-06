#include <iostream>
using namespace std;

//Prototipo
int digito(int,int);

//Principal
int main()
{
	int n,k;
	cout<<"PROGRAMA PARA HALLAR DIGITO DE UN NUMERO"<<endl;
	cout<<"========================================"<<endl;
	cout<<"Digite el numero:";cin>>n;
	cout<<"Digite el orden del digito (de derecha a izquierda): ";cin>>k;
	cout<<"El digito es: "<<digito(n,k);
	
	return 0;
}

//Funciones
int digito(int n,int k)
{
	if(k==1)
		return n%10;
	else
		return digito(n/10,k-1);
}
