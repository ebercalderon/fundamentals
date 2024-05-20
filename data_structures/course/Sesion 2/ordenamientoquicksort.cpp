#include<iostream>
#define N 10
using namespace std;

//función de ordenamiento con Quicksort
void quicksort(int a[],int primero, int ultimo){
	int c,i,j,aux,pivote;
	i=primero;
	j=ultimo;
	c=(primero+ultimo)/2;
	pivote=a[c];
	do{
		while(a[i]<pivote) i++;
		while(a[j]>pivote) j--;
		if(i<=j){
			aux=a[i];
			a[i]=a[j];
			a[j]=aux;
			i++;
			j--;
		}		
	}while(i<=j);
	
	if(primero<j)
		quicksort(a,primero,j);
	if(i<ultimo)
		quicksort(a,i,ultimo);	
	
}

//función principal o de ejecución
int main(){
		int A[N]={7,3,4,1,0,5,-1,7,9,2};
		for(int i=0;i<N;i++)
		cout<<A[i]<<" ";
		quicksort(A,0,N-1);
		cout<<endl;		
		for(int i=0;i<N;i++)
		cout<<A[i]<<" ";
}
