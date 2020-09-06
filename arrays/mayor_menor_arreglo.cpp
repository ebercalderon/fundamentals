#include<iostream>
#include<conio.h>
using namespace std;
//prototipos
int elementomayor(int[],int);
int elementomenor(int[],int);
int suma(int[],int);
//principal
int main(){
	int n;
	cout<<"Ingresar numero de elementos del arreglos: ";cin>>n;
	int numeros[n];
	for (int i=0;i<n;i++){
		cout<<"\nDigite el numero que va a ingresar en la posicion "<<"["<<i<<"]"<<": ";
		cin>>numeros[i];
	}
	cout<<"\nEl elemento mayor del arreglo es: "<<elementomayor(numeros,n);
	cout<<"\n\nEl elemento menor del arreglo es: "<<elementomenor(numeros,n);
	cout<<"\n\nLa suma de los elementos del arreglo es: "<<suma(numeros,n);
	getch();
	return 0;
}
//subprogramas

int elementomayor(int arreglo[],int n)
{
	int mayor=arreglo[0];
	for(int i=1;i<n;i++)
	{
		if(mayor<arreglo[i])
		{
			mayor=arreglo[i];
		}
	}
	return mayor;
}
int elementomenor(int arreglo[],int n)
{
	int menor=arreglo[0];
	for(int i=1;i<n;i++)
	{
		if(menor>arreglo[i])
		{
			menor=arreglo[i];
		}
	}
	return menor;
}  
int suma(int arreglo[],int n){
	int suma = 0;
	for (int i=0;i<n;i++){
		suma+=arreglo[i];
	}
	return suma;
}
