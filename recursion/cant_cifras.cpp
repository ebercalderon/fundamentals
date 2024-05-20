#include <iostream>
using namespace std;

int cifras(int numero);

int main(){
	int num;
	cout<<"Ingrese numero a evaluar: ";
	cin>>num;
    cout<<"Cantidad de cifras: "<<cifras(num);
    
	return 0;  
	}

int cifras(int numero){
	
	if (numero<10)
		return 1;
	else
		return 1+cifras(numero/10);	
		
}