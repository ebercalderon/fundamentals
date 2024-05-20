#include<iostream>
using namespace std;
int main(){
	int x=5;
	int *p; //declarando una variable tipo puntero.
	p=&x;  //p apunta a x
	cout<<p<<endl;//imprime el contenido de p que es la dirección de memoria de x.	
	cout<<*p<<endl;//mostrando el valor de la variable apuntada por p
	*p=100;//modificando el valor de la variable apuntada por p
	cout<<x<<endl;
	cout<<&p<<endl; //mostrando la dirección de memoria de p
}
