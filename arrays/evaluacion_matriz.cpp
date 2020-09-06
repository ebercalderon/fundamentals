#include<iostream>
#include<iomanip>
using namespace std;

//PROTOTIPOS
void llenar_datos(int[][3],int);
void asignar_salones(int[][3],int,int[][5]);
void imprimir(int[][3],int);

//MAIN
int main()
{
	//SALONES QUE HAY EN EL EDIFICIO
	int n,salones[3][5]={{30,30,15,30,40},{25,30,25,10,110},{62,30,40,40,30}};  //salones[piso-1][numero]
	//LISTADO DE CURSOS
	cout<<"Digite el numero de cursos que se va a dictar: ";cin>>n;
	int cursos[n][3];  //cursos[][0]:codigo , cursos[][1]:tamaño , cursos[][2]:salon asignado
	llenar_datos(cursos,n);
	asignar_salones(cursos,n,salones);
	imprimir(cursos,n);
		
	return 0;
}

//SUBPROGRAMAS
void llenar_datos(int matriz[][3],int nfil)
{
	int contador=1;
	for(int i=0;i<nfil;i++)
	{
		cout<<endl;
		cout<<"Digite el codigo del curso "<<contador<<" : ";cin>>matriz[i][0];
		cout<<"Digite el tamanio del curso "<<contador<<" : ";cin>>matriz[i][1];
		matriz[i][2]=-1;  //El valor -1 representa que no tiene un salon asignado
		contador++;
	}
}

void asignar_salones(int cursos[][3],int nfil,int salones[][5])
{
	for(int t=0;t<nfil;t++)
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<5;j++)
			{
				if(cursos[t][2]==-1)  //Si el curso no tiene ningun salon asignado
				{
					if(cursos[t][1]<=salones[i][j]) //Si el tamaño del curso es menor o igual que el salon
					{
						cursos[t][2]=(i+1)*100+j;
					}
				}
				else  //Si el curso ya tiene asignado un salon 
				{
					if(cursos[t][1]<=salones[i][j] && salones[i][j]<salones[(cursos[t][2]/100)-1][cursos[t][2]%10])
					//Si el tamaño del curso es menor o igual que el salon Y el tamaño del salon actual es menor que el tamaño del salon ya asignado 
					{	
						cursos[t][2]=(i+1)*100+j;
					}	
				}
			}
		}
		salones[(cursos[t][2]/100)-1][cursos[t][2]%10]=-1; //Si salones[][]=-1 significa que este salon ya fue asignado
	}
}

void imprimir(int cursos[][3],int nfil)
{
	cout<<setw(14)<<"CURSO"<<setw(14)<<"CODIGO"<<setw(14)<<"TAMAÑO"<<setw(14)<<"SALON"<<endl;
	for(int i=0;i<nfil;i++)
	{
		cout<<setw(14)<<i+1<<setw(14)<<cursos[i][0]<<setw(14)<<cursos[i][1];
		if(cursos[i][2]==-1)
		{
			cout<<setw(14)<<"NO ASIGNADO";
		}
		else
		{
			cout<<setw(14)<<cursos[i][2];
		}
		cout<<endl;
	}
}
