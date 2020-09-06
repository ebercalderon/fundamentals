#include<iostream>
#include<conio.h>
//prototipos
void leermatriz(int, int );
void escribirmatriz(int, int );
void matriztraspuesta(int, int );
int numeros[50][50];
using namespace std;

//programa principal
int main(){
	int c, f;
	cout<<"ingresar numero de filas : ";cin>>f;	
	cout<<"ingresar numero de columnas : ";cin>>c;	
	leermatriz(f,c);
	escribirmatriz(f,c);
	matriztraspuesta(f,c);
	
	getch();
	return 0;
}

//subprogramas
void leermatriz(int f, int c){
	for(int i=0;i<f;i++){
		for(int j=0;j<c;j++){
			cout<<"Digite un numero ["<<i<<"]["<<j<<"]: ";
			cin>>numeros[i][j];
		}
	}
}

void escribirmatriz(int f, int c){	
	cout<<"\nMatriz Original\n";
	for(int i=0;i<f;i++){
		for(int j=0;j<c;j++){
			cout<<numeros[i][j]<<" ";
		}
		cout<<"\n";
	}
	
}
		
void matriztraspuesta(int f, int c){	
	cout<<"\nMatriz Transpuesta\n";
	for(int i=0;i<c;i++){
		for(int j=0;j<f;j++){
			cout<<numeros[j][i]<<" ";
		}
		cout<<"\n";
	}
}

