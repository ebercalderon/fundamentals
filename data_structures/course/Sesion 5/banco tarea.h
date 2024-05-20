#include<iostream>
using namespace std;
struct nodo{
   	char dato;
	nodo *sig;
};
typedef nodo *pcola;
class cola{
	private:
		pcola pfrente, pfinal;
	public:
		cola();
		~cola();
		void encolar(char);
		void desencolar();
		void imprimir();
		bool vacia();
};
cola::cola(){
	pfrente=NULL;
	pfinal=NULL;
}
bool cola::vacia(){
	if(pfrente==NULL)	
		return true;
	else
		return false;
}
void cola::encolar(char c){
	pcola p;
	p=new nodo;
	p->dato=c;
	p->sig=NULL;
	if(pfrente==NULL)
		pfrente=p;
	else
		pfinal->sig=p;
	pfinal=p;
}
void cola::desencolar(){
	pcola p;
	p=pfrente;
	if(p!=NULL){
		pfrente=p->sig;
		delete p;
		if(pfrente==NULL)
			pfinal=NULL;
	}
	
}
void cola::imprimir(){
	pcola p;
	p=pfrente;
	if(p==NULL)
		cout<<"cola vacia"<<endl;
	else
		do{
			cout<<p->dato<<"->";
			p=p->sig;		
		}while(p!=NULL);
}
cola::~cola(){
	pcola p,q;
	p=pfrente;
	while(p!=NULL){
		q=p;
		p=p->sig;
		delete q;
	}
}





