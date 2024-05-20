#include <iostream>
#include "pila.h"
using namespace std;
int main()
{
      pila stack;
      int x, i;
      cout<<"Apilando datos:"<<endl;
      for(i=1;i<=5;i++)
      {
        cout<<"Ingrese un dato: ";
        cin>>x;
        stack.apilar(x);
        stack.imprimir();
      }
      cout<<endl<<"Desapilando datos"<<endl;
    
        x=stack.desapilar();
        cout<<"Dato desapilado: "<<x<<endl;
        stack.imprimir();
    
    
}
