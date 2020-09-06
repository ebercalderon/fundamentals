#include <iostream>
#include <stdlib.h> // exit
#include <fstream>
//#include <string.h>

using namespace std;

int menu();
void procesos();
void crear();
void escribir();
void leer();

int main(){
    procesos();
    return 0;
}

int menu()
{
	system("cls");
    int opcion;
    cout<<"\n\t\t\t=========================="
		<<"\n\t\t\t....:::: FICHEROS ::::...."
    	<<"\n\t\t\t==========================\n\n"
    	<<"\n\t\t\t[1] Crear registros"
    	<<"\n\t\t\t[2] Escribir en fichero"
    	<<"\n\t\t\t[3] Leer fichero"
    	<<"\n\n\n\t\t\t\t\t|| [4] Salir ||\n\n";
    do{
		cout<<"\n\t\t\tDigite opcion [ ]\b\b";
		cin>>opcion;
    }while(opcion < 1 || opcion > 4);
    
    return opcion;
}

void procesos()
{
	int opcion;
	do
	{	
		system("COLOR F0");	
		opcion = menu();
		switch (opcion)
		{
			case 1: crear(); break;	
			case 2:	escribir(); break;
			case 3: leer(); break;
			case 4:	break;
		}
        system("pause");
	}while (opcion != 4);
}

void crear(){
    ofstream archivo;
    string _name;
    //cout<<"\nDigite el nombre del archivo: ";
    //fflush(stdin);
    //getline(cin,_name);
    //archivo.open(_name.c_str(),ios::out);  
    archivo.open("fichero.txt",ios::out);   // out:Operaciones de escritura

    if (archivo.fail()){
        cout<<"No se puede abrir el archivo";
        exit(1);
    }
    //archivo<<"Hello";
    archivo.close();
}

void escribir(){
    ofstream archivo;

    archivo.open("fichero.txt",ios::app);   // Operaciones de añadidura

    if (archivo.fail()){
        cout<<"No se puede abrir el archivo";
        exit(1);
    }

    archivo<<"\nHello";

    archivo.close();
}

void leer(){
    string texto;
    ifstream archivo;
    
    archivo.open("fichero.txt",ios::in);   // Operaciones de lectura

    if (archivo.fail()){
        cout<<"No se puede abrir el archivo";
        exit(1);
    }

    while(!archivo.eof()){  // Mientras no sea el final del archivo
        getline(archivo,texto);
        cout<<texto<<endl;
    }

    archivo.close();
}


/*
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<conio.h>

using namespace std;

int main(){
 ifstream archivo;
 string nombre_archivo, texto;
 
 cout << "Ingrese nombre o direccion del archivo a leer: ";
 getline(cin,nombre_archivo);
 nombre_archivo += ".txt";
 
 archivo.open(nombre_archivo.c_str(),ios::in);
 
 if(archivo.fail()){
  cout << "No se ha podido abrir el archivo";
  exit(1);
 }
 
 while(!archivo.eof()){
  getline(archivo,texto);
  cout << texto << endl;
  cout << texto << endl;
 }

 archivo.close();

 getch();
 return 0;
}
*/