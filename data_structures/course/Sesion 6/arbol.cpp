#include<iostream>
#include "arbol.h"
using namespace std;
int main(){
	arbol abb;
	int x;
	abb.insertar(5);
	abb.insertar(3);
	abb.insertar(4);
	abb.insertar(1);
	abb.imprimir(abb.getRaiz());
	cout<<endl<<"Ingrese el nodo a buscar"<<endl;
	cin>>x;
	if(abb.buscar(x)==NULL)
		cout<<"No está en el árbol"<<endl;
	else
		cout<<"Si está en el árbol"<<endl;
	
}
