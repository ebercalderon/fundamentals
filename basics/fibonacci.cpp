#include <iostream>
using namespace std;
int main(){
	int v1=0, v2=1,v3, n;
	
	do{
	system("cls");
	cout<<"Ingrese la cantidad de numeros de la serie: ";
	cin>>n;
	if(n<=0){
		cout<<"****Ingrese un dato correcto****\n";
		system("pause");
	}
	}while(n<=0);
	
	if(n==1)
		cout<<v1;
	else
		cout<<v1<<", "<<v2;
	
	for(int i=1;i<=n-2;i++)
	{
		v3=v1+v2;
		cout<<", "<<v3;
		v1=v2;
		v2=v3;
	}
	
	return 0;
}
