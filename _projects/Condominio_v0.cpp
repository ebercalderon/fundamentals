#include <iostream>
#include <stdio.h>
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
	char situacion[10]={"Moroso"};
};

// PROTOTIPOS ///////////////////////////////////////////////////////////
int menu();
void procesos(FILE *R, FILE *F, filial _filial, fecha calendario);

void crear_filial(FILE *R);
void ingresar_filial(FILE *R, filial _filial);
void cobro_filial(FILE *R, FILE *F, filial _filial, fecha calendario);
void realizar_cobro(FILE *R, FILE *F, filial _filial, int dia, string _aux);
bool FechaValida(fecha calendario, int *aux);
string consulta_filial(FILE *R, filial _filial);

// Pagos 
int menu_mostrar();
void proceso_mostrar(FILE *R, FILE *F, filial _filial);
void mostrar_filial(FILE *R, filial _filial);
void mostrar_realizado(FILE *F, filial _filial);

string fecha_local();
void mensaje_salida();	// Mensajes

// MAIN ///////////////////////////////////////////////////////////
int main()
{	
	FILE *R;
	filial _filial;
	FILE *F;
	fecha calendario;

	// Llamada al proceso
	procesos(R, F, _filial, calendario);
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
    	<<"\n\t\t\t[1] Crear registros"
    	<<"\n\t\t\t[2] Ingresar filial"
    	<<"\n\t\t\t[3] Registrar cobro"
		<<"\n\t\t\t[4] Consultar filial"
		<<"\n\t\t\t[5] Mostrar pagos"
    	<<"\n\n\n\t\t\t\t\t\t|| [6] Salir ||\n\n";
    do{
		cout<<"\n\t\t\tDigite opcion [ ]\b\b";
		cin>>opcion;
    }while(opcion < 1 || opcion > 6);
    
    return opcion;
}

void procesos(FILE *R, FILE *F, filial _filial, fecha calendario)
{
	int opcion;
	do
	{	
		system("COLOR F0");	
		opcion = menu();
		switch (opcion)
		{
			case 1: crear_filial(R); break;	
			case 2:	ingresar_filial(R, _filial); break;;
			case 3: cobro_filial(R, F, _filial, calendario); break;
			case 4:	
					consulta_filial(R, _filial); 
					cout<<"\n"; 
					system("pause"); break;
			case 5: proceso_mostrar(R, F, _filial); break;
			case 6:	mensaje_salida(); break;
		}
	}while (opcion != 6);
}

// Creacion de registro
void crear_filial(FILE *R)
{	
	R = fopen("filial.txt","w");
	if (R != NULL)
	{
		cout<<"\n\t\t\t....:::Creacion exitosa:::....\n\n";
		fclose(R);
	}
	else
		cout<<"\n\t\t\t~~~~ No se pudo crear el archivo ~~~~\n";

	system("pause");
}

// Ingreso de datos de filial
void ingresar_filial(FILE *R, filial _filial)
{
	int dia;
	system("cls");
	cout<<"\n\t\tINGRESO DE DATOS DE FILIAL"
		<<"\n\t==========================================="
		<<"\n\tA continuacion complete los siguientes datos:\n";
	fflush(stdin);
	cout<<"\n\tIngrese el numero de filial: "; cin.getline(_filial.ID,9,'\n');
	cout<<"\n\tNombres : "; cin.getline(_filial.nombres,20,'\n');
	cout<<"\n\tMonto: ";cin>>_filial.monto;
	cout<<fecha_local();

	R = fopen("filial.txt","a");

	if (R != NULL)
	{
		fwrite(&_filial,sizeof(_filial),1,R); 
			if (!ferror(R))
			{
				cout<<"\n\t\t....:::Registro exitoso:::....\n\n";
				fclose(R);
			}
			else
				cout<<"\n\t\t~~~~ Error de escritura en archivo ~~~~\n";
	}
	else 
		cout<<"\n\t\t~~~~ No se puede abrir el archivo ~~~~\n"; 

	system("pause");
}

void cobro_filial(FILE *R, FILE *F, filial _filial, fecha calendario){
	system("cls");
	int aux;
	string _aux=consulta_filial(R, _filial);
	cout<<"\n";
	system("pause");
	if (_aux!="0"){
		if(FechaValida(calendario, &aux)){
			realizar_cobro(R, F, _filial, aux, _aux);
			cout<<"\n\t....:::Pago realizado:::....\n";
		}
		else
			cout<<"\n\tOperacion incorrecta\n";

		system("pause");
	}
}

void realizar_cobro(FILE *R, FILE *F, filial _filial, int dia, string _aux){
	int i;
	char buffer[10];
	strcpy(buffer,_aux.c_str());	
	R=fopen("filial.txt","r");
	if (R != NULL)	// Valida la existencia del archivo
	{	
		while(!feof(R)){
			fread(&_filial,sizeof(_filial),1,R);
			if (!ferror(R))
			{
				if (!feof(R))
				{
					if (strcmp(buffer,_filial.ID)==0){
						i++;
						if (i<2){
							if (dia<10)
								cout<<"\n\t\tCuota a pagar		: "<<_filial.monto;
							else
								cout<<"\n\t\tCuota a pagar + 10%: "<<_filial.monto*1.1;

							strcpy(_filial.situacion,"Cumplido");
						}
					}
				}			
			}
		}
		fclose(R);
		cout<<"\n\t\t-----------------------------\n";
	}
	F = fopen("realizados.txt","a");

	if (F != NULL)
	{
		fwrite(&_filial,sizeof(_filial),1,F); 
			if (ferror(F))
				cout<<"\n\t\t....:::Registro invalido:::....\n\n";
	}
	fclose(F);
				
			
}

bool FechaValida(fecha calendario, int *aux){
	bool valido;
	system("cls");
	fflush(stdin);
	cout<<"\t\tAnio	: "; cin>>calendario.anio;
	cout<<"\n\t\tMes	: "; cin>>calendario.mes;
	cout<<"\n\t\tDia	: "; cin>>calendario.dia;

	if (calendario.dia  >= 1 && calendario.dia <= 31)
		*aux = calendario.dia;

	if ( calendario.mes>= 1 && calendario.mes <=12 && calendario.anio<=2021)
	{
		switch ( calendario.mes )
		{

			case  1 :
					if ( calendario.dia  >= 1 && calendario.dia <= 31 )
						valido=true;					
					else 
						valido=false;
					break;

			case  3 :
					if ( calendario.dia >= 1 && calendario.dia <= 31 )
						valido=true;					
					else 
						valido=false;
					break;

			case  5 :
					if ( calendario.dia >= 1 && calendario.dia <= 31 )
						valido=true;			
					else
						valido=false;
					break;

			case  7 :
					if ( calendario.dia >= 1 && calendario.dia <= 31 )
						valido=true;		
					else
						valido=false;
					break;

			case  8 :
					if ( calendario.dia >= 1 && calendario.dia <= 31 )
						valido=true;			
					else
						valido=false;
					break;

			case 10 :
					if ( calendario.dia >= 1 && calendario.dia <= 31 )
						valido=true;
					else
						valido=false;
					break;

			case 12 : 
					if ( calendario.dia >= 1 && calendario.dia <= 31 )
						valido=true;			
					else
						valido=false;
					break;

			case  4 :
					if ( calendario.dia >= 1 && calendario.dia <= 30 )
						valido=true;
					else
						valido=false;
					break;

			case  6 :
					if ( calendario.dia >= 1 && calendario.dia <= 30 )
						valido=true; 		   
					else
						valido=false;
					break;

			case  9 :
					if ( calendario.dia >= 1 && calendario.dia <= 30 )
						valido=true;			
					else
						valido=false;
					break;

			case 11 : 
					if ( calendario.dia >= 1 && calendario.dia <= 30 )
						valido=true;			
					else
						valido=false;
					break;

			case  2 : 
					if( calendario.anio % 4 == 0 && calendario.anio % 100 != 0 ){
		
						if ( calendario.dia >= 1 && calendario.dia <= 29 )
							valido=true;					
						else
							valido=false;
					} 
					else{
						if ( calendario.dia >= 1 && calendario.dia <= 28 )
							valido=true;					
						else
							valido=false;
					}
		}	

	}
	if (calendario.mes<1 && calendario.mes>12 && calendario.anio>2021)
		valido=false;

	return valido;
}


string consulta_filial(FILE *R, filial _filial){
	char aux[10];
	int i=0;	// verifica existencia del ID

	system("cls");
	cout<<"Ingrese su DNI: "; 
	cin>>aux;
	system("cls");
	
	R=fopen("filial.txt","r");
	if (R != NULL)	// Valida la existencia del archivo
	{	
		cout<<"\t\t ....::::  ESTADO DE FILIAL  ::::....\n"
			<<"\t\t ====================================\n"
    		<<"\n\t\t--------------------------------------\n";
		while(!feof(R)){
			fread(&_filial,sizeof(_filial),1,R);
			if (!ferror(R))
			{
				if (!feof(R))
				{
					if (strcmp(aux,_filial.ID)==0){
						i++;
						if (i<2){
							cout<<"\t\tIdentificacion filial	: "<<_filial.ID
								<<"\n\t\tNombres			: "<<_filial.nombres
								<<"\n\t\tCuota mensual		: "<<_filial.monto;

							return _filial.ID;
						}
					}
				}			
			}
			else
				cout<<"\n\t\t\t~~~~ Error de lectura en archivo ~~~~\n";

		}
		fclose(R);
		if(i==0)
			cout<<"\n\t\tEl filial no se encuentra registrado\n";

		cout<<"\n\t\t--------------------------------------\n";
	}
	else
		cout<<"\n\t\t\t~~~~ No se pudo cargar el archivo ~~~~\n";

	return "0";

}	

// MENU MOSTRAR ///////////////////////////////////////////////////////////
int menu_mostrar()
{
	system("cls");
	int opcion;
    cout<<"\n\t\t\t=============================="
		<<"\n\t\t\t...::: REPORTE DE PAGOS :::..."
    	<<"\n\t\t\t==============================\n"
    	<<"\n\t\t\t[1] Mostrar todos"
    	<<"\n\t\t\t[2] Mostrar realizados"
		<<"\n\t\t\t[3] Mostrar pendientes"
    	<<"\n\n\n\t\t\t\t\t|| [0] Atras ||\n\n";
    do
	{
		cout<<"Digite opcion [ ]\b\b";
		cin>>opcion;
    }while(opcion < 0 || opcion > 3);
    
    return opcion;
}

void proceso_mostrar(FILE *R, FILE *F, filial _filial)
{
	int opcion;
	do
	{
		opcion = menu_mostrar();
		if (opcion != 0)
		{
			switch (opcion)
			{
				case 1: mostrar_filial(R, _filial); break;
				case 2: mostrar_realizado(F,  _filial); break;
				case 3: break;
			}
		}
	}while (opcion != 0);

}

// Mostrar datos de filial en pantalla
void mostrar_filial(FILE *R, filial _filial)
{
	system("cls");
	int cont = 1;
	R = fopen("filial.txt","r"); 
	if (R != NULL)
	{
		cout<<"\t"<<setw(55)<<"...:::  REGISTRO DE FILIAL  :::...\n"
			<<"\t"<<setw(55)<<"====================================\n"
			<<"\n\tN"<<setw(16)<<"Filial"<<setw(16)<<"Nombres"<<setw(16)<<"Monto"
    		<<"\n\t------------------------------------------------------------\n";
		while(!feof(R)){
			fread(&_filial,sizeof(_filial),1,R);
		 	
			if (!ferror(R))
			{
				if (!feof(R))
				{
					cout<<"\n\t"<<cont
						<<setw(16)<<_filial.ID
						<<setw(16)<<_filial.nombres
						<<setw(16)<<_filial.monto;
					cont++;
				}
			}
			else
				cout<<"\n\t\t\t~~~~ Error de lectura en archivo ~~~~\n";
		}
		cout<<"\n\t------------------------------------------------------------\n";
		fclose(R);
	}
	else
		cout<<"\n\t\t\t~~~~ No se pudo cargar el archivo ~~~~\n";
	system("pause");
}

void mostrar_realizado(FILE *F, filial _filial)
{
	system("cls");
	int cont = 1;
	F = fopen("realizados.txt","r"); 
	if (F != NULL)
	{
		cout<<"\t"<<setw(55)<<"...:::  REGISTRO DE FILIAL  :::...\n"
			<<"\t"<<setw(55)<<"====================================\n"
			<<"\n\tN"<<setw(16)<<"Filial"<<setw(16)<<"Nombres"<<setw(16)<<"Monto"<<setw(16)<<"Situacion"
    		<<"\n\t------------------------------------------------------------------\n";
		while(!feof(F)){
			fread(&_filial,sizeof(_filial),1,F);
		 	
			if (!ferror(F))
			{
				if (!feof(F))
				{
					cout<<"\n\t"<<cont
						<<setw(16)<<_filial.ID
						<<setw(16)<<_filial.nombres
						<<setw(16)<<_filial.monto
						<<setw(16)<<_filial.situacion;
					cont++;
				}
			}
			else
				cout<<"\n\t\t\t~~~~ Error de lectura en archivo ~~~~\n";
		}
		cout<<"\n\t------------------------------------------------------------------\n";
		fclose(F);
	}
	else
		cout<<"\n\t\t\t~~~~ No se pudo cargar el archivo ~~~~\n";
	system("pause");
}

string fecha_local()
{
    time_t t = time(NULL);
	tm* timePtr = localtime(&t);

    stringstream ss_year;
    ss_year << timePtr->tm_year+1900;
    string Year = ss_year.str();

    stringstream ss_month;
    ss_month << timePtr->tm_mon+1;
    string Month = ss_month.str();
    if(atoi(Month.c_str()) < 10)
        Month = "0"+Month;

    stringstream ss_day;
    ss_day << timePtr->tm_mday;
    string Day = ss_day.str();
    if(atoi(Day.c_str()) < 10)
        Day = "0"+Day;

    string Fecha ="\n\tFecha: " +Day+"-"+Month+"-"+Year+"\n";

    return Fecha;
}

// Mensajes ///////////////////////////////////////////////////////////
void mensaje_salida()
{
	system("cls");
	cout<<"\n\t\t..........:::::::: FIN DE PROGRAMA ::::::::..........\n";
	system("pause");
	system("cls");
}
