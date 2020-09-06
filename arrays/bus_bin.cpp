#include <iostream>
#include <conio.h>
#define dim 1000
using namespace std;

void LeerVector(int M[dim], int d){
	int i;
	for(i=0;i<d;i++){
		cout<<"M["<<(i+1)<<"]=";
    	cin>>M[i];
	}
  }
  
  
void MostrarVector(int M[dim], int d){
	int i;
	for(i=0;i<d;i++){
		cout<<"M["<<(i+1)<<"]: "<<M[i]<<endl;
	}
    cout <<"\n\n";
	system("pause");       
    
} 

int busbin(int a[dim],int d,int nbus){
	int i,p,u,c;
    p=0;
    u=d;
	
	while(p<=u){
		c=(p+u)/2;
		if( a [c]==nbus)
	      return c;
		else{
			if(nbus> a [c])
				p=c+1;	
			else	
				u=c-1;
		}
	}
   return -1; 
}
  
int main(){
   int n,a[dim],i,pos,re,nb;
   cout<<"N = ";
   cin>>n;
   LeerVector(a,n);
   system("cls");
   MostrarVector(a,n);
   for(;;){
	   system("cls");
	   cout<<"Ingrese el numero  a buscar : "<<endl;
	   cin>>nb;
	   pos=busbin(a,n,nb);
	   if(pos>=0)
	      cout<<nb<<" Se encontro en la posicion "<<pos+1<<endl;
	   else
	      cout<<nb<<" No esta registrado "<<endl;
	   getche();
	   cout<<"Desea realizar otra busqueda Si (1)  No (0) "<<endl;
	   cin>>re;
       if(re==0)break;
    }
   system("cls");
   cout<<"FIN DE BUSQUEDA "<<endl;
   cout<<"GRACIAS"<<endl;
   getche();
   return 0;
}        

