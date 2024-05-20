#include <iostream>
using namespace std;

void LeerVector(int M[100], int d){
	int i;
	for(i=0;i<d;i++){
		cout<<"M["<<(i+1)<<"]=";
    	cin>>M[i];
	}
}  
  
void MostrarVector(int M[100], int d){
	int i;
	for(i=0;i<d;i++){
		cout<<"M["<<(i+1)<<"]: "<<M[i]<<endl;
	}
    cout <<"\n\n";
	       
    
} 

int busbin(int a[100],int d,int nbus){
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
   int n,a[100],i,pos,re,nb;
   cout<<"N = ";
   cin>>n;
   LeerVector(a,n);
   
   MostrarVector(a,n);
   for(;;){
	   
	   cout<<"Ingrese el numero  a buscar : "<<endl;
	   cin>>nb;
	   pos=busbin(a,n,nb);
	   if(pos>=0)
	      cout<<nb<<" Se encontro en la posicion "<<pos+1<<endl;
	   else
	      cout<<nb<<" No esta registrado "<<endl;
	   
	   cout<<"Desea realizar otra busqueda Si (1)  No (0) "<<endl;
	   cin>>re;
       if(re==0)break;
    }
   
   cout<<"FIN DE BUSQUEDA "<<endl;
   cout<<"GRACIAS"<<endl;
   return 0;
}        

