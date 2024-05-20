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

pnodo buscar(int x){
pnodo p;
if ( pL == NULL )
	return NULL;
else
{
	p = pL;
	while ( p != NULL && (*p).dato != x )
		p = (*p).sig;
	return p;
}
}

pnodo buscaranterior(int x){
pnodo a,p;
a = NULL;
p = pL;
while ((*p).dato != x){
	a = p;
	p = (*p).sig;}
return a;
}

void eliminar(int x){
	pnodo a,p;
	p=buscar(x);
	if ( p == NULL )
		cout<<"El elemento no esta en la lista";
	else{
		a = buscaranterior(x);
		if ( a == NULL )
			pL = (*p).sig;
		else
			(*a).sig = (*p).sig;	
		delete p;}
}


int main(){
	pL=NULL;

	insertar(4);
	insertar(3);
	insertar(1);
	
	imprimir();
}



