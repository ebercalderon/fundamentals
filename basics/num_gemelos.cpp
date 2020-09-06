#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int num;
	int contador=0;
	int op=1;
	
	do{
		cout<<"Digite un numero a evaluar: ";
		cin>>num;
		
		//HALLANDO NUMERO DE CIFRAS
		int residuo=0,cifras=0;
		for(int i=10;residuo!=num;i*=10)
		{
			residuo=num%i;
			if(num>0)
			cifras++;
		}
		
		//COMPROBANDO SI ES GEMELO
		if(cifras>1)
		{
			if(cifras%2==0)
			{
				int potencia=pow(10,(cifras/2));
				if(num/potencia==num%potencia)
					contador++;
			}
			else
			{
				int potencia1=pow(10,((cifras+1)/2));
				int potencia2=pow(10,((cifras-1)/2));
				if(num/potencia1==num%potencia2)
					contador++;
			
			}
		}
		cout<<"¿Continuar ingresando numeros? si(1) / no(0): ";
		cin>>op;
		cout<<endl;

	}while(op==1);
	
	cout<<"Ha ingresado "<<contador<<" numeros gemelos";
	
	return 0;

}

