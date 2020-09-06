#include <iostream>
using namespace std;
int main()
{
	int num;
	int i;
	bool p=true;

	do{
		cout<<"Ingrese un numero a evaluar: ";
		cin>>num;
		system("cls");
	}while(num<=1);
	
	for(i=2;i<num-1&&p==true;i++){
		if(num%i==0){
			p=false;
			}
	}
			
	if(p==true)
		cout<<num<<" es primo";
	else
		cout<<num<<" no es primo";
				
}
