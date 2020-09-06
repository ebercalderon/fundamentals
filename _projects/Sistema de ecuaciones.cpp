#include <iostream>
using namespace std;
int main()
{
//variables
 int opcion,repetir=1;
 float matriz2x3[2][3],matriz3x4[3][4],dets,detx,dety,detz,x,y,z;
 int i,j;
 //Consistencia
 do 
 {
 cout<<"Este programa resuleve sistemas ecuaciones, de 2 y 3 incognitas"<<endl;
 cout<<"Para resolver un sistema de 2 incognitas Presiona 1"<<endl;
 cout<<"Para resolver un sistema de 3 incognitas Presiona 2"<<endl;
 cout<<"Opci\xA2n: ";
 cin>>opcion;
 while(opcion<1||opcion>2)
 {
  cout<<endl<<"Seleccione una opci\xA2n valida"<<endl;
  cout<<"Opci\xA2n: ";
  cin>>opcion;
 }
 system("cls");
 
//Resolviendo utilizando determinantes
 switch(opcion)
 {
  case 1:
  //Solicitar datos
   cout<<"Primera Ecuaci\xA2n: Ingrese los coeficiente de x, y & del termino independiente"<<endl;
   for (i=0;i<1;i++)  //Llenado de matriz
        for (j=0;j<=2;j++)
            cin>>matriz2x3[i][j];cout<<" ";
   cout<<"\nSegunda Ecuaci\xA2n: Ingrese los coeficiente de x, y & del termino independiente"<<endl;
      for (i=1;i<2;i++)  //Llenado de matriz
        for (j=0;j<=2;j++)
            cin>>matriz2x3[i][j];cout<<" ";
   cout<<endl;
   /*
   //Solicitar datos
   cout<<"Primera Ecuaci\xA2n"<<endl<<endl;
   cout<<"Ingrese el coeficiente de x: ";
   cin>>matriz2x3[0][0];
   cout<<endl;
   cout<<"Ingrese el coeficiente de y: ";
   cin>>matriz2x3[0][1];
   cout<<endl;
   cout<<"Ingrese el valor del termino independiente: ";
   cin>>matriz2x3[0][2];
   cout<<endl;
   cout<<"Segunda Ecuaci\xA2n"<<endl<<endl;
   cout<<"Ingrese el coeficiente de x: ";
   cin>>matriz2x3[1][0];
   cout<<endl;
   cout<<"Ingrese el coeficiente de y: ";
   cin>>matriz2x3[1][1];
   cout<<endl;
   cout<<"Ingrese el valor del termino independiente: ";
   cin>>matriz2x3[1][2];
   cout<<endl; 
   */
   
//Determinante del sistema
   dets=(matriz2x3[0][0]*matriz2x3[1][1])-(matriz2x3[0][1]*matriz2x3[1][0]);
//Otras determinantes
   if(dets==0)
   	cout<<"NO TIENE SOLUCION"<<endl;
   else{
	cout<<"Se muestra la determinante del sistema: \n"<<endl;
	for (i=0;i<=1;i++)  //Imprime la determinante del sistema
    {
        for (j=0;j<=1;j++)
        {
            cout<<"	"<<matriz2x3[i][j]<<" ";
        }
        cout<<endl;
    }
	
	cout<<"\nEl resultado de la determinante del sistema es:"<<dets<<endl;
	   detx=(matriz2x3[0][2]*matriz2x3[1][1])-(matriz2x3[0][1]*matriz2x3[1][2]);
	   dety=(matriz2x3[0][0]*matriz2x3[1][2])-(matriz2x3[0][2]*matriz2x3[1][0]);
	   x=detx/dets;
	   y=dety/dets;
	   cout<<"\nSoluci\xA2n: "<<endl;
	   cout<<"\tx="<<x<<endl;
	   cout<<"\ty="<<y<<endl;
	}
   break;
   
  case 2:
  //Solicitar datos
   cout<<"Primera Ecuaci\xA2n: Ingrese los coeficiente de x, y , z, & del termino independiente"<<endl;
   for (i=0;i<1;i++)  //Llenado de matriz 
        for (j=0;j<=3;j++)
            cin>>matriz3x4[i][j];cout<<" ";
   cout<<"\nSegunda Ecuaci\xA2n: Ingrese los coeficiente de x, y , z, & del termino independiente"<<endl;
      for (i=1;i<2;i++)  //Llenado de matriz
        for (j=0;j<=2;j++)
            cin>>matriz3x4[i][j];cout<<" ";
   cout<<"\nTercera Ecuaci\xA2n: Ingrese los coeficiente de x, y , z, & del termino independiente"<<endl;
      for (i=2;i<3;i++)  //Llenado de matriz
        for (j=0;j<=2;j++)
            cin>>matriz3x4[i][j];cout<<" ";
   cout<<endl;
   /*
   //Solicitar datos
   cout<<"Primera Ecuaci\xA2n"<<endl<<endl;
   cout<<"Ingrese el coeficiente de x: ";
   cin>>matriz3x4[0][0];
   cout<<endl;
   cout<<"Ingrese el coeficiente de y: ";
   cin>>matriz3x4[0][1];
   cout<<endl;
   cout<<"Ingrese el coeficiente de z: ";
   cin>>matriz3x4[0][2];
   cout<<endl;
   cout<<"Ingrese el valor del termino independiente: ";
   cin>>matriz3x4[0][3];
   cout<<endl;
   cout<<"Segunda Ecuaci\xA2n"<<endl<<endl;
   cout<<"Ingrese el coeficiente de x: ";
   cin>>matriz3x4[1][0];
   cout<<endl;
   cout<<"Ingrese el coeficiente de y: ";
   cin>>matriz3x4[1][1];
   cout<<endl;
   cout<<"Ingrese el coeficiente de z: ";
   cin>>matriz3x4[1][2];
   cout<<endl;
   cout<<"Ingrese el valor del termino independiente: ";
   cin>>matriz3x4[1][3];
   cout<<endl;
   cout<<"Tercera Ecuaci\xA2n"<<endl<<endl;
   cout<<"Ingrese el coeficiente de x: ";
   cin>>matriz3x4[2][0];
   cout<<endl;
   cout<<"Ingrese el coeficiente de y: ";
   cin>>matriz3x4[2][1];
   cout<<endl;
   cout<<"Ingrese el coeficiente de z: ";
   cin>>matriz3x4[2][2];
   cout<<endl;
   cout<<"Ingrese el valor del termino independiente: ";
   cin>>matriz3x4[2][3];
   cout<<endl;
   */
   
//Determinante del sistema
   dets=(matriz3x4[0][0]*matriz3x4[1][1]*matriz3x4[2][2])+(matriz3x4[1][0]*matriz3x4[2][1]*matriz3x4[0][2])+(matriz3x4[0][1]*matriz3x4[0][2]*matriz3x4[2][0])-(matriz3x4[0][2]*matriz3x4[1][1]*matriz3x4[2][0])-(matriz3x4[1][2]*matriz3x4[2][1]*matriz3x4[0][0])-(matriz3x4[0][1]*matriz3x4[1][0]*matriz3x4[2][2]);
//Otras determinantes
   if(dets==0)
   	cout<<"NO TIENE SOLUCION"<<endl;
   else{
   	cout<<"Se muestra la determinante del sistema: \n"<<endl;
	for (i=0;i<=2;i++)  //Imprime la determinante del sistema
    {
        for (j=0;j<=2;j++)
        {
            cout<<"	"<<matriz3x4[i][j]<<" ";
        }
        printf ("\n");
    }
	   detx=(matriz3x4[0][3]*matriz3x4[1][1]*matriz3x4[2][2])+(matriz3x4[1][3]*matriz3x4[2][1]*matriz3x4[0][2])+(matriz3x4[0][1]*matriz3x4[1][2]*matriz3x4[2][3])-(matriz3x4[0][2]*matriz3x4[1][1]*matriz3x4[2][3])-(matriz3x4[1][2]*matriz3x4[2][1]*matriz3x4[0][3])-(matriz3x4[0][1]*matriz3x4[1][3]*matriz3x4[2][2]);
	   dety=(matriz3x4[0][0]*matriz3x4[1][3]*matriz3x4[2][2])+(matriz3x4[1][0]*matriz3x4[2][3]*matriz3x4[0][2])+(matriz3x4[0][3]*matriz3x4[1][2]*matriz3x4[2][0])-(matriz3x4[0][2]*matriz3x4[1][3]*matriz3x4[2][0])-(matriz3x4[1][2]*matriz3x4[2][3]*matriz3x4[0][0])-(matriz3x4[0][3]*matriz3x4[1][0]*matriz3x4[2][2]);
	   detz=(matriz3x4[0][0]*matriz3x4[1][1]*matriz3x4[2][3])+(matriz3x4[1][0]*matriz3x4[2][1]*matriz3x4[0][3])+(matriz3x4[0][1]*matriz3x4[1][3]*matriz3x4[2][0])-(matriz3x4[0][3]*matriz3x4[1][1]*matriz3x4[2][0])-(matriz3x4[1][3]*matriz3x4[2][1]*matriz3x4[0][0])-(matriz3x4[0][1]*matriz3x4[1][0]*matriz3x4[2][3]);
	   x=detx/dets;
	   y=dety/dets;
	   z=detz/dets;
	   cout<<"\nSoluci\xA2n: "<<endl;
	   cout<<"\tx="<<x<<endl;
	   cout<<"\ty="<<y<<endl;
	   cout<<"\tz="<<z<<endl;
	}
   break;
 }
 cout<<"\nPara realizar otro calculo presione 1, para salir presione 0"<<endl;
 cout<<"Opci\xA2n: ";
 cin>>repetir;
 while (repetir<0||repetir>1)
 {
  cout<<endl<<"Ingrese una opci\xA2n valida"<<endl;
  cout<<"Opci\xA2n: ";
  cin>>repetir;
 }
 system("cls");
 }while(repetir==1);
}
