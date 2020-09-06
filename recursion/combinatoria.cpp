#include <iostream>
using namespace std;

int comb(int n,int k){
	if(k==0 || n==k){
		return 1;
	}
	else{
		return comb(n-1,k-1)+comb(n-1,k);
	}
	
}
int main(){
	int m, n;
	cout<<"Ingrese valor de m: ";cin>>m;
	cout<<"Ingrese valor de n: ";cin>>n;
	cout<<"Resultado: "<<comb(m,n);
	return 0;
}
