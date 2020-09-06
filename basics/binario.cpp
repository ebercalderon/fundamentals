#include <iostream>
using namespace std;
int main()
{
	int num, D, r, d = 2; //D:dividendo, d:divisor,r:resto
	string binario = "";

	do{
		cout<<"Ingrese un numero decimal positivo a convertir a sistemas binario: ";
		cin>>num;
		system("cls");
	}while(num<0);
	
	D=num;
	
	while(D>=d)
		{ 
		r=D%d;
		
		if(r==1)
			binario="1"+binario; 
		else
			binario="0"+binario;
		
		D=D/d;
		}
	
	if(D==1)
		binario="1"+binario;
	else
		binario="0"+binario;
	
	cout<<"Numero decimal: "<<num<<endl;
	cout<<"Numero binario: "<<binario;
	
	return 0;
}


