#include<iostream>
#define N 12
using namespace std;

int main(){
	int A[N]={1,3,5,7,9,11,13,15,17,19,21,23};
	int izq, der, medio,nrobuscado;
	izq=0;
	der=N-1;
	nrobuscado=10;
	while(izq<=der){
	   medio= (izq+der)/2;	
		if(A[medio]==nrobuscado){
				cout<<"Lo encontró"<<endl;
				break;		
		}		
		if(A[medio]<nrobuscado)
			izq=medio+1;
		if(A[medio]>nrobuscado)
			der=medio-1;
	}

}
	
