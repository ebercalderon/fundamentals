#include<iostream>
#define N 6
using namespace std;

int main(){
	int A[N]={7,3,4,1,0,5};
	int aux;
	for(int i=0;i<N;i++)
		cout<<A[i]<<" ";
	
	for(int i=0;i<N;i++)
		for(int j=0;j<=N-2-i;j++)
			if(A[j]>A[j+1]){
				aux=A[j];
				A[j]=A[j+1];
				A[j+1]=aux;
			}
	cout<<endl;		
	for(int i=0;i<N;i++)
		cout<<A[i]<<" ";
}
