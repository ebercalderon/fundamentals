/*	Ejemplo 6.8		(de Procedimiento)
	Algoritmo que transforma un número introducido por teclado en 
	notación decimal a romana. El número será entero y positivo y 
	no excederá de 3.000	*/
	
#include <iostream>
using namespace std;

char romanos (int digito, char v1, char v2, char v3);

int main(){
	float n;
	int r, digito;
	char rpta;
	
	do{
		do{
			system ("cls");
			cout << "Digite un numero: ";
			cin >> n;
		}while (n<0 || n>3000 || n!=int(n));
		
		r = int(n);
		digito = r/1000;
		r = r%1000;
		romanos (digito, 'M', ' ', ' ');
		digito = r/100;
		r = r%100;
		romanos (digito, 'C', 'D', 'M');
		digito = r/10;
		r = r%10;
		romanos (digito, 'X', 'L', 'C');
		digito = r;
		romanos (digito, 'I', 'V', 'X');
		
		cout << "\nOtra conversion? (Y/N): ";
		cin >> rpta;
	}while (rpta != 'N' && rpta != 'n');
	
	return 0;
}

char romanos (int digito, char v1, char v2, char v3){
	int j;
	
	if (digito == 9)
		cout << v1 << v3;
	else{
		if (digito > 4){
			cout << v2;
			for (j=1; j<=digito-5; j++){
				cout << v1;
			}
		}
		else{
			if (digito == 4)
				cout << v1 << v2;
			else{
				for (j=1; j<=digito; j++){
					cout << v1;
				}
			}
		}
	}
}		
