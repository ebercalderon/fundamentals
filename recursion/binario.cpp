#include <iostream>
using namespace std;

long binario(long n);

int main(){
	long num;
	do{
		cout<<"Ingrese un numero positivo a convertir: ";
		cin>>num;
	}while(num<0);

	cout<<"Numero en binario: "<<binario(num);
 
 return 0;
}

long binario(long n){
	if(n< 2)
		return n;
	else
		return n%2 + 10*binario(n/2);
}
