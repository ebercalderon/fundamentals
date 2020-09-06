
#include <iostream>
#include <fstream> // Ficheros

using namespace std;

int main()
{
    int cedula,opcion,Bcedula,edad,telefono,Ntelefono,Nedad;
    char nombre[10],apellido[10];
    ofstream Guardar;
    ifstream Leer;
    ofstream Temp; // Referencia aun archivo temporal
    
    do
    {
        system("cls");
        cout<<"\n\t\t\t=========================="
		    <<"\n\t\t\t....:::: FICHEROS ::::...."
    	    <<"\n\t\t\t==========================\n\n"
            <<"\n\t\t\t[1] GUARDAR"
    	    <<"\n\t\t\t[2] LEER"
    	    <<"\n\t\t\t[3] BUSCAR"
            <<"\n\t\t\t[4] MODIFICAR"
    	    <<"\n\t\t\t[5] ELIMINAR"
    	    <<"\n\n\n\t\t\t\t\t|| [6] Salir ||\n\n";
        
        do{
		    cout<<"\n\t\t\tDigite opcion [ ]\b\b";
		    cin>>opcion;
        }while(opcion < 1 || opcion > 6);

        switch(opcion)
        {
            case 1:
                {
                    system("cls");
                    Guardar.open("Fichero.txt",ios::app);
                    cout<<"Ingrese Nombre: ";
                    cin>>nombre;
                    cout<<"Ingrese Apellido: ";
                    cin>>apellido;
                    cout<<"Ingrese la Edad en anos: ";
                    cin>>edad;
                    cout<<"Ingrese Numero de Telefono: ";
                    cin>>telefono;
                    cout<<"Ingrese su numero de cedula: ";
                    cin>>cedula;
                    Guardar<<nombre<<" "<<apellido<<" "<<edad<<" "<<telefono<<" "<<cedula<<endl;
                    Guardar.close();
                    break;
                }
            case 2:
                {
                    system("cls");  
                    Leer.open("Fichero.txt");
                    Leer>>nombre>>apellido>>edad>>telefono;
                    while(!Leer.eof())
                    {
                        Leer>>cedula;
                        cout<<"----------------------------"<<endl;
                        cout<<"Nombre:    "<<nombre<<endl;
                        cout<<"Apellido:  "<<apellido<<endl;
                        cout<<"Edad:      "<<edad<<" anios"<<endl;
                        cout<<"Telefono:  "<<telefono<<endl;
                        cout<<"Cedula:    "<<cedula<<endl;
                        cout<<"----------------------------"<<endl;
                        cout<<endl;
                        Leer>>nombre>>apellido>>edad>>telefono;
                    }
                    Leer.close();
                    break;
                }
            case 3:
                {
                    system("cls");  
                    Leer.open("Fichero.txt");
                    Leer>>nombre>>apellido>>edad>>telefono;
                    bool encontrado=false;
                    cout<<"Ingrese su numero de cedula para buscar"<<endl;
                    cin>>Bcedula;
                    while(!Leer.eof())
                    {
                        Leer>>cedula;
                        if(cedula==Bcedula)
                        {
                            encontrado=true;
                            cout<<"----------------------------"<<endl;
                            cout<<"Nombre:    "<<nombre<<endl;
                            cout<<"Apellido:  "<<apellido<<endl;
                            cout<<"Edad:      "<<edad<<" anio"<<endl;
                            cout<<"Telefono:  "<<telefono<<endl;
                            cout<<"Cedula:    "<<cedula<<endl;
                            cout<<"----------------------------"<<endl;
                            cout<<endl;
                        }
                        Leer>>nombre>>apellido>>edad>>telefono;
                    }
                    if(encontrado==false)
                    {
                        cout<<"Cedula no encontrada"<<endl;
                    }
                    Leer.close();
                    break;
                }

            case 4:
                {
                    system("cls");  
                    Leer.open("Fichero.txt");//abre fichero original
                    Temp.open("Temp.txt");//abrimos el temporal tambn
                    Leer>>nombre>>apellido>>edad>>telefono;
                    bool encontrado=false;
                    cout<<"Ingrese clave a modificar"<<endl;
                    cin>>Bcedula;
                    while(!Leer.eof())
                    {
                        Leer>>cedula;
                        if(cedula==Bcedula)
                        {
                            encontrado=true;
                            cout<<"Nombre:    "<<nombre<<endl;
                            cout<<"Apellido:  "<<apellido<<endl;
                            cout<<"Edad :     "<<edad<<" anios"<<endl;
                            cout<<"Telefono:  "<<telefono<<endl;
                            cout<<"Cedula:    "<<cedula<<endl;
                            cout<<endl;
                            cout<<"Ingrese su Edad a modificar"<<endl;
                            cin>>Nedad;
                            cout<<"Ingrese nuevo numero de telefono"<<endl;
                            cin>>Ntelefono;
                            Temp<<nombre<<" "<<apellido<<" "<<Nedad<<" "<<Ntelefono<<" "<<cedula<<endl;
                            cout<<endl;
                            cout<<"Modificado"<<endl;
                        }
                        else
                        {
                            Temp<<nombre<<" "<<apellido<<" "<<edad<<" "<<telefono<<" "<<cedula<<endl;
                        }
                        Leer>>nombre>>apellido>>edad>>telefono;
                    }
                    if(encontrado==false)
                    {
                        cout<<"Cedula no encontrada"<<endl;
                    }
                    
                    Leer.close();
                    Temp.close();
                    //if (rename("Temp.txt", "Fichero.txt") == 0)
		            //        perror("Error renaming file");
	                //else
		            //    cout << "File renamed successfully";
                    remove("Fichero.txt");
                    rename("Temp.txt","Fichero.txt");
                    break;
                }

            case 5:
                {
                    system("cls");
                    Leer.open("Fichero.txt");
                    Temp.open("Temp.txt");
                    Leer>>nombre>>apellido>>edad>>telefono;
                    bool encontrado=false;
                    cout<<"Ingrese clave a eliminar"<<endl;
                    cin>>Bcedula;
                    while(!Leer.eof())
                    {
                        Leer>>cedula;
                        if(cedula==Bcedula)
                        {
                            encontrado=true;
                            cout<<"Nombre:    "<<nombre<<endl;
                            cout<<"Apellido:  "<<apellido<<endl;
                            cout<<"Edad:      "<<edad<<endl;
                            cout<<"Telefono:  "<<telefono<<endl;
                            cout<<"Cedula:    "<<cedula<<endl;
                            cout<<endl;
                            cout<<"Eliminado"<<endl;
                        }
                        else
                        {
                            Temp<<nombre<<" "<<apellido<<" "<<edad<<" "<<telefono<<" "<<cedula<<endl;
                        }
                        Leer>>nombre>>apellido>>edad>>telefono;
                    }
                    if(encontrado==false)
                    {
                        cout<<"Clave no encontrada"<<endl;
                    }
                    Leer.close();
                    Temp.close();
                    remove("Fichero.txt");
                    rename("Temp.txt","Fichero.txt");

                    break;
                }

            case 6:
                {
                    system("cls");

                    break;
                }

        }
        system("pause");   
    }while(opcion!=6);
    return 0;
}