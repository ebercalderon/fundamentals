#include<iostream>
#include "grafo.h"
using namespace std;

int main(){
	grafo g;
	int x,y;
	g.insertarVertice(1);
	g.insertarVertice(2);
	g.insertarVertice(3);
	g.insertarArista(1,2);
	g.insertarArista(1,3);
	g.insertarArista(3,2);
	cout<<"Vert|Aristas"<<endl;
	g.imprimirGrafo();
}
