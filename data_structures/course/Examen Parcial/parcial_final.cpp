#include<iostream>
using namespace std;
int main(){
	
	struct producto{
		string nombre;
		int cantidad;
		float precio;	
		float tienda1;
		float tienda2;
		float tienda3;
	};typedef producto tproducto;
	
	int x;
	tproducto p1,p2,p3,p4; // las variables p1 y p2 tienen tres campos nombre, cantidad y peso.
	p1.nombre="Cafe";
	p1.precio=9.5;
	p1.tienda1=245;
	p1.tienda2=423;
	p1.tienda3=121;
	
	p2.nombre="Yogurt";
	p2.precio=10.5;
	p2.tienda1=445;
	p2.tienda2=380;
	p2.tienda3=225;
	
	p3.nombre="Leche";
	p3.precio=5.5;
	p3.tienda1=245;
	p3.tienda2=238;
	p3.tienda3=321;
	
	p4.nombre="Gaseosa";
	p4.precio=4.5;
	p4.tienda1=324;
	p4.tienda2=123;
	p4.tienda3=221;
	
	tproducto cab[5];
	cab[0].nombre="Producto";
	cab[1].nombre="Precio";
	cab[2].nombre="Tienda 1";
	cab[3].nombre="Tienda 2";
	cab[4].nombre="Tienda 3";
	
	
	cout<<cab[0].nombre<<"|"<<cab[1].nombre<<"|"<<cab[2].nombre<<"|"<<cab[3].nombre<<"|"<<cab[4].nombre<<endl;
	cout<<p1.nombre<<"|"<<p1.precio<<"|"<<p1.tienda1<<"|"<<p1.tienda2<<"|"<<p1.tienda3<<endl;
	cout<<p2.nombre<<"|"<<p2.precio<<"|"<<p2.tienda1<<"|"<<p2.tienda2<<"|"<<p2.tienda3<<endl;
	cout<<p3.nombre<<"|"<<p3.precio<<"|"<<p3.tienda1<<"|"<<p3.tienda2<<"|"<<p3.tienda3<<endl;
	cout<<p4.nombre<<"|"<<p4.precio<<"|"<<p4.tienda1<<"|"<<p4.tienda2<<"|"<<p4.tienda3<<endl;
	//arreglo de estructura
	
	cout<<""<<endl;
	if(p1.tienda1>p1.tienda2 && p1.tienda1>p1.tienda3)
		cout<<"Se observa que en la Tienda 1 se vendio mas cantidad de "<<p1.nombre;
	else 
	if(p1.tienda2>p1.tienda1 && p1.tienda2>p1.tienda3)
		cout<<"Se observa que en la Tienda 2 se vendio mas cantidad de "<<p1.nombre;
	else
		cout<<"Se observa que en la Tienda 3 se vendio mas cantidad de "<<p1.nombre;
	
	cout<<""<<endl;		
	if(p2.tienda1>p2.tienda2 && p2.tienda1>p2.tienda3)
		cout<<"Se observa que en la Tienda 1 se vendio mas cantidad de "<<p2.nombre;
	else 
	if(p2.tienda2>p2.tienda1 && p2.tienda2>p2.tienda3)
		cout<<"Se observa que en la Tienda 2 se vendio mas cantidad de "<<p2.nombre;
	else
		cout<<"Se observa que en la Tienda 3 se vendio mas cantidad de "<<p2.nombre;
		
	cout<<""<<endl;		
	if(p3.tienda1>p3.tienda2 && p3.tienda1>p3.tienda3)
		cout<<"Se observa que en la Tienda 1 se vendio mas cantidad de "<<p3.nombre;
	else 
	if(p3.tienda2>p3.tienda1 && p3.tienda2>p3.tienda3)
		cout<<"Se observa que en la Tienda 2 se vendio mas cantidad de "<<p3.nombre;
	else
		cout<<"Se observa que en la Tienda 3 se vendio mas cantidad de "<<p3.nombre;	
	
	cout<<""<<endl;		
	if(p4.tienda1>p4.tienda2 && p4.tienda1>p4.tienda3)
		cout<<"Se observa que en la Tienda 1 se vendio mas cantidad de "<<p4.nombre;
	else 
	if(p4.tienda2>p4.tienda1 && p4.tienda2>p4.tienda3)
		cout<<"Se observa que en la Tienda 2 se vendio mas cantidad de "<<p4.nombre;
	else
		cout<<"Se observa que en la Tienda 3 se vendio mas cantidad de "<<p4.nombre;
			
}
