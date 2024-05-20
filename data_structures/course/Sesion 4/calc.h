#include<iostream>
using namespace std;
struct nodo{
	int dato;
	nodo *sig;
};
typedef nodo *ppila;
class pila{
	private:
		ppila pcima;
	public:
		pila();
		~pila();
		void apilar(int);
		int desapilar();
		void imprimir();
};
pila::pila(){
	pcima=NULL;
}
pila::~pila(){
	ppila p;
	p=pcima;
	while(p!=NULL){
		p=p->sig;
		delete pcima;
		pcima=p;
	}

}
void pila::apilar(int x){
	ppila p;
	p=new nodo;
	p->dato=x;
	p->sig=pcima;
	pcima=p;

}
int pila::desapilar(){
	int x;
	ppila p;
	p=pcima;
	if(p!=NULL){
		x=p->dato;
		pcima=p->sig;
		delete p;
		return x;
	}
	return -1;
}
void pila::imprimir(){
	ppila p;
	p=pcima;
	while(p!=NULL){
		cout<<p->dato<<endl;	
		p=p->sig;
	}
	
}

