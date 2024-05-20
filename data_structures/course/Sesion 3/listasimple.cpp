#include<iostream>
using namespace std;

struct nodo{
	int dato;
	nodo *sig;
};
typedef nodo *pnodo;
pnodo pL;
void insertar(int x){
	pnodo p;
	p=new nodo;// pedir espacio de memoria para un nodo
	p->dato=x;
	p->sig=pL;
	pL=p;
}
void imprimir(){
	pnodo p;
	p=pL;
	cout<<"pL-> ";
	while(p!=NULL){
		cout<<p->dato<<"-> ";
		p=p->sig;
	}
	cout<<"NULL"<<endl;
}

int main(){
	pL=NULL;

	insertar(4);
	insertar(3);
	insertar(1);
	
	imprimir();
}



