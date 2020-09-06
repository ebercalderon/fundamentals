#include<iostream>
#include<conio.h>
using namespace std;
//prototipos
void leerarreglo (int []);
void comparar(int [],int []);
int n;
int cont;
int arreglo1[30], arreglo2[30];
int main(){
	cout<<"Ingresar numero de elementos del arreglo: ";cin>>n;
	int arreglo1[n], arreglo2[n];
	cont= 0;	
	cout<<"\nIngresar datos de primer arreglo"<<endl;leerarreglo(arreglo1);
	cout<<"\nIngresar datos de segundo arreglo"<<endl;leerarreglo(arreglo2);
	comparar(arreglo1,arreglo2);
	getch();
	return 0;
}
//subprogramas
void leerarreglo(int arreglo[]){
	for(int i=0;i<n;i++){
		cout<<"\nDigite el numero que va a ingresar en la posicion "<<"["<<i<<"]"<<" de este arreglo"<<": ";
		cin>>arreglo[i];
	}
}
	
	
	
void comparar(int vect1[],int vect2[]){
	for (int i=0;i<n;i++){
		if(vect1[i]==vect2[i]){
		cont++;
		}
	}
	if (cont == n){
		cout<<"\n\t\t\t======LOS DOS ARREGLOS SON IGUALES=======";
	}
	else{
		cout<<"\n\t\t\t======LOS DOS ARREGLOS SON DIFERENTES=======";
		}
}
