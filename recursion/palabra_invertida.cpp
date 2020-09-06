#include<iostream>
#include<string.h>
using namespace std;

void inversa(string,int);

int main()
{
	string cadena;
	cout<<"Digite una palabra: ";cin>>cadena;
	int longitud;
	longitud=cadena.length();
	
	cout<<"Su palabra invertida es: ";
	inversa(cadena,longitud);
	
	return 0;
}

void inversa(string cadena,int longitud)
{
	if(longitud==1)
	{
		cout<<cadena[0];
	}
	else
	{
		cout<<cadena[longitud-1];
		inversa(cadena,longitud-1);
	}
}
