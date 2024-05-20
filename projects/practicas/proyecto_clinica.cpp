#include <iostream>
#include <stdio.h>
#include <iomanip>	//setw
#include <string.h>	//strcmp
using namespace std;

// ESTRUCTURAS ///////////////////////////////////////////////////////////
struct datos{
	char DNI[9];
	char nombres[20];
	char apellido_paterno[20];
	char apellido_materno[20];
	char sexo;
	char celular[9];
	int	edad;
	int pago;
};

struct fecha{
	datos _code;
	int dia;
	int mes;
	int anio;
	int turno;
};

struct paciente{
	datos _datos;
	//fecha fecha_nacimiento_paciente; 
	char estado_civil;
	char emergencia[7];
};

struct historia{
	datos _clinico;
	//char direccion[60];
	//fecha consulta;
	float talla; //dos decimales y en m.
	float peso; //dos decimales y en kg.
	char enfermedad[30];
	char sintoma1 [30];	
	char sintoma2 [30];	
	char sintoma3 [30];	
	
};

struct receta{
	datos _r;
	char nombre_farmaco[30];
	char posologia[30];//mg ml
	char dosis[30];//cantidad cada tiempo
	char antes_despuescomida[20];
};

struct profesional{
	char cod1[9];
 	char nombre[20];
 	char apellido[20];
 	char profesion[20];  
 	int edad;
 	char sexo;
	char especialidad [20];
	int rne;
	char td[10];
	char th[10];
	
};

// PROTOTIPOS ///////////////////////////////////////////////////////////
int menu();
void procesos(paciente _paciente, fecha _cita, historia _historia, receta _receta, profesional _profesional);

int menu_Area_Adminstrativa();	// AREA ADMINISTRATIVA
void proceso_Area_Adminstrativa(paciente _paciente, fecha _cita, profesional _profesional);

int menu_Administracion();	// Administracion	
void proceso_Administracion(paciente _paciente, fecha _cita, profesional _profesional);
void mostrar_pacientes(paciente _paciente);
void mostrar_citas(fecha _cita);
void mostrar_pagos(fecha _cita);
void mostrar_profesional(profesional _profesional);

int menu_Recepcion_Caja();	// Recepcion-Caja
void proceso_Recepcion_Caja(paciente _paciente, fecha _cita, profesional _profesional);
void crear_paciente();
void crear_cita();
void crear_pago();
void ingresar_paciente(paciente _paciente);	
void registrar_paciente(paciente _paciente);
bool consultar_duplicado(paciente _paciente, char aux[9]);
bool consultar_paciente(paciente _paciente, char aux[9]);
void modificar_paciente(paciente _paciente, char aux[9]);
void registrar_temporal(paciente _paciente);
void ingresar_cita(paciente _paciente, fecha _cita);
void registrar_cita(fecha _cita);
bool cita_duplicado(fecha _cita, char aux[9], int YY, int MM, int DD, int turno);
int consultar_cita(fecha _cita, char aux[9]);
void ingresar_pago(fecha _cita);
void registrar_pago(fecha _cita);

int menu_Area_Hospitalaria();	// AREA HOSPITALARIA
void proceso_Area_Hospitalaria(paciente _paciente, fecha _cita, historia _historia, receta _receta);

int menu_Especialidades();	// Especialidades
void proceso_Especialidades(paciente _paciente, fecha _cita, historia _historia, receta _receta);
void crear_historia();
void crear_receta();
void ingresar_historia(paciente _paciente, historia _historia);
void registrar_historia(historia _historia);
bool consultar_historia(paciente _paciente, historia _historia, char aux[9]);
void ingresar_receta(paciente _paciente, receta _receta);
void registrar_receta(receta _receta);
bool consultar_receta(paciente _paciente, receta _receta, char aux[9]);

int menu_Planificacion();	// AREA RRHH
void procesos_Planificacion(profesional _profesional);	
void crear_profesional(profesional _profesional);
bool consultar_profesional(profesional _profesional, char aux[9]);
bool consultar_duplicado_profesional(profesional _profesional, char aux[9]);
void ingresar_profesional(profesional _profesional);
void registrar_profesional(profesional _profesional);
void registrar_temporal_profesional(profesional _profesional);
void modificar_profesional(profesional _profesional, char aux[9]);
void pedir_colegiatura(char aux[9]);

bool confirmar();
bool fecha_valida(int YY, int MM, int DD);
void pedir_DNI(char DNI[]);

void mensaje_salida();	//Mensajes

// MAIN ///////////////////////////////////////////////////////////
int main()
{	
	paciente _paciente;
	fecha _cita;
	historia _historia;
	receta _receta;
	profesional _profesional;

	// Llamada al proceso
	procesos(_paciente, _cita, _historia, _receta, _profesional);
    return 0;
}

// MENU PRINCIPAL ///////////////////////////////////////////////////////////
int menu()
{
	system("cls");
    int opcion;
    cout<<"\n\t\t\t======================================="
		<<"\n\t\t\t....:::: DEPARTAMENTOS / AREAS ::::...."
    	<<"\n\t\t\t=======================================\n\n"
    	<<"\n\t\t\t[1] AREA ADMINISTRATIVA"
    	<<"\n\t\t\t[2] AREA HOSPITALARIA"
		<<"\n\t\t\t[3] AREA RRHH"
    	<<"\n\n\n\t\t\t\t\t\t|| [4] Salir ||\n\n";
    do{
		cout<<"\n\t\t\tDigite opcion [ ]\b\b";
		cin>>opcion;
    }while(opcion < 1 || opcion > 4);
    
    return opcion;
}

void procesos(paciente _paciente, fecha _cita, historia _historia, receta _receta, profesional _profesional)
{
	int opcion;
	do
	{	
		system("COLOR F0");	
		opcion = menu();
		switch (opcion)
		{
			case 1: proceso_Area_Adminstrativa(_paciente, _cita, _profesional); break;	
			case 2:	proceso_Area_Hospitalaria(_paciente, _cita, _historia, _receta); break;	// Evaluar quitar _paciente
			case 3:	procesos_Planificacion(_profesional); break;
			case 4: mensaje_salida(); break;
		}
	}while (opcion != 4);
}

// 1. AREA ADMINISTRATIVA ///////////////////////////////////////////////////////////
int menu_Area_Adminstrativa()
{
	system("cls");
	int opcion;
    cout<<"\n\t\t\t========================================="
		<<"\n\t\t\t......:::: AREA ADMINISTRATIVA ::::......"
    	<<"\n\t\t\t=========================================\n"
    	<<"\n\t\t\t[1] Administracion"
    	<<"\n\t\t\t[2] Recepcion / Caja"
    	<<"\n\n\n\t\t\t\t\t\t|| [0] Atras ||\n\n";
    do
	{
		cout<<"\n\t\t\tDigite opcion [ ]\b\b";
		cin>>opcion;
    }while(opcion < 0 || opcion > 2);
    
    return opcion;
}

void proceso_Area_Adminstrativa(paciente _paciente, fecha _cita, profesional _profesional)
{
	int opcion;
	do
	{
		opcion = menu_Area_Adminstrativa();
		if (opcion != 0)
		{
			switch (opcion)
			{
				case 1: proceso_Administracion(_paciente, _cita, _profesional); break;
				case 2: proceso_Recepcion_Caja(_paciente, _cita, _profesional); break;
			}
		}
	}while (opcion != 0);

}

// 1.1. SUB AREA ADMINISTRACION ///////////////////////////////////////////////////////////
int menu_Administracion()
{
	system("cls");
	int opcion;
    cout<<"\n\t\t\t==============================="
		<<"\n\t\t\t...:::  Administracion  :::..."
    	<<"\n\t\t\t===============================\n"
    	<<"\n\t\t\t[1] Reporte de clientes"
		<<"\n\t\t\t[2] Reporte de citas"
		<<"\n\t\t\t[3] Reporte de pagos"
		<<"\n\t\t\t[4] Reporte de doctores"
		<<"\n\n\n\t\t\t\t\t|| [0] Atras ||\n\n";
    do
	{
		cout<<"\n\t\t\tDigite opcion [ ]\b\b";
		cin>>opcion;
    }while(opcion < 0 || opcion > 4);
    
    return opcion;
}

void proceso_Administracion(paciente _paciente, fecha _cita, profesional _profesional)
{
	int opcion;
	do
	{
		opcion = menu_Administracion();
		if (opcion != 0)
		{
			switch (opcion)
			{
				case 1: mostrar_pacientes(_paciente); break;
				case 2: mostrar_citas(_cita); break;
				case 3: mostrar_pagos(_cita); break;
				case 4: mostrar_profesional(_profesional); break;
			}
			system("pause");
		}
	}while (opcion != 0);
}

// Todos los pacientes registrados
void mostrar_pacientes(paciente _paciente)
{
	system("cls");

	FILE *R;
	int cont = 1;
	R = fopen("Paciente.txt","r"); 
	if (R != NULL)
	{
		cout<<"\t"<<setw(70)<<"...:::  REGISTRO DE PACIENTES  :::...\n"
			<<"\t"<<setw(70)<<"=====================================\n"
			<<"\n\tN"<<setw(16)<<"DNI"<<setw(16)<<"Nombres"<<setw(16)<<"A. Paterno"<<setw(16)<<"A. Materno"<<setw(12)<<"Sexo"<<setw(12)<<"E. Civil"<<setw(16)<<"Celular"
    		<<"\n\t---------------------------------------------------------------------------------------------------------\n";
		while(!feof(R)){
			fread(&_paciente,sizeof(_paciente),1,R);
		 	
			if (!ferror(R))
			{
				if (!feof(R))
				{
					cout<<"\n\t"<<cont
						<<setw(16)<<_paciente._datos.DNI
						<<setw(16)<<_paciente._datos.nombres
						<<setw(16)<<_paciente._datos.apellido_paterno
						<<setw(16)<<_paciente._datos.apellido_materno
						<<setw(12)<<_paciente._datos.sexo
						<<setw(12)<<_paciente.estado_civil
						<<setw(16)<<_paciente._datos.celular;		
					cont++;
				}
			}
			else
				cout<<"\n\t~~~~ Error de lectura en archivo ~~~~\n";
		}
		cout<<"\n\t---------------------------------------------------------------------------------------------------------\n";
		fclose(R);
	}
	else
		cout<<"\n\t~~~~ No se pudo cargar el archivo ~~~~\n";
}

// Todas citas programadas
void mostrar_citas(fecha _cita)
{
	system("cls");

	FILE *C;
	int cont = 1;
	C = fopen("Citas.txt","r"); 
	if (C != NULL)
	{
		cout<<"\t"<<setw(60)<<"...:::  REGISTRO DE CITAS  :::...\n"
			<<"\t"<<setw(60)<<"=================================\n"
			<<"\n\tN"<<setw(16)<<"DNI"<<setw(16)<<"Turno"<<setw(16)<<"Dia"<<setw(16)<<"Mes"<<setw(12)<<"Anio"
    		<<"\n\t------------------------------------------------------------------------------\n";
		while(!feof(C)){
			fread(&_cita,sizeof(_cita),1,C);
		 	
			if (!ferror(C))
			{
				if (!feof(C))
				{
					cout<<"\n\t"<<cont
						<<setw(16)<<_cita._code.DNI
						<<setw(16)<<_cita.turno
						<<setw(16)<<_cita.dia
						<<setw(16)<<_cita.mes
						<<setw(12)<<_cita.anio;		
					cont++;
				}
			}
			else
				cout<<"\n\t~~~~ Error de lectura en archivo ~~~~\n";
		}
		cout<<"\n\t------------------------------------------------------------------------------\n";
		fclose(C);
	}
	else
		cout<<"\n\t~~~~ No se pudo cargar el archivo ~~~~\n";
}

// Todas pagos realizados
void mostrar_pagos(fecha _cita)
{
	system("cls");

	FILE *F;
	int cont = 1;
	F = fopen("Pagos.txt","r"); 
	if (F != NULL)
	{
		cout<<"\t"<<setw(45)<<"...:::  REGISTRO DE PAGOS  :::...\n"
			<<"\t"<<setw(45)<<"=================================\n"
			<<"\n\t\tN"<<setw(16)<<"CLIENTE"<<setw(16)<<"PAGO"
    		<<"\n\t\t-------------------------------------\n";
		while(!feof(F)){
			fread(&_cita,sizeof(_cita),1,F);
		 	
			if (!ferror(F))
			{
				if (!feof(F))
				{
					cout<<"\n\t\t"<<cont
						<<setw(16)<<_cita._code.DNI
						<<setw(16)<<_cita._code.pago;	
					cont++;
				}
			}
			else
				cout<<"\n\t\t~~~~ Error de lectura en archivo ~~~~\n";
		}
		cout<<"\n\t\t-------------------------------------\n";
		fclose(F);
	}
	else
		cout<<"\n\t~~~~ No se pudo cargar el archivo ~~~~\n";
}

void mostrar_profesional(profesional _profesional)
{
	system("cls");

	FILE *D;
	int cont = 1;
	D = fopen("Profesional.txt","r"); 
	if (D != NULL)
	{
		cout<<"\t"<<setw(70)<<"...:::  REGISTRO DE DOCTORES  :::...\n"
			<<"\t"<<setw(70)<<"====================================\n"
			<<"\n\t\tN"<<setw(16)<<"APELLIDO"<<setw(16)<<"NOMBRE"<<setw(16)<<"ESPECIALIDAD"<<setw(16)<<"RNE"<<setw(16)<<"DIAS DISP."<<setw(16)<<"TURNO"
    		<<"\n\t\t-------------------------------------------------------------------------------------------------\n";
		while(!feof(D)){
			fread(&_profesional,sizeof(_profesional),1,D);
		 	
			if (!ferror(D))
			{
				if (!feof(D))
				{
					cout<<"\n\t\t"<<cont
						<<setw(16)<<_profesional.apellido
						<<setw(16)<<_profesional.nombre
						<<setw(16)<<_profesional.especialidad
						<<setw(16)<<_profesional.rne
						<<setw(16)<<_profesional.td
						<<setw(16)<<_profesional.th;
					cont++;
				}
			}
			else
				cout<<"\n\t\t~~~~ Error de lectura en archivo ~~~~\n";
		}
		cout<<"\n\t\t-------------------------------------------------------------------------------------------------\n";
		fclose(D);
	}
	else
		cout<<"\n\t~~~~ No se pudo cargar el archivo ~~~~\n";
}

// 1.2. SUB AREA RECEPCION - CAJA ///////////////////////////////////////////////////////////
int menu_Recepcion_Caja()
{
	system("cls");
	int opcion;
    cout<<"\n\t\t\t================================"
		<<"\n\t\t\t...:::  Recepcion / Caja  :::..."
    	<<"\n\t\t\t================================\n"
    	<<"\n\t\t\t[1] Crear registros\n"
		<<"\n\t\t\t[2] Registrar paciente"
		<<"\n\t\t\t[3] Consultar paciente"
		<<"\n\t\t\t[4] Modificar paciente\n"
		<<"\n\t\t\t[5] Mostrar horarios\n"
		<<"\n\t\t\t[6] Registrar cita"
		<<"\n\t\t\t[7] Registrar pago"
    	<<"\n\n\n\t\t\t\t\t || [0] Atras ||\n\n";
    do
	{
		cout<<"\n\t\t\tDigite opcion [ ]\b\b";
		cin>>opcion;
    }while(opcion < 0 || opcion > 7);
    
    return opcion;
}

void proceso_Recepcion_Caja(paciente _paciente, fecha _cita, profesional _profesional)
{
	int opcion;
	do
	{
		opcion = menu_Recepcion_Caja();
		if (opcion != 0)
		{
			switch (opcion)
			{
				case 1: 
					if (confirmar())
					{
						crear_paciente(); crear_cita(); crear_pago();
					}
					break;
				case 2: ingresar_paciente(_paciente); break;
				case 3: pedir_DNI(_paciente._datos.DNI); consultar_paciente(_paciente, _paciente._datos.DNI); consultar_cita(_cita, _paciente._datos.DNI);break;
				case 4: pedir_DNI(_paciente._datos.DNI); modificar_paciente(_paciente, _paciente._datos.DNI); break;
				case 5: mostrar_profesional(_profesional); break;
				case 6: ingresar_cita(_paciente, _cita); break;
				case 7: ingresar_pago(_cita); break;
			}
			system("pause");
		}
	}while (opcion != 0);
}

// Registros
void crear_paciente()
{	
	system("cls");

	FILE *P;
	P = fopen("Paciente.txt","w");
	
	if (P != NULL)
	{
		fclose(P);
		cout<<"\n\n\t\t\t....::: Creacion exitosa:Pacientes :::....\n\n"; 
	}
	else
		cout<<"\n\n\t\t\t~~~~ No se pudo crear el archivo ~~~~\n\n";	
}

void crear_cita()
{	
	FILE *C;
	C = fopen("Citas.txt","w");
	
	if (C != NULL)
	{
		fclose(C);
		cout<<"\n\n\t\t\t....::: Creacion exitosa:Citas :::....\n\n"; 
	}
	else
		cout<<"\n\n\t\t\t~~~~ No se pudo crear el archivo ~~~~\n\n";		
}

void crear_pago()
{	
	FILE *F;
	F = fopen("Pagos.txt","w");
	
	if (F != NULL)
	{
		fclose(F);
		cout<<"\n\n\t\t\t....::: Creacion exitosa:Pagos :::....\n\n"; 
	}
	else
		cout<<"\n\n\t\t\t~~~~ No se pudo crear el archivo ~~~~\n\n";		
}

// Ingreso del paciente
void ingresar_paciente(paciente _paciente)
{
	system("cls");
	bool temp;

	cout<<"\n\t\t\t\tINGRESO DE DATOS DEL PACIENTE"
		<<"\n\t\t\t==============================================="
		<<"\n\t\t\tA continuacion complete los siguientes datos:\n";
	fflush(stdin);
	cout<<"\n\t\t\tIngrese el numero de DNI: "; cin.getline(_paciente._datos.DNI,9,'\n');

	temp = consultar_duplicado(_paciente, _paciente._datos.DNI);
	if (!temp)
	{
		cout<<"\n\t\t\tNombres : "; cin.getline(_paciente._datos.nombres,20,'\n');
		cout<<"\n\t\t\tApellido paterno: "; cin.getline(_paciente._datos.apellido_paterno,20,'\n');
		cout<<"\n\t\t\tApellido materno: "; cin.getline(_paciente._datos.apellido_materno,20,'\n');
		cout<<"\n\t\t\tSexo (M/F): "; cin>>_paciente._datos.sexo;
		cout<<"\n\t\t\tEstado Civil (S/C) : "; cin>>_paciente.estado_civil; 
		cout<<"\n\t\t\tCelular: "; cin>>_paciente._datos.celular;
		cout<<"\n\t\t\tTelefono emergencia: "; cin>>_paciente.emergencia;
		
		registrar_paciente( _paciente);
	}
	else
		cout<<"\n\n\t\t\t....::: Paciente duplicado :::....\n\n";
}

void registrar_paciente(paciente _paciente)
{	
	FILE *P;
	P = fopen("Paciente.txt","a");

	if (P != NULL)
	{
		fwrite(&_paciente,sizeof(_paciente),1,P); 
			if (!ferror(P))
			{
				cout<<"\n\n\t\t\t....::: Registro exitoso :::....\n\n";
				fclose(P);
			}
			else
				cout<<"\n\n\t\t\t~~~~ Error de escritura en archivo ~~~~\n\n";
	}
	else 
		cout<<"\n\n\t\t\t~~~~ No se puede abrir el archivo ~~~~\n\n"; 	
}

bool consultar_duplicado(paciente _paciente, char aux[9])
{
	FILE *P;
	bool temp = false;
	int cont=0;

	P = fopen("Paciente.txt","r"); 
	if (P != NULL)
	{
		while(!feof(P))
		{
			fread(&_paciente,sizeof(_paciente),1,P);
			
			if (!ferror(P))
			{
				if (!feof(P))
				{
					if(strcmp(aux,_paciente._datos.DNI) == 0)
						temp=true;		
					cont++;
				}
			}
			else
				cout<<"\n\n\t\t\t~~~~ Error de lectura en archivo ~~~~\n\n";
		}
		fclose(P);
	}
	else
		cout<<"\n\n\t\t\t~~~~ No se pudo cargar el archivo ~~~~\n\n";

	return temp;
}	

// Busqueda, verificacion y modificacion de datos
bool consultar_paciente(paciente _paciente, char aux[9])
{
	system("cls");
	FILE *P;
	bool temp = false;

	P = fopen("Paciente.txt","r"); 
	if (P != NULL)
	{
		while(!feof(P))
		{
			fread(&_paciente,sizeof(_paciente),1,P);
			
			if (!ferror(P))
			{
				if (!feof(P))
				{
					if(strcmp(aux,_paciente._datos.DNI) == 0 && temp == false )
					{
						temp = true;
						cout<<"\t\t  ....::::  ESTADO DE PACIENTE  ::::....\n"
							<<"\t\t=========================================\n"
							<<"\n\t\t-----------------------------------------"
							<<"\n\t\tDNI			: "<<_paciente._datos.DNI
							<<"\n\t\tNombres			: "<<_paciente._datos.nombres
							<<"\n\t\tApellido paterno	: "<<_paciente._datos.apellido_paterno
							<<"\n\t\tApellido materno	: "<<_paciente._datos.apellido_materno
							<<"\n\t\tEstado civil		: "<<_paciente.estado_civil
							<<"\n\t\tCelular			: "<<_paciente._datos.celular
							<<"\n\t\tTelefono Emergencia	: "<<_paciente.emergencia
							<<"\n\t\t-----------------------------------------\n";
					}
				}
			}
			else
				cout<<"\n\n\t\t\t~~~~ Error de lectura en archivo ~~~~\n\n";
		}
		fclose(P);
	}
	else
		cout<<"\n\n\t\t\t~~~~ No se pudo cargar el archivo ~~~~\n\n";
		
	if (temp == false)
		cout<<"\n\n\t\t\t~~~~ Paciente no registrado ~~~~\n\n";

	return temp;
}	

void modificar_paciente(paciente _paciente, char aux[9])
{
	system("cls");
	FILE *P, *TEMP;
	bool temp = false;

	P = fopen("Paciente.txt","r"); 
	if (P != NULL)
	{
		while(!feof(P))
		{
			fread(&_paciente,sizeof(_paciente),1,P);
			
			if (!ferror(P))
			{
				if (!feof(P))
				{
					if(strcmp(aux,_paciente._datos.DNI) == 0)
					{
						temp = true;
						cout<<"\t\t....::::  Campos modificables  ::::...."
							<<"\n\t\t--------------------------------------";
						cout<<"\n\t\t\tEstado Civil (S/C) : "; cin>>_paciente.estado_civil; 
						cout<<"\n\t\t\tCelular: "; cin>>_paciente._datos.celular;
						cout<<"\n\t\t\tTelefono emergencia: "; cin>>_paciente.emergencia;
						cout<<"\n\t\t--------------------------------------\n";

						registrar_temporal(_paciente);
					}
					else
						registrar_temporal(_paciente);
				}
			}
			else
				cout<<"\n\n\t\t\t~~~~ Error de lectura en archivo ~~~~\n\n";
		}
		fclose(P);
		
		remove("Paciente.txt");
        rename("temp.txt","Paciente.txt");
	}
	else
		cout<<"\n\n\t\t\t~~~~ No se pudo cargar el archivo ~~~~\n\n";
		
	if (temp == false)
		cout<<"\n\n\t\t\t~~~~ Paciente no registrado ~~~~\n\n";

}	

void registrar_temporal(paciente _paciente)
{	
	FILE *T;
	T = fopen("temp.txt","a");

	if (T != NULL)
	{
		fwrite(&_paciente,sizeof(_paciente),1,T); 
			if (!ferror(T))
				fclose(T);
			else
				cout<<"\n\n\t\t\t~~~~ Error de escritua ~~~~\n\n";
	}
	else 
		cout<<"\n\n\t\t\t~~~~ No se puede abrir el archivo ~~~~\n\n"; 	
}

// Ingreso de cita
void ingresar_cita(paciente _paciente, fecha _cita)
{
	system("cls");
	bool temp, _time, duplicado;

	cout<<"\n\t\t\t\tPROGAMACION DE CITA"
		<<"\n\t\t\t-----------------------------------\n";
		
	fflush(stdin);
	cout<<"\t\t\tIngrese el numero de DNI: "; cin.getline(_paciente._datos.DNI,9,'\n');
	
	temp = consultar_duplicado(_paciente, _paciente._datos.DNI);
	if (temp)
	{
		cout<<"\n\t\t\tFecha de cita: \n";
		cout<<"\t\t\tAnio	: "; cin>>_cita.anio;
		cout<<"\t\t\tMes	: "; cin>>_cita.mes;
		cout<<"\t\t\tDia	: "; cin>>_cita.dia;

		_time = fecha_valida(_cita.anio, _cita.mes, _cita.dia);
		
		if (_time)
		{
			cout<<"\n\t\t\t-----------------------------------"
				<<"\n\t\t\t\t\tTurnos\n"
				<<"\n\t\t\t[1] Maniana"
				<<"\n\t\t\t[2] Tarde"
				<<"\n\t\t\t[3] Noche\n";
			do{
				cout<<"\n\t\t\tDigite turno[ ]\b\b"; cin>>_cita.turno;
			}while(_cita.turno != 1 && _cita.turno != 2 && _cita.turno != 3);
		
			duplicado = cita_duplicado(_cita, _paciente._datos.DNI, _cita.anio, _cita.mes, _cita.dia, _cita.turno);
			if (duplicado==false)
			{
				strcpy(_cita._code.DNI, _paciente._datos.DNI);
				registrar_cita(_cita);
			}
			else
				cout<<"\n\n\t\t\t....::: Usted ya tiene una cita :::....\n\n";
			
		}
		else
			cout<<"\n\n\t\t\t....::: Fecha incorrecta :::....\n\n";
	}
	else
		cout<<"\n\n\t\t\t....::: No registrado :::....\n\n";
	cout<<"\n\t\t\t-----------------------------------\n";
}

void registrar_cita(fecha _cita)
{	
	FILE *C;
	C = fopen("Citas.txt","a");

	if (C != NULL)
	{
		fwrite(&_cita,sizeof(_cita),1,C); 
			if (!ferror(C))
			{
				cout<<"\n\n\t\t\t....::: Cita programada :::....\n\n";
				fclose(C);
			}
			else
				cout<<"\n\n\t\t\t~~~~ Error de escritura en archivo ~~~~\n\n";
	}
	else 
		cout<<"\n\n\t\t\t~~~~ No se puede abrir el archivo ~~~~\n\n"; 	
}

bool cita_duplicado(fecha _cita, char aux[9], int YY, int MM, int DD, int turno)
{
	FILE *C;
	bool temp = false;

	C = fopen("Citas.txt","r"); 
	if (C != NULL)
	{
		while(!feof(C))
		{
			fread(&_cita,sizeof(_cita),1,C);
			
			if (!ferror(C))
			{
				if (!feof(C))
				{
					if(strcmp(aux,_cita._code.DNI) == 0)
					{
						if(YY == _cita.anio)
						{
							if(MM == _cita.mes)
							{
								if(DD == _cita.dia)
								{
									if(turno == _cita.turno)
										temp=true;
								}
							}
						}
					}		
				}
			}
			else
				cout<<"\n\n\t\t\t~~~~ Error de lectura en archivo ~~~~\n\n";
		}
		fclose(C);
	}
	else
		cout<<"\n\n\t\t\t~~~~ No se pudo cargar el archivo ~~~~\n\n";

	return temp;
}

// Mostrar cita
int consultar_cita(fecha _cita, char aux[9])
{
	FILE *C;
	bool temp = false;
	int cont = 0;

	C = fopen("Citas.txt","r"); 
	if (C != NULL)
	{
		cout<<"\t\t\t....::::  CITAS  ::::...."
			<<"\n\t\t-----------------------------------------"
			<<"\n\t\tN"<<setw(10)<<"Turno"<<setw(10)<<"DD"<<setw(10)<<"MM"<<setw(10)<<"YY\n";
		while(!feof(C))
		{
			fread(&_cita,sizeof(_cita),1,C);
			
			if (!ferror(C))
			{
				if (!feof(C))
				{
					if(strcmp(aux,_cita._code.DNI) == 0)
					{
						temp = true;
						cont++;
						cout<<"\n\t\t"<<cont<<setw(10)<<_cita.turno<<setw(10)<<_cita.dia<<setw(10)<<_cita.mes<<setw(10)<<_cita.anio;
						
					}
				}
			}
			else
				cout<<"\n\n\t\t\t~~~~ Error de lectura en archivo ~~~~\n\n";
		}
		cout<<"\n\t\t-----------------------------------------\n";
		fclose(C);
	}
	else
		cout<<"\n\n\t\t\t~~~~ No se pudo cargar el archivo ~~~~\n\n";
		
	if (temp == false)
		cout<<"\n\n\t\t~~~~ No hay citas registradas ~~~~\n\n";

	return cont;
}	

// Pago
void ingresar_pago(fecha _cita)
{
	pedir_DNI(_cita._code.DNI);
	system("cls");
	_cita._code.pago = consultar_cita(_cita, _cita._code.DNI);
	if (_cita._code.pago != 0){
		
		_cita._code.pago *=20;
		cout<<"\t\tMonto a pagar: \t\t\tS/. "<<_cita._code.pago
			<<"\n\t\t-----------------------------------------\n";
		registrar_pago(_cita);
	}

}

void registrar_pago(fecha _cita)
{	
	FILE *F;
	F = fopen("Pagos.txt","a");

	if (F != NULL)
	{
		fwrite(&_cita,sizeof(_cita),1,F); 
			if (!ferror(F))
			{
				cout<<"\n\n\t\t\t....::: Pago realizado :::....\n\n";
				fclose(F);
			}
			else
				cout<<"\n\n\t\t\t~~~~ Error de escritura en archivo ~~~~\n\n";
	}
	else 
		cout<<"\n\n\t\t\t~~~~ No se puede abrir el archivo ~~~~\n\n"; 	
}

// 1. AREA HOSPITALARIA ///////////////////////////////////////////////////////////
int menu_Area_Hospitalaria()
{
	system("cls");
	int opcion;
    cout<<"\n\t\t\t======================================="
		<<"\n\t\t\t......:::: AREA HOSPITALARIA ::::......"
    	<<"\n\t\t\t=======================================\n"
    	<<"\n\t\t\t[1] Especialidades"
    	<<"\n\n\n\t\t\t\t\t\t|| [0] Atras ||\n\n";
    do
	{
		cout<<"\n\t\t\tDigite opcion [ ]\b\b";
		cin>>opcion;
    }while(opcion < 0 || opcion > 1);
    
    return opcion;
}

void proceso_Area_Hospitalaria(paciente _paciente, fecha _cita, historia _historia, receta _receta)
{
	int opcion;
	do
	{
		opcion = menu_Area_Hospitalaria();
		if (opcion != 0)
		{
			switch (opcion)
			{
				case 1: proceso_Especialidades(_paciente, _cita, _historia, _receta); break;
			}
		}
	}while (opcion != 0);

}

// 2.1. SUB AREA ESPECIALIDADES ///////////////////////////////////////////////////////////
int menu_Especialidades()
{
	system("cls");
	int opcion;
    cout<<"\n\t\t\t=============================="
		<<"\n\t\t\t...:::  Especialidades  :::..."
    	<<"\n\t\t\t==============================\n"
    	<<"\n\t\t\t[1] Crear registros\n"
		<<"\n\t\t\t[2] Registrar historial"
		<<"\n\t\t\t[3] Consultar historial\n"
		<<"\n\t\t\t[4] Consultar cita\n"
		<<"\n\t\t\t[5] Registrar receta"
		<<"\n\t\t\t[6] Consultar receta"
    	<<"\n\n\n\t\t\t\t\t || [0] Atras ||\n\n";
    do
	{
		cout<<"\n\t\t\tDigite opcion [ ]\b\b";
		cin>>opcion;
    }while(opcion < 0 || opcion > 6);
    
    return opcion;
}

void proceso_Especialidades(paciente _paciente, fecha _cita, historia _historia, receta _receta)
{
	int opcion;
	do
	{
		opcion = menu_Especialidades();
		if (opcion != 0)
		{
			switch (opcion)
			{
				case 1: 
					if (confirmar())
					{
						crear_historia(); crear_receta();
					}
					break;
				case 2: ingresar_historia(_paciente, _historia); break;
				case 3: pedir_DNI(_historia._clinico.DNI); consultar_paciente(_paciente, _historia._clinico.DNI); consultar_historia(_paciente, _historia, _historia._clinico.DNI); break;
				case 4: pedir_DNI(_historia._clinico.DNI); system("cls"); consultar_cita(_cita, _historia._clinico.DNI); break;
				case 5: ingresar_receta( _paciente, _receta); break;
				case 6: pedir_DNI(_receta._r.DNI); consultar_paciente(_paciente, _receta._r.DNI); consultar_receta(_paciente, _receta, _receta._r.DNI); break;
			}
			system("pause");
		}
	}while (opcion != 0);
}

// Registros
void crear_historia()
{	
	system("cls");

	FILE *H;
	H = fopen("Historia.txt","w");
	
	if (H != NULL)
	{
		fclose(H);
		cout<<"\n\n\t\t\t....::: Creacion exitosa:Historia :::....\n\n"; 
	}
	else
		cout<<"\n\n\t\t\t~~~~ No se pudo crear el archivo ~~~~\n\n";	
}

void crear_receta()
{	
	FILE *R;
	R = fopen("Receta.txt","w");
	
	if (R != NULL)
	{
		fclose(R);
		cout<<"\n\n\t\t\t....::: Creacion exitosa:Receta :::....\n\n"; 
	}
	else
		cout<<"\n\n\t\t\t~~~~ No se pudo crear el archivo ~~~~\n\n";		
}

// Ingreso del paciente
void ingresar_historia(paciente _paciente, historia _historia)
{
	system("cls");
	bool val;

	cout<<"\n\t\t\t\tHISTORIA CLINICA"
		<<"\n\t\t\t==============================================="
		<<"\n\t\t\tA continuacion complete los siguientes datos:\n";
	fflush(stdin);
	cout<<"\n\t\t\tIngrese el numero de DNI: "; cin.getline(_historia._clinico.DNI,9,'\n');

	val = consultar_duplicado(_paciente, _historia._clinico.DNI);
	if (val)
	{
		cout<<"\n\t\t\tTalla : "; cin>>_historia.talla;
		cout<<"\n\t\t\tPeso: "; cin>>_historia.peso;
		fflush(stdin);
		cout<<"\n\t\t\tSintoma 1: "; cin.getline(_historia.sintoma1,30,'\n');
		cout<<"\n\t\t\tSintoma 2: "; cin.getline(_historia.sintoma2,30,'\n');
		cout<<"\n\t\t\tSintoma 3: "; cin.getline(_historia.sintoma3,30,'\n');
		cout<<"\n\t\t\tEnfermedad: "; cin.getline(_historia.enfermedad,30,'\n');
		
		registrar_historia(_historia);
	}
	else
		cout<<"\n\n\t\t\t....::: Paciente no registrado :::....\n\n";
}

void registrar_historia(historia _historia)
{	
	FILE *H;
	H = fopen("Historia.txt","a");

	if (H != NULL)
	{
		fwrite(&_historia,sizeof(_historia),1,H); 
			if (!ferror(H))
			{
				cout<<"\n\n\t\t\t....::: Registro exitoso :::....\n\n";
				fclose(H);
			}
			else
				cout<<"\n\n\t\t\t~~~~ Error de escritura en archivo ~~~~\n\n";
	}
	else 
		cout<<"\n\n\t\t\t~~~~ No se puede abrir el archivo ~~~~\n\n"; 	
}

// Busqueda de historia
bool consultar_historia(paciente _paciente, historia _historia, char aux[9])
{
	FILE *H;
	bool temp = false;

	H = fopen("Historia.txt","r"); 
	if (H != NULL)
	{
		while(!feof(H))
		{
			fread(&_historia,sizeof(_historia),1,H);
			
			if (!ferror(H))
			{
				if (!feof(H))
				{
					if(strcmp(aux,_historia._clinico.DNI) == 0)
					{
						temp = true;
						cout<<"\n\t\t....::::  HISTORIA DE PACIENTE  ::::....\n"
							<<"\t\t=========================================\n"
							<<"\n\t\t-----------------------------------------"
							<<"\n\t\tTalla 		: "<<_historia.peso
							<<"\n\t\tPeso		: "<<_historia.talla
							<<"\n\t\tSintoma 1	: "<<_historia.sintoma1
							<<"\n\t\tSintoma 2	: "<<_historia.sintoma2
							<<"\n\t\tSintoma 3	: "<<_historia.sintoma3
							<<"\n\t\tEnfermedad	: "<<_historia.enfermedad
							<<"\n\t\t-----------------------------------------\n";
					}
				}
			}
			else
				cout<<"\n\n\t\t\t~~~~ Error de lectura en archivo ~~~~\n\n";
		}
		fclose(H);
	}
	else
		cout<<"\n\n\t\t\t~~~~ No se pudo cargar el archivo ~~~~\n\n";
		
	if (temp == false)
		cout<<"\n\n\t\t\t~~~~ Historia no registrado ~~~~\n\n";

	return temp;
}	

// Ingreso del paciente
void ingresar_receta(paciente _paciente, receta _receta)
{
	system("cls");
	bool val;

	cout<<"\n\t\t\t\t\tRECETA CLINICA"
		<<"\n\t\t\t==============================================="
		<<"\n\t\t\tA continuacion complete los siguientes datos:\n";
	fflush(stdin);
	cout<<"\n\t\t\tIngrese el numero de DNI: "; cin.getline(_receta._r.DNI,9,'\n');

	val = consultar_duplicado(_paciente, _receta._r.DNI);
	if (val)
	{
		cout<<"\n\t\t\tNombre del farcamo	: "; cin.getline(_receta.nombre_farmaco,30,'\n');
		cout<<"\n\t\t\tPosologia	: "; cin.getline(_receta.posologia,30,'\n');
		cout<<"\n\t\t\tDosis 		: "; cin.getline(_receta.dosis,30,'\n');
		cout<<"\n\t\t\tIndicacion	: "; cin.getline(_receta.antes_despuescomida,20,'\n');
		
		registrar_receta(_receta);
	}
	else
		cout<<"\n\n\t\t\t....::: Paciente no registrado :::....\n\n";
}

void registrar_receta(receta _receta)
{	
	FILE *R;
	R = fopen("Receta.txt","a");

	if (R != NULL)
	{
		fwrite(&_receta,sizeof(_receta),1,R); 
			if (!ferror(R))
			{
				cout<<"\n\n\t\t\t....::: Registro exitoso :::....\n\n";
				fclose(R);
			}
			else
				cout<<"\n\n\t\t\t~~~~ Error de escritura en archivo ~~~~\n\n";
	}
	else 
		cout<<"\n\n\t\t\t~~~~ No se puede abrir el archivo ~~~~\n\n"; 	
}

// Busqueda de receta
bool consultar_receta(paciente _paciente, receta _receta, char aux[9])
{
	//system("cls");
	FILE *H;
	bool temp = false;

	H = fopen("Receta.txt","r"); 
	if (H != NULL)
	{
		while(!feof(H))
		{
			fread(&_receta,sizeof(_receta),1,H);
			
			if (!ferror(H))
			{
				if (!feof(H))
				{
					if(strcmp(aux,_receta._r.DNI) == 0)
					{
						temp = true;
						consultar_paciente(_paciente, aux);
						cout<<"\n\t\t....::::  RECETA DE PACIENTE  ::::....\n"
							<<"\t\t=========================================\n"
							<<"\n\t\t-----------------------------------------"
							<<"\n\t\t\tNombre del farcamo	: "<<_receta.nombre_farmaco
							<<"\n\t\t\tPosologia	: "<<_receta.posologia
							<<"\n\t\t\tDosis 		: "<<_receta.dosis
							<<"\n\t\t\tIndicacion	: "<<_receta.antes_despuescomida
							<<"\n\t\t-----------------------------------------\n";
					}
				}
			}
			else
				cout<<"\n\n\t\t\t~~~~ Error de lectura en archivo ~~~~\n\n";
		}
		fclose(H);
	}
	else
		cout<<"\n\n\t\t\t~~~~ No se pudo cargar el archivo ~~~~\n\n";
		
	if (temp == false)
		cout<<"\n\n\t\t\t~~~~ Receta no registrado ~~~~\n\n";

	return temp;
}

// 3. AREA RRHH ///////////////////////////////////////////////////////////
int menu_Planificacion()
{
	system("cls");
	int opcion;
    cout<<"\n\t\t\t=========================="<<endl;
	cout<<"\n\t\t\tPlanificacion del personal"<<endl;
    cout<<"\n\t\t\t==========================\n"<<endl;
    cout<<endl;
    cout<<"\n\t\t[1] Crear archivo Profesionales de Salud"<<endl;
	cout<<"\t\t[2] Ingresar datos del Profesional de Salud"<<endl;
	cout<<"\t\t[3] Buscar por colegiatura del Profesionales de Salud"<<endl;
	cout<<"\t\t[4] Mostrar a todos los Profesionales de Salud "<<endl;
	cout<<"\t\t[5] Modificar Datos del Profesional de Salud" <<endl;
	cout<<"\n\n\t\t\t\t\t\t|| [0] Atras ||\n\n"<<endl;
    do
	{
		cout<<"\n\t\tDigite opcion [ ]\b\b";
		cin>>opcion;
    }while(opcion < 0 || opcion > 5);
    
    return opcion;
}

void procesos_Planificacion(profesional _profesional)
{
	int opcion,codigo,posi,ps,m;
	system("cls");
	do
	{
		opcion = menu_Planificacion();
		if (opcion != 0)
		{
			switch (opcion)
			{
				case 1: 
						crear_profesional(_profesional); 
						break;
				case 2:	
	  					ingresar_profesional(_profesional);
	  					break;
	 	 		case 3: 
	 	 				pedir_colegiatura(_profesional.cod1);
          				consultar_profesional(_profesional,_profesional.cod1);
						break;
				case 4: 
						mostrar_profesional(_profesional); 
						break;
				case 5: 
						pedir_colegiatura(_profesional.cod1);
						modificar_profesional(_profesional,_profesional.cod1);
						break;
			}
			system("pause");
		}
	}while (opcion != 0);

}

/////////////////////////////////////////////////////// archivo
void crear_profesional(profesional _profesional)
{	
	FILE *D;
	D = fopen("Profesional.txt","a+");
	if (D != NULL)
	{
		cout<<"\n\t....:::Creacion exitosa:::....\n\n";
		
		fclose(D);
	}
	else
		cout<<"\n\t~~~~ No se pudo crear el archivo ~~~~\n";

}

//////////////////////////////////////////////////////////Buscar
bool consultar_profesional(profesional _profesional, char aux[9])
{

	system("cls");
	FILE *D;
	bool temp = false;

	D = fopen("Profesional.txt","r"); 
	if (D!= NULL)
	{
		while(!feof(D))
		{
			fread(&_profesional,sizeof(_profesional),1,D);
			
			if (!ferror(D))
			{
				if (!feof(D))
				{
					if(strcmp(aux,_profesional.cod1) == 0)
					{
						temp = true;
						cout<<"\t\t  CONSULTA DEL PROFESIONAL DE SALUD  \n";
						cout<<"\t\t=====================================\n";
							//cout<<"\nColegiatura : ";cin>>_profesional.cod1;
          					cout<<"Nombres : "<<_profesional.nombre;
           					cout<<"\nApellidos : "<<_profesional.apellido;
        					cout<<"\nEdad : "<<_profesional.edad;
            				cout<<"\nSexo [M] o [F] : "<<_profesional.sexo;
        					cout<<"\nProfesion: "<<_profesional.profesion;
        					cout<<"\nEspecialidad: "<<_profesional.especialidad;
        					cout<<"\nRegistro Nacional de Especialista RNE:  "<<_profesional.rne;
        					cout<<"\nDias de Atencion:  "<<_profesional.td;
        					cout<<"\nHorario de atencion: "<<_profesional.th;
							cout<<"\n";
					}
				}
			}
			else
				cout<<"\n\n\t\t\t~~~~ Error de lectura en archivo ~~~~\n\n";
		}
		fclose(D);
	}
	else
		cout<<"\n\n\t\t\t~~~~ No se pudo cargar el archivo ~~~~\n\n";
		
	if (temp == false)
		cout<<"\n\n\t\t\t~~~~ Especialista no registrado ~~~~\n\n";

	return temp;
}	


//////////////////////////////////////////
bool consultar_duplicado_profesional(profesional _profesional, char aux[9])
{
	FILE *D;
	bool temp = true;
	int cont=0;

	D = fopen("Profesional.txt","r"); 
	if (D != NULL)
	{
		while(!feof(D))
		{
			fread(&_profesional,sizeof(_profesional),1,D);
			
			if (!ferror(D))
			{
				if (!feof(D))
				{
					if(strcmp(aux,_profesional.cod1) == 0)
						temp=false;		
					cont++;
				}
			}
			else
				cout<<"\n\n\t\t\t~~~~ Error de lectura en archivo ~~~~\n\n";
		}
		fclose(D);
	}
	else
		cout<<"\n\n\t\t\t~~~~ No se pudo cargar el archivo ~~~~\n\n";

	if (cont == 0)
		temp=true;

	return temp;
}	


//////////////////////////////////////////////////Registrar datos de doctores
void ingresar_profesional(profesional _profesional)
{
	FILE *D;
	system("cls");
	bool temp;
    
	cout<<"\nREGISTRO DEL PROFESIONAL DE SALUD"<<endl;
    cout<<"\n================================="<<endl;
	cout<<"\nA continuacion complete los siguientes datos:\n"<<endl;
	
	fflush(stdin);
	cout<<"\n\t\t\tIngrese el numero Colegiatura: "; cin>>_profesional.cod1;

	temp = consultar_duplicado_profesional(_profesional, _profesional.cod1);
	if (temp)
	{
      	   	cout<<"Nombres : ";cin>>_profesional.nombre;
           	cout<<"Apellidos : ";cin>>_profesional.apellido;
        	cout<<"Edad : ";cin>>_profesional.edad;
            cout<<"Sexo [M] o [F] : ";cin>>_profesional.sexo;
        	cout<<"Profesion: ";cin>>_profesional.profesion;
        	cout<<"Especialidad: ";cin>>_profesional.especialidad;
        	cout<<"Registro Nacional de Especialista RNE: ";cin>>_profesional.rne;
        	cout<<"Dias de Atencion: ";cin>>_profesional.td;
        	cout<<"Horario de atencion: ";cin>>_profesional.th;
        	registrar_profesional( _profesional);
	}
	else
		cout<<"\n\n\t\t\t....::: El Profesional de Salud ya se encuentra registrado :::....\n\n";
    	
}

void registrar_profesional(profesional _profesional)
{	
	FILE *D;
	D = fopen("Profesional.txt","a");

	if (D != NULL)
	{
		fwrite(&_profesional,sizeof(_profesional),1,D); 
			if (!ferror(D))
			{
				cout<<"\n\n\t\t\t....::: Registro exitoso :::....\n\n";
				fclose(D);
			}
			else
				cout<<"\n\n\t\t\t~~~~ Error de escritura en archivo ~~~~\n\n";
	}
	else 
		cout<<"\n\n\t\t\t~~~~ No se puede abrir el archivo ~~~~\n\n"; 	
}

void registrar_temporal_profesional(profesional _profesional)
{	
	FILE *T;
	T = fopen("temp.txt","a");

	if (T != NULL)
	{
		fwrite(&_profesional,sizeof(_profesional),1,T); 
			if (!ferror(T))
				fclose(T);
			else
				cout<<"\n\n\t\t\t~~~~ Error de escritua ~~~~\n\n";
	}
	else 
		cout<<"\n\n\t\t\t~~~~ No se puede abrir el archivo ~~~~\n\n"; 	
}

void modificar_profesional(profesional _profesional, char aux[9]){

	system("cls");
	FILE *D, *TEMP;
	bool temp = false;

	D = fopen("Profesional.txt","r"); 
	if (D != NULL)
	{
		while(!feof(D))
		{
			fread(&_profesional,sizeof(_profesional),1,D);
			
			if (!ferror(D))
			{
				if (!feof(D))
				{
					if(strcmp(aux,_profesional.cod1) == 0)
					{
						temp = true;
						cout<<"\t\t....::::  Campos modificables  ::::...."
							<<"\n\t\t--------------------------------------";
							cout<<"Profesion: ";cin>>_profesional.profesion;
        					cout<<"Especialidad";cin>>_profesional.especialidad;
        					cout<<"Registro Nacional de Especialista RNE: ";cin>>_profesional.rne;
        					cout<<"Dias de Atencion ";cin>>_profesional.td;
        					cout<<"Horario de atencion";cin>>_profesional.th;
							cout<<"\n\t\t--------------------------------------\n";

						registrar_temporal_profesional(_profesional);
					}
					else
						registrar_temporal_profesional(_profesional);
				}
			}
			else
				cout<<"\n\n\t\t\t~~~~ Error de lectura en archivo ~~~~\n\n";
		}
		fclose(D);
		
		remove("Profesional.txt");
        rename("temp.txt","Profesional.txt");
	}
	else
		cout<<"\n\n\t\t\t~~~~ No se pudo cargar el archivo ~~~~\n\n";
		
	if (temp == false)
		cout<<"\n\n\t\t\t~~~~ Especialista no registrado ~~~~\n\n";

}	

void pedir_colegiatura(char aux[9])
{
	fflush(stdin);
	cout<<"\n\t\t\tIngrese el numero Colegiatura: "; 
	cin>>aux;
}


// Validar fecha
bool fecha_valida(int YY, int MM, int DD)
{
	bool valido;

	if ( MM>= 1 && MM <=12 && YY>=2020 && YY<=2030)
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
	if (MM<1 && MM>12 && YY<2020 && YY>2021)
		valido=false;

	return valido;
}

// Confirmacion
bool confirmar()
{
	bool val;
	char r;
	
	do{
		cout<<"\n\t\t\tDesea continuar? (S/N): "; 
		cin>>r;
	}while(r != 'S' && r != 'N' && r != 's' && r != 'n');

	if (r == 'S' || r == 's')
		val = true;
	else
		val = false;	
	
	return val;
}

// Obtener DNI a evaluar
void pedir_DNI(char DNI[])
{
	fflush(stdin);
	cout<<"\n\t\t\tIngrese el numero de DNI: "; 
	cin.getline(DNI,9,'\n');
}

void mensaje_salida()
{
	system("cls");
	cout<<"\n\t............::::::::: FIN DE PROGRAMA :::::::::::............"
		<<"\n\t============================================================="
		<<"\n\tName		:	CLINICA"
		<<"\n\tAuthor		:	@Eber, @Jahir, @Jhon, @Amelia"
		<<"\n\tVersion		:	FINAL"
		<<"\n\tCopyright	:	Gupo 2"
		<<"\n\tDescription	:	Programacion y fundamentos de algoritmica 1"
		<<"\n\t=============================================================\n\n";
	system("pause");
}
