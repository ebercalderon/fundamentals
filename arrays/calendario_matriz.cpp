#include<iostream>
#include<iomanip>
using namespace std;

void iniciar_matriz(int[][7],int,int);
void llenar_matriz(int[][7],int,int,int,int);
void Calendario(int[],string,int,int[][7]);

int main()
{
	int dias[]={31,28,31,30,31,30,31,31,30,31,30,31};
	int calendario[6][7];
	int mes;
	string prim_dia;
	cout<<"Digite el numero del mes del calendario: ";cin>>mes;
	cout<<"Digite el dia de la semana en el que comienza el mes (en minuscula): ";cin>>prim_dia;
	cout<<endl<<endl;
	
	iniciar_matriz(calendario,6,7);
	Calendario(dias,prim_dia,mes,calendario);
	
	cout<<setw(11)<<"Lunes";
	cout<<setw(11)<<"Martes";
	cout<<setw(11)<<"Miercoles";
	cout<<setw(11)<<"Jueves";
	cout<<setw(11)<<"Viernes";
	cout<<setw(11)<<"Sabado";
	cout<<setw(11)<<"Domingo"<<endl;
	
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<7;j++)
		{
			cout<<setw(11)<<calendario[i][j];
		}
		cout<<endl;
	}
	
	return 0;
}

void iniciar_matriz(int matriz[][7],int nf,int nc)
{
	for(int i=0;i<nf;i++)
	{
		for(int j=0;j<nc;j++)
		{
			matriz[i][j]=0;
		}
	}
}

void Calendario(int dias[],string dia,int mes,int calendario[][7])
{
	int cantidad_dias=dias[mes-1],inicio,numeracion=1;
	bool prim_semana=true;
	if(dia=="lunes")inicio =0;
	if(dia=="martes")inicio =1;
	if(dia=="miercoles")inicio =2;
	if(dia=="jueves")inicio =3;
	if(dia=="viernes")inicio =4;
	if(dia=="sabado")inicio =5;
	if(dia=="dommingo")inicio =6;
	
	for(int i=0;i<6;i++)
	{
		
		if(prim_semana==true)
		{
			for(int j=inicio;j<7;j++)
			{
				calendario[i][j]=numeracion;
				numeracion++;
			}
			prim_semana=false;	
		}
		else
		{
			for(int j=0;j<7;j++)
			{
				calendario[i][j]=numeracion;
				numeracion++;
				if(numeracion>cantidad_dias)
				{
					break;
				}
			}
		}
		if(numeracion>cantidad_dias)
		{
			break;
		}
	}
}
