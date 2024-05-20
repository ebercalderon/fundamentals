#include<iostream>
using namespace std;

struct nodo{
	int dato;
	nodo *hizq;
	nodo *hder;
};
typedef nodo *pnodo;

class arbol{
	private:
		pnodo praiz;
	public:
		arbol();
		~arbol();
		void insertar(int );
		void imprimir(pnodo);
		pnodo getRaiz();
		void eliminaarbol(pnodo);
		pnodo buscar(int);
};

arbol::arbol(){
	praiz=NULL;
}
void arbol::eliminaarbol(pnodo p){
	if(p!=NULL){
		eliminaarbol(p->hizq);
		eliminaarbol(p->hder);
		delete p;
	}
}
arbol::~arbol(){
	eliminaarbol(praiz);
}
pnodo arbol::getRaiz(){
	return praiz;
}
void arbol::insertar(int x){
	pnodo p,r,padrer;
	char c;
	p=new nodo;
	p->dato=x;
	p->hizq=NULL;
	p->hder=NULL;
	if(praiz==NULL)
		praiz=p;
	else{
		r=praiz;
		while(r!=NULL){
			padrer=r;
			if(x<r->dato){
				r=r->hizq;
				c='i';
			}				
			else{
				r=r->hder;
				c='d';
			}
		}
		//enlazar con el dato
		if(c=='i')
			padrer->hizq=p;
		else
			padrer->hder=p;
	}

}
void arbol::imprimir(pnodo p){
	if(p!=NULL){
		imprimir(p->hizq);
		cout<<p->dato<<" ";
		imprimir(p->hder);
	}
}
pnodo arbol::buscar(int x){
	pnodo p;
	p=praiz;
	while(p!=NULL){
		if(p->dato==x)
			return p;
		else if(x<p->dato)
			p=p->hizq;
		else
			p=p->hder;
	}
	return p;
}


