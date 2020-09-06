//librerias
#include<iostream>
#include<iomanip>
using namespace std;

//Prototipos
int sistema();
int matricula(int op);
void cupos();
int c1=5, c2=6, c3=3, c4=4, c5=3, cont=0;


//Funcion principal
int main(){
	// declaracion de variables locales
	system("color F0");
	int opcion, ciclo;	
	do{
		opcion=sistema();
		
		switch (opcion)
        {
			case 1:
                do{
                    do{	
                    	system("cls");
                        cout<<"Cursos matriculados: "<<cont<<endl;
                        cout<<"(Max. 3 cursos por estudiante, presione 0 para terminar)"<<endl;
                        cout<<"\nDigite semestre a matricular: ";
                        cin>>ciclo;
                    }while(ciclo<0|| ciclo>2);
                    matricula(ciclo);
                }while(cont!=3 && ciclo!=0);
                cout<<"Usted se matriculo en: "<<cont<<" cursos"<<endl;
                cout<<"MATRICULA FINALIZADA"<<endl;
                cont=0;
                break;
			case 2:
				cupos();
				break;
		}
		system("pause");
		system("cls");
	}while(opcion!=3);
	cout<<" FIN DE PROGRAMA "<<endl;
	return 0;
}

int sistema(){
	int op;
	// MENU
	cout<<"\t\t\t\tSISTEMA DE MATRICULA"<<endl; 
	cout<<"\t\t\t\t===================="<<endl;
	cout<<"\t\t[1] : Iniciar matricula"<<endl;
	cout<<"\t\t[2] : Ver cupos por cursos"<<endl;
	cout<<"\t\t[3] : Salir del sistema"<<endl;
	do{
		cout<<"Ingrese una opcion  [ ]"<<"\b\b";
		cin>>op;
		if(op<1 ||op >3)
			cout<<"***Opcion errada***"<<endl;
	}while(op<1 ||op>3);
    system("cls");
	return op;
}

int matricula(int op){
    int a=0, b=0, c=0;
    system("cls");
    int mat;
    switch (op)
    {
        case 1:
            cout<<"Escoga curso a matricular para el  primer semestre: "<<endl;
            cout<<"\nPara retroceder presione 0"<<endl<<endl;
            cout<<"\t\t[1] : Algoritmica I"<<endl;
            cout<<"\t\t[2] : Matematica 1"<<endl;
            do{
                do{
                cout<<"\nIngrese un curso  [ ]"<<"\b\b";
                cin>>mat;
                }while(mat<0 || mat>2);

                if(cont==3)
                    mat=0;  
                if(mat==1){
                    if(a==0 && c1>0){
                        c1--; 
                        a++;
                        cont++;
                        cout<<"Matricula en el curso realizada"<<endl;
                    }else{
                        if(a!=0)
                            cout<<"Ya se matriculo en el curso :)"<<endl;
                        else if(c1<=0)
                        		cout<<"Ya no hay vacantes :("<<endl;
                    }   
                } 
                if(mat==2){
                    if(b==0 && c2>0){
                        c2--; 
                        b++;
                        cont++;
                        cout<<"Matricula en el curso realizada"<<endl;
                    }else{
                        if(b!=0)
                            cout<<"Ya se matriculo en el curso :)"<<endl;
                        else if(c2<=0)
                        		cout<<"Ya no hay vacantes :("<<endl;
                    }   
                }
      
            }while(mat!=0 && cont!=3);
        	if(cont==3 )system("pause");
        break;
                    
        case 2:
            cout<<"Escoga curso a matricular para el  segundo semestre: "<<endl;
            cout<<"\nPara retroceder presione 0"<<endl<<endl;
            cout<<"\t\t[1] : Algoritmica II"<<endl;
            cout<<"\t\t[2] : Matematica 2"<<endl;
            cout<<"\t\t[3] : Electivo 1"<<endl;
            do{
                do{
                cout<<"\nIngrese un curso  [ ]"<<"\b\b";
                cin>>mat;
                }while(mat<0 && mat>3);
                
                if(cont==3)
                    mat=0; 
                if(mat==1){
                    if(a==0 && c3>0){
                        c3--; 
                        a++;
                        cont++;
                        cout<<"Matricula en el curso realizada"<<endl;
                    }else{
                        if(a!=0)
                            cout<<"Ya se matriculo en el curso :)"<<endl;
                        else if(c3<=0)
                        		cout<<"Ya no hay vacantes :("<<endl;
                    }    
                }
                if(mat==2){
                    if(b==0 && c4>0){
                        c4--; 
                        b++;
                        cont++;
                        cout<<"Matricula en el curso realizada"<<endl;
                    }else{
                        if(b!=0)
                            cout<<"Ya se matriculo en el curso :)"<<endl;
                        else if(c4<=0)
                        		cout<<"Ya no hay vacantes :("<<endl;
                    }    
                }       
                if(mat==3){
                    if(c==0 && c5>0){
                        c5--; 
                        c++;
                        cont++;
                        cout<<"Matricula en el curso realizada"<<endl;
                    }else{
                        if(c!=0)
                            cout<<"Ya se matriculo en el curso :)"<<endl;
                        else if(c5<=0)
                        		cout<<"Ya no hay vacantes :("<<endl;
                    } 
                }
            }while(mat!=0 && cont!=3);
            if(cont==3 )system("pause");
       	break;
           
    } 
    return op;
}
void cupos(){
	cout<<setw(21)<<"I Semestre"<<setw(27)<<"II Semestre"<<endl;
	cout<<setw(21)<<" =========="<<setw(27)<<"==========="<<endl;
	cout<<setw(20)<<"Algoritmica I: "<<c1<<setw(25)<<"ALgoritmica II: "<<c3<<endl;
	cout<<setw(20)<<"Matematica 1:  "<<c2<<setw(25)<<"Matematica 2:   "<<c4<<endl;
	cout<<setw(46)<<"Electivo 1:     "<<c5<<endl;
}

