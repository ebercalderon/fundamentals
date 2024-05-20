#include<iostream>
#define N 6
using namespace std;

int main(){
	int A[N]={7,3,4,1,0,5};
	int x=1;
	int j=0;
	int pos=0;
	for(int i=0;i<N;i++)
		cout<<A[i]<<" ";
	while(j<N){
		if(A[j]==x){
			pos=j+1;
			cout<<"\nLo encontro en la posicion "<<pos<<endl;
			break;
		}
		if(A[j]!=x){
			cout<<"\nNo lo encontro"<<endl;
			break;
		}
		j++;
	}
}



