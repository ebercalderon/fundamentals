//*************************************************
//   	OPERACIONES SOBRE LISTAS ENLAZADAS DOBLES
//
//**************************************************
#include <iostream>

using namespace std;
struct nodo{
			int dato;
			struct nodo *ant;	
			struct nodo *sgte;	
};

typedef struct nodo *TpLista;// crea un tipo de dato struct nodo



void menu(){
	system("CLS");
	cout<<"\tOpciones de Listas"<<endl<<endl;
	cout<<"1.- Insertar al Inicio"<<endl;
	cout<<"2.- Insertar al Final"<<endl;
	cout<<"3.- Insertar en una posicion"<<endl;
	cout<<"4.- Mostrar Lista"<<endl;
	cout<<"5.- Eliminar al Inicio"<<endl;
	cout<<"6.- Eliminar al Final"<<endl;
	cout<<"7.- Eliminar de una posicion"<<endl;
	cout<<"8.- Reemplazar los datos segun valor"<<endl;	
	cout<<"0 Salir"<<endl;
	cout<<"Ingrese Opcion --> ";
}
//*********** Ingreso de dato *****
int IngresaValor(){
	int v1;
	system("CLS");
	do{
		cout<<"Ingresar valor del nodo --->";
		cin>>v1;
	}while(v1<=0);
	cout<<endl;
	return v1;		
}

//*********** Crea NODO y asigna valor*****
TpLista CreaNodo(int valor){
	TpLista q= new(struct nodo);
    q->dato=valor;
    q->ant=NULL;
    q->sgte=NULL;
    return q;
}
//*********** Inserta NODO al inicio de la LIsta *****
void InsertarInicio(TpLista &inicio){
	int a;
	TpLista r=NULL;
	a= IngresaValor();
	r = CreaNodo(a);
	if(inicio ==NULL)
		inicio=r;
	else{
		r->sgte=inicio;
		inicio->ant=r;
    	inicio=r;
	}
	
}
	//*********** Inserta NODO al FINAL de la LIsta *****
void InsertarFinal(TpLista &inicio){
    TpLista p=inicio, r=NULL;
    int a;
    a= IngresaValor();
	r = CreaNodo(a);
	if(inicio ==NULL)
		inicio=r;
	else{
	
    	while(p->sgte!=NULL)
    		p=p->sgte;
    
		p->sgte=r;
		r->ant=p;
	}
}
//******* Insertar pos Posicion ***************
void InsertarPosicion(TpLista &inicio, int n){
	
	TpLista r=NULL, p=inicio,q;
	int c=1, a;
	a= IngresaValor();
	q = CreaNodo(a);

	while(c != n){
		r=p;
 		p = p->sgte;
		c=c+1;
	}

	p->ant=q;
	q->ant=p->ant->sgte;
	p->ant->sgte=q;	
	q->sgte=p;
		
}

//******* IMPRIME LISTA *********
void MostrarLista(TpLista inicio){
	system("CLS");
	TpLista temp=inicio, t2;
    cout<<endl;
    cout<<"Recorrido de Lista Inicio a Final "<<endl<<endl;
    while(temp != NULL){
       
        cout<<temp->dato<<" - ";
        t2=temp;
        temp=temp->sgte;
       }
    cout<<endl;
    cout<<"Recorrido de Lista Final a Inicio"<<endl<<endl;
    temp=t2;
	while(temp != NULL){
       
        cout<<temp->dato<<" - ";
        temp=temp->ant;
       }
    cout<<endl;
    system("pause");
	
}

//********** ELIMINAR AL INICIO ******
void EliminarInicio(TpLista &inicio){
	TpLista  p=inicio;
	inicio=inicio->sgte;
	inicio->ant=NULL;
	cout<<"El nodo eliminado es--> "<<p->dato<<endl;
	system("pause");
	delete(p);
	MostrarLista(inicio);
}
//***** ELIMINAR AL FINAL ****************
void EliminarFinal(TpLista &inicio){
	TpLista p=inicio;
	while(p->sgte != NULL){
		p=p->sgte;
	}
	p->ant->sgte=NULL;
	cout<<"El nodo eliminado es--> "<<p->dato<<endl;;
	system("pause");
	delete(p);
	MostrarLista(inicio);
}
//******* 	ELIMINAR UN NODO POR POSICION **********
void EliminarPosicion(TpLista &inicio, int n){
	TpLista p=inicio, r=NULL;
	int c=1;
	bool sw=false;
	while(p->sgte !=NULL && c != n){
		p=p->sgte;
		c++;
		if(c==n)
			sw=true;
		}//while
		
	if(sw==false){
		cout<<"\nPosicion Ingresada No es Valida..."<<endl;
		system("pause");	
	}	
	else{
		p->ant->sgte= p->sgte;
		p->sgte->ant= p->ant;
		cout<<"El nodo eliminado es--> "<<p->dato<<endl;;
		system("pause");
		delete(p);
		MostrarLista(inicio);
		
	}
			
}
//********** Modificacion

void ModificarValor(TpLista inicio, int nuevo, int buscar){
	TpLista p=inicio;
	bool sw=false;
	while(p != NULL){
		if(p->dato == buscar){
			sw=true;
			p->dato=nuevo;
			}
		p=p->sgte;
	}
	if(sw==false){
		cout<<"Error... No hay Nodos con el valor buscado..."<<buscar<<endl;
		system("pause");
	}else
		MostrarLista(inicio);
}


//******* FUNCION MAIN ************
int main() {
	int a, pos, buscar, nuevo;
	TpLista inicio=NULL;
	TpLista n=NULL;
	int opc;
	do{
	
	menu();
	cin>>opc;
	switch(opc){
		case 1:
			InsertarInicio(inicio);
			break;
		case 2:
			InsertarFinal(inicio);
			break;
		case 3:
			cout<<"Ingresar posicion ---> ";cin>>pos;
			cout<<endl;
			InsertarPosicion(inicio, pos);
			break;
		case 4:
			MostrarLista(inicio);
			break;
		case 5:
			EliminarInicio(inicio);
			break;									
		case 6:
			EliminarFinal(inicio);
			break;			
		case 7:
			cout<<"Ingresar posicion ---> ";cin>>pos;
			cout<<endl;
			EliminarPosicion(inicio, pos); 
			break;
		case 8:
			cout<<"Ingresar el valor a Buscar-----> ";cin>>buscar;
			cout<<"Ingresar el valor a Reemplazar-> ";cin>>nuevo;
			ModificarValor(inicio, nuevo, buscar);
			break;
		case 0:	
			break;	
	}
	
} while(opc!=0);
	
	return 0;
}
