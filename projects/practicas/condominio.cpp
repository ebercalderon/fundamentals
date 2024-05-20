#include <iostream>
#include <fstream>	// archivos
#include <stdio.h>
#include <stdlib.h> // exit
#include <iomanip>	//setw
#include <string.h>	//strcmp
using namespace std;

// ESTRUCTURAS ///////////////////////////////////////////////////////////
struct fecha{
	int dia;
	int mes;
	int anio;
};

struct filial{
	char ID[9];
	char nombres[20];
	float monto;
	char situacion[11];
};

// PROTOTIPOS ///////////////////////////////////////////////////////////
int menu();
void procesos(filial _filial, fecha calendario);

void crear_filial();
void crear_realizado();
void crear_pendientes();
void crear_morosos();
void ingresar_filial(filial _filial);
bool consulta_duplicado(filial _filial, char aux[9]);
bool consulta_filial(filial _filial, char aux[9]);
void generar_cobro(filial _filial, fecha calendario);
void realizar_cobro(filial _filial, fecha calendario, char aux[9]);
void ingresar_realizado(filial _filial, fecha calendario);
void eliminar_realizado(filial _filial, char aux[9]);
void proceso_mostrar(filial _filial, fecha calendario);
void mostrar_realizado(filial _filial, fecha calendario);
void ingresar_moroso(filial _filial);
void mostrar_moroso(filial _filial);
bool FechaValida(int YY, int MM, int DD);
void mostrar_filial(filial _filial);

void mensaje_salida();	// Mensajes

// MAIN ///////////////////////////////////////////////////////////
int main()
{	
	filial _filial;
	fecha calendario;

	// Llamada al proceso
	procesos(_filial, calendario);
    return 0;
}

// MENU PRINCIPAL ///////////////////////////////////////////////////////////
int menu()
{
	system("cls");
    int opcion;
    cout<<"\n\t\t\t========================================"
		<<"\n\t\t\t....:::: SISTEMA DE CONDOMINIOS ::::...."
    	<<"\n\t\t\t========================================\n\n"
    	<<"\n\t\t\t[1] Crear registro"
    	<<"\n\t\t\t[2] Ingresar filial"
		<<"\n\t\t\t[3] Generar cobros mensuales"
    	<<"\n\t\t\t[4] Registrar cobro"
		<<"\n\t\t\t[5] Consultar filial"
		<<"\n\t\t\t[6] Mostrar pagos"
    	<<"\n\n\n\t\t\t\t\t\t|| [7] Salir ||\n\n";
    do{
		cout<<"\n\t\t\tDigite opcion [ ]\b\b";
		cin>>opcion;
    }while(opcion < 1 || opcion > 7);
    
    return opcion;
}

void procesos(filial _filial, fecha calendario)
{
	int opcion;
	do
	{	
		//system("COLOR F0"); 
		char aux[9];
		opcion = menu();
		switch (opcion)
		{
			case 1: 
					crear_filial(); 
					crear_realizado();
					crear_morosos();
					crear_pendientes();
					cout<<"\n\t\t\t....:::Creaciones exitosas:::....\n\n";
					break;	
			case 2:	ingresar_filial(_filial); break;
			case 3: generar_cobro(_filial, calendario); break; 
			case 4: 
					cout<<"\n\t\t\tIngrese ID: "; 
					fflush(stdin);
					cin.getline(aux,9,'\n');
					realizar_cobro(_filial, calendario, aux); 
					break;
			case 5:	
					cout<<"\n\t\t\tIngrese ID: "; 
					fflush(stdin);
					cin.getline(aux,9,'\n');
					consulta_filial(_filial, aux); 
					break;
			case 6: proceso_mostrar(_filial, calendario); break;
			case 7:	mensaje_salida(); break;
		}
		if(opcion != 6)
			system("pause");
	}while (opcion != 7);
}

// Creacion de registro
void crear_filial()
{	
	ofstream archivo;
	archivo.open("filial.txt",ios::out);   // out:Operaciones de escritura
	
	if (archivo.fail()){
        
		system("pause");
		exit(1);
	}
    
	//cout<<"\n\t\t\t....:::Creacion exitosa:Filial:::....\n\n";
    archivo.close();	// Cerrrar archivo
}

void crear_realizado()
{	
	ofstream archivo;
	archivo.open("realizado.txt",ios::out);   // out:Operaciones de escritura
	
	if (archivo.fail()){
        cout<<"\n\t\t\t~~~~ No se pudo crear el archivo ~~~~\n";
		system("pause");
		exit(1);
	}
    
	//cout<<"\n\t\t\t....:::Creacion exitosa:Realizados:::....\n\n";
    archivo.close();	// Cerrrar archivo
}

void crear_pendientes()
{	
	ofstream archivo;
	archivo.open("pendientes.txt",ios::out);   // out:Operaciones de escritura
	
	if (archivo.fail()){
        cout<<"\n\t\t\t~~~~ No se pudo crear el archivo ~~~~\n";
		system("pause");
		exit(1);
	}
    
	//cout<<"\n\t\t\t....:::Creacion exitosa:Pendientes:::....\n\n";
    archivo.close();	// Cerrrar archivo
}

void crear_morosos()
{	
	ofstream archivo;
	archivo.open("morosos.txt",ios::out);   // out:Operaciones de escritura
	
	if (archivo.fail()){
        cout<<"\n\t\t\t~~~~ No se pudo crear el archivo ~~~~\n";
		system("pause");
		exit(1);
	}
    
	//cout<<"\n\t\t\t....:::Creacion exitosa:Morosos:::....\n\n";
    archivo.close();	// Cerrrar archivo
}
// Ingreso de datos de filial
void ingresar_filial(filial _filial)
{
	system("cls");
	ofstream archivo;
	bool temp=true;
	char aux[9];

	cout<<"\n\t\tINGRESO DE DATOS DE FILIAL"
		<<"\n\t==========================================="
		<<"\n\tA continuacion complete los siguientes datos:\n";
	fflush(stdin);
	cout<<"\n\tIngrese el numero de filial: "; cin.getline(_filial.ID,9,'\n');
	
	temp=consulta_duplicado(_filial, _filial.ID);

	if (temp)
	{
		cout<<"\n\tNombres : "; cin.getline(_filial.nombres,20,'\n');
		cout<<"\n\tMonto: "; cin>>_filial.monto;

		archivo.open("filial.txt",ios::app);    // Operaciones de añadidura
		if (archivo.fail()){
			cout<<"\n\t\t\t~~~~ No se pudo crear el archivo ~~~~\n";
			system("pause");
			exit(1);
		}

		archivo<<_filial.ID<<'\t'<<_filial.nombres<<'\t'<<_filial.monto<<'\n';
		archivo.close();
		strcpy(_filial.situacion,"moroso");
		ingresar_moroso(_filial);
		cout<<"\n\t\t....:::Registro exitoso:::....\n\n";
	}
	else
		cout<<"\n\t\t\t~~~~ Filial duplicado ~~~~\n";
	
	 
}

bool consulta_duplicado(filial _filial, char aux[9]){
	ifstream archivo;
	bool temp = true;
	int cont=0;

	archivo.open("filial.txt",ios::in);
	if (archivo.fail()){
        cout<<"\n\t\t\t~~~~ No se pudo crear el archivo ~~~~\n";
		system("pause");
		exit(1);
	}
	archivo>>_filial.ID>>_filial.nombres>>_filial.monto;

	while(!archivo.eof())
    {
		if(strcmp(aux,_filial.ID) == 0)
		{	
			temp=false;
		}
		archivo>>_filial.ID>>_filial.nombres>>_filial.monto;
		cont++;
	}
	archivo.close();

	if (cont == 0)
		temp=true;

	return temp;
}	

bool consulta_filial(filial _filial, char aux[9]){
	system("cls");
	ifstream archivo;
	bool temp = false;

	archivo.open("filial.txt",ios::in);
	if (archivo.fail()){
        cout<<"\n\t\t\t~~~~ No se pudo crear el archivo ~~~~\n";
		system("pause");
		exit(1);
	}
	archivo>>_filial.ID>>_filial.nombres>>_filial.monto;

	while(!archivo.eof())
    {
		if(strcmp(aux,_filial.ID) == 0)
		{	
			temp = true;
			cout<<"\t\t ....::::  ESTADO DE FILIAL  ::::....\n"
				<<"\t\t ====================================\n"
				<<"\n\t\t--------------------------------------"
				<<"\n\t\tFilial ID	: "<<_filial.ID
				<<"\n\t\tNombres		: "<<_filial.nombres
				<<"\n\t\tMonto		: "<<_filial.monto
				<<"\n\t\t--------------------------------------\n";
		}
		archivo>>_filial.ID>>_filial.nombres>>_filial.monto;
	}
	archivo.close();

	if (temp == false)
		cout<<"\n\t\t\t~~~~ Filial no encontrado ~~~~\n";

	return temp;
}	

void ingresar_realizado(filial _filial, fecha calendario)
{
	ofstream archivo;

	archivo.open("realizado.txt",ios::app);    // Operaciones de añadidura

	if (archivo.fail()){
        cout<<"\n\t\t\t~~~~ No se pudo crear el archivo ~~~~\n";
		system("pause");
		exit(1);
	}

	archivo<<_filial.ID<<'\t'<<_filial.nombres<<'\t'<<_filial.monto<<'\t'<<_filial.situacion<<'\t'<<calendario.mes<<'\t'<<calendario.anio<<'\n';
	archivo.close();

	eliminar_realizado(_filial, _filial.ID);

	cout<<"\n\t\t....:::Cobro realizado:::....\n\n";
}

void generar_cobro(filial _filial, fecha calendario)
{
	ifstream archivo;
	ofstream _pendientes;

	cout<<"\n\t\t\tIngrese mes a cobrar: ";
	cin>>calendario.mes;

	archivo.open("filial.txt",ios::in);
	if (archivo.fail()){
        cout<<"\n\t\t\t~~~~ No se pudo crear el archivo ~~~~\n";
		system("pause");
		exit(1);
	}

	_pendientes.open("pendientes.txt",ios::app);    // Operaciones de añadidura
	if (_pendientes.fail()){
        cout<<"\n\t\t\t~~~~ No se pudo crear el archivo ~~~~\n";
		system("pause");
		exit(1);
	}

	while(!archivo.eof())
	{	
		archivo>>_filial.ID>>_filial.nombres>>_filial.monto>>_filial.situacion;
		_pendientes<<_filial.ID<<'\t'<<_filial.nombres<<'\t'<<_filial.monto<<'\t'<<_filial.situacion<<'\t'<<calendario.mes<<'\n';
		
		
	}
	archivo.close();
	_pendientes.close();
	
	archivo.close();
}

void realizar_cobro(filial _filial, fecha calendario, char aux[9]){
	ifstream archivo;
	bool temp, verificacion;
	float _monto;

	temp=consulta_filial(_filial, aux); 
	if(temp)
	{
		cout<<"\n\t\tFecha de pago: \n\n";
		cout<<"\t\tAnio	: "; cin>>calendario.anio;
		cout<<"\t\tMes	: "; cin>>calendario.mes;
		cout<<"\t\tDia	: "; cin>>calendario.dia;
	}

	verificacion=FechaValida(calendario.anio, calendario.mes, calendario.dia);
	if(verificacion)
	{
		archivo.open("pendientes.txt",ios::in);
		if (archivo.fail()){
			cout<<"\n\t\t\t~~~~ No se pudo crear el archivo ~~~~\n";
			system("pause");
			exit(1);
		}
		archivo>>_filial.ID>>_filial.nombres>>_filial.monto>>calendario.mes;
		cout<<"\n\t\tPagos pendientes: \n";
		cout<<"\t\tMes"<<setw(16)<<"Monto\n";
		while(!archivo.eof())
		{
			
			if (strcmp(aux,_filial.ID) == 0)
			{
				if (calendario.dia<10)
					cout<<"\t\t"<<calendario.mes<<setw(16)<<_filial.monto<<"\n";
				else{
					_filial.monto*=1.1;
					cout<<"\t\tMonto a pagar + 10%: "<<_filial.monto<<"\n";
				}

				strcpy(_filial.situacion,"Cumplido");
				
				ingresar_realizado(_filial, calendario);

			}
			archivo>>_filial.ID>>_filial.nombres>>_filial.monto>>calendario.mes;
		}
		archivo.close();
			
	}
	else
		cout<<"\n\t\t\t~~~~ Operacion incorrecta ~~~~\n";
}

// MENU MOSTRAR ///////////////////////////////////////////////////////////
int menu_mostrar()
{
	system("cls");
	int opcion;
    cout<<"\n\t\t\t=============================="
		<<"\n\t\t\t...::: REPORTE DE PAGOS :::..."
    	<<"\n\t\t\t==============================\n"
    	<<"\n\t\t\t[1] Mostrar filiales"
    	<<"\n\t\t\t[2] Mostrar realizados"
		<<"\n\t\t\t[3] Mostrar pendientes"
    	<<"\n\n\n\t\t\t\t\t|| [0] Atras ||\n\n";
    do
	{
		cout<<"\n\t\t\tDigite opcion [ ]\b\b";
		cin>>opcion;
    }while(opcion < 0 || opcion > 3);
    
    return opcion;
}

void proceso_mostrar(filial _filial, fecha calendario)
{
	int opcion;
	do
	{
		opcion = menu_mostrar();
		if (opcion != 0)
		{
			switch (opcion)
			{
				case 1: mostrar_filial(_filial); break;
				case 2: mostrar_realizado(_filial, calendario); break;
				case 3: mostrar_moroso(_filial); break;
			}
			if (opcion!=0)
				system("pause");
		}
	}while (opcion != 0);

}

void mostrar_filial(filial _filial)
{
	system("cls");
	ifstream archivo;
	int cont = 1;

	archivo.open("filial.txt",ios::in);   // Operaciones de lectura
	if (archivo.fail()){
        cout<<"\n\t\t\t~~~~ No se pudo crear el archivo ~~~~\n";
		system("pause");
		exit(1);
	}

	archivo>>_filial.ID>>_filial.nombres>>_filial.monto;

	cout<<"\t"<<setw(52)<<"...:::  REGISTRO DE FILIAL  :::...\n"
		<<"\t"<<setw(52)<<"==================================\n"
		<<"\n\t\tN"<<setw(16)<<"Filial"<<setw(16)<<"Nombres"<<setw(16)<<"Monto"
		<<"\n\t\t--------------------------------------------------\n";

	while(!archivo.eof())
	{
		cout<<"\n\t\t"<<cont
			<<setw(16)<<_filial.ID
			<<setw(16)<<_filial.nombres
			<<setw(16)<<_filial.monto;
	
		archivo>>_filial.ID>>_filial.nombres>>_filial.monto;
		cont++;	
	}
	archivo.close();

	cout<<"\n\t\t--------------------------------------------------\n";
}

void mostrar_realizado(filial _filial, fecha calendario)
{
	system("cls");
	ifstream archivo;
	int cont = 1;

	archivo.open("realizado.txt",ios::in);   // Operaciones de lectura
	if (archivo.fail()){
        cout<<"\n\t\t\t~~~~ No se pudo crear el archivo ~~~~\n";
		system("pause");
		exit(1);
	}

	archivo>>_filial.ID>>_filial.nombres>>_filial.monto>>_filial.situacion>>calendario.mes>>calendario.anio;

	cout<<"\t"<<setw(65)<<"...:::  REGISTRO DE FILIAL REALIZADO  :::...\n"
		<<"\t"<<setw(65)<<"============================================\n"
		<<"\n\tN"<<setw(16)<<"Filial"<<setw(16)<<"Nombres"<<setw(16)<<"Monto"<<setw(16)<<"Pago"<<setw(16)<<"Mes"<<setw(16)<<"Anio"
		<<"\n\t-------------------------------------------------------------------------------------------------\n";

	while(!archivo.eof())
	{
		cout<<"\n\t"<<cont
			<<setw(16)<<_filial.ID
			<<setw(16)<<_filial.nombres
			<<setw(16)<<_filial.monto
			<<setw(16)<<_filial.situacion
			<<setw(16)<<calendario.mes
			<<setw(16)<<calendario.anio;
			
		archivo>>_filial.ID>>_filial.nombres>>_filial.monto>>_filial.situacion>>calendario.mes>>calendario.anio;
		cont++;	
	}
	archivo.close();

	cout<<"\n\t-------------------------------------------------------------------------------------------------\n";
}

void ingresar_moroso(filial _filial)
{
	ofstream archivo;

	archivo.open("morosos.txt",ios::app);    // Operaciones de añadidura

	if (archivo.fail()){
        cout<<"\n\t\t\t~~~~ No se pudo crear el archivo ~~~~\n";
		system("pause");
		exit(1);
	}

	archivo<<_filial.ID<<'\t'<<_filial.nombres<<'\t'<<_filial.monto<<'\t'<<_filial.situacion<<'\n';
	archivo.close();

}

void eliminar_realizado(filial _filial, char aux[9])
{
	ifstream archivo;
	ofstream temp;
	int cont = 1;
	
	
	archivo.open("morosos.txt",ios::in);   // Operaciones de lectura

	if (archivo.fail()){
        cout<<"\n\t\t\t~~~~ No se pudo abrir el archivo ~~~~\n";
		system("pause");
		exit(1);
	}

	temp.open("temp.txt",ios::app);
	if (temp.fail()){
        cout<<"\n\t\t\t~~~~ No se pudo crear temporal ~~~~\n";
		system("pause");
		exit(1);
	}

	archivo>>_filial.ID>>_filial.nombres>>_filial.monto>>_filial.situacion;

	while(!archivo.eof())
	{	
		if (strcmp(aux,_filial.ID) != 0)
			temp<<_filial.ID<<'\t'<<_filial.nombres<<'\t'<<_filial.monto<<'\t'<<_filial.situacion<<'\n';
		
		archivo>>_filial.ID>>_filial.nombres>>_filial.monto>>_filial.situacion;
	}
	archivo.close();
	temp.close();
	remove("morosos.txt");
    rename("temp.txt","morosos.txt");

	cout<<"\n\t\t--------------------------------------\n";
}

void mostrar_moroso(filial _filial)
{
	system("cls");
	ifstream archivo;
	int cont = 1;
	
	archivo.open("morosos.txt",ios::in);   // Operaciones de lectura
	if (archivo.fail()){
        cout<<"\n\t\t\t~~~~ No se pudo crear el archivo ~~~~\n";
		system("pause");
		exit(1);
	}

	archivo>>_filial.ID>>_filial.nombres>>_filial.monto>>_filial.situacion;

	cout<<"\t\t"<<setw(55)<<"...:::  REGISTRO DE FILIAL MOROSO  :::...\n"
		<<"\t\t"<<setw(55)<<"==========================================\n"
		<<"\n\t\tN"<<setw(16)<<"Filial"<<setw(16)<<"Nombres"<<setw(16)<<"Monto"<<setw(16)<<"Situacion"
		<<"\n\t\t-----------------------------------------------------------------\n";

	while(!archivo.eof())
	{
		cout<<"\n\t\t"<<cont
			<<setw(16)<<_filial.ID
			<<setw(16)<<_filial.nombres
			<<setw(16)<<_filial.monto
			<<setw(16)<<_filial.situacion;
			
		archivo>>_filial.ID>>_filial.nombres>>_filial.monto>>_filial.situacion;
		cont++;	
	}
	archivo.close();

	cout<<"\n\t\t-----------------------------------------------------------------\n";
}

bool FechaValida(int YY, int MM, int DD){
	bool valido;

	if ( MM>= 1 && MM <=12 && YY<=2021)
	{
		switch ( MM )
		{

			case  1 :
					if ( DD  >= 1 && DD <= 31 )
						valido=true;					
					else 
						valido=false;
					break;

			case  3 :
					if ( DD >= 1 && DD <= 31 )
						valido=true;					
					else 
						valido=false;
					break;

			case  5 :
					if ( DD >= 1 && DD <= 31 )
						valido=true;			
					else
						valido=false;
					break;

			case  7 :
					if ( DD >= 1 && DD <= 31 )
						valido=true;		
					else
						valido=false;
					break;

			case  8 :
					if ( DD >= 1 && DD <= 31 )
						valido=true;			
					else
						valido=false;
					break;

			case 10 :
					if ( DD >= 1 && DD <= 31 )
						valido=true;
					else
						valido=false;
					break;

			case 12 : 
					if ( DD >= 1 && DD <= 31 )
						valido=true;			
					else
						valido=false;
					break;

			case  4 :
					if ( DD >= 1 && DD <= 30 )
						valido=true;
					else
						valido=false;
					break;

			case  6 :
					if ( DD >= 1 && DD <= 30 )
						valido=true; 		   
					else
						valido=false;
					break;

			case  9 :
					if ( DD >= 1 && DD <= 30 )
						valido=true;			
					else
						valido=false;
					break;

			case 11 : 
					if ( DD >= 1 && DD <= 30 )
						valido=true;			
					else
						valido=false;
					break;

			case  2 : 
					if( YY % 4 == 0 && YY % 100 != 0 ){
		
						if ( DD >= 1 && DD <= 29 )
							valido=true;					
						else
							valido=false;
					} 
					else{
						if ( DD >= 1 && DD <= 28 )
							valido=true;					
						else
							valido=false;
					}
		}	

	}
	if (MM<1 && MM>12 && YY>2021)
		valido=false;

	return valido;
}

// Mensajes ///////////////////////////////////////////////////////////
void mensaje_salida()
{
	system("cls");
	cout<<"\n\t\t..........:::::::: FIN DE PROGRAMA ::::::::..........\n";
}
