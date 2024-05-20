// simule el funcionamiento de la calculadora
// pasamos 23+
// debe salir 5
#include<iostream>
#include "calc.h"

using namespace std;
int main(){
	int x,y;
	pila p;
	char cadena[20];
	cout<<"Ingrese la cadena en postfijo"<<endl;
	fgets(cadena,20,stdin);
	for(int i=0;cadena[i]!='\0';i++){
		if(cadena[i]>=48&&cadena[i]<=57)//determinar si es un nro con codigo ascii
			p.apilar(cadena[i]-48);	
		else if(cadena[i]=='+'){
			x=p.desapilar();
			y=p.desapilar();
			p.apilar(x+y);
		}
		else if(cadena[i]=='-'){
			x=p.desapilar();
			y=p.desapilar();
			p.apilar(y-x);
		}
		else if(cadena[i]=='*'){
			x=p.desapilar();
			y=p.desapilar();
			p.apilar(x*y);
		}
		else if(cadena[i]=='/'){
			x=p.desapilar();
			y=p.desapilar();
			p.apilar((x*10)/(y*10));
		}	
	}
	p.imprimir();
}

