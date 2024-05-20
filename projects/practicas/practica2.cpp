#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <string.h>
#include <iostream>

using namespace std;

// Constante
const int LIM = 64;

// variables globales
int codigo[LIM];
string nombre[LIM];
string tipo[LIM];
string ubicacion[LIM];
double precio[LIM];
string servicio[LIM];
string cliente[LIM];
int indice = 0;
int numero = 10;

/** listaServicios
 * Muestra todos las mascotas registradas, asi como cuantas mascotas estan 
 * en Casa y cuantos en Clinica
 **/
void listaServicios()
{
    int casa = 0, clinica = 0; 
    cout << endl << setw(15) << "Codigo" << setw(15) << "Mascota" << setw(15) << "Tipo" << setw(15)	<< "Ubicacion" << setw(15) << "Precio" << setw(15) << "Servicio" << setw(15) << "Cliente";
    for (int i = 0; i < indice; i++)
    {
        cout << endl << setw(15) << codigo[i] << setw(15) << nombre[i] << setw(15) << tipo[i] << setw(15) << ubicacion[i] << setw(15) << precio[i] << setw(15) << servicio[i] << setw(15) << cliente[i];
        if (ubicacion[i] == "casa")
            casa++;
        else 
            clinica++;
    }

    cout << "\n\nCantidad de mascotas en la Clinica: " << clinica;
    cout << "\nCantidad de mascotas en la Casa: " << casa;
}

/** nuevaMascota
 * Crea una nueva mascota grabando los valores en todos los arreglos, para 
 * lo cual creara el codigo (numero) con el que sigue a la ultima mascota 
 * creada y los parametros recibidos. Si no se puede agregar mas mascotas 
 * (se excede la capacidad del arreglo) se retorna false, si puede grabar 
 * los datos en los arreglos retorna true. Por defecto tendra ubicacion 
 * Casa y Servicio en Blanco
 **/
bool nuevaMascota()
{
    char opc;

    if (indice < LIM){
        codigo[indice] = numero;
        cout << "\nDigite el nombre: ";
        cin >> nombre[indice];

        cout << "\np. perro";
        cout << "\ng. gato";
        cout << "\nl. loro";
        do
        {
            cout << "\nDigite el tipo: ";
            cin >> opc;
        } while (opc != 'p' && opc != 'g' && opc != 'l');

        switch (opc)
        {
        case 'p':
            tipo[indice] = "perro";
            break;
        case 'g':
            tipo[indice] = "gato";
            break;
        case 'l':
            tipo[indice] = "loro";
            break;
        
        }

        ubicacion[indice] = "casa";
        precio[indice] = 0;
        servicio[indice] = " ";

        numero++;
        indice++;

        return true;
    }
    
    return false;
}

/** terminaServicio
 * Tras pedir al usuario un codigo de masota, debera validar si se 
 * puede terminar el servicio segun las reglas explicadas anteriormente, 
 * si no se puede retorna false, si es que se puede retorna true y hace 
 * el cambio de estado a Local y le borra el nombre del Cliente al arreglo 
 * correspondiente.
 **/
bool terminaServicio()
{
    int id;
    bool terminar = false;

    cout << "\nDigite el codigo: ";
    cin >> id;

    for (int i = 0; i < indice; i++)
    {
        if (codigo[i] == id)
        {
            if (ubicacion[i] == "clinica")
            {
                terminar = true;
                id = i;
            }
        }  
    }

    if (terminar){
        cliente[id] = " ";
        servicio[id] = " ";
        precio[id] = 0;
        ubicacion[id] = "casa";

        return true;
    }
    
    return false;
}

/** nuevoServicio
 * Tras pedir al usuario un codigo de mascota y un nombre de Cliente, 
 * deberá validar si se puede asignar un servicio a la mascota segun 
 * las reglas explicadas, si no se puede retorna false, si es que se 
 * puede retorna true y hace el cambio de ubicación a  Clínica  y le 
 * graba el nombre del Cliente al arreglo correspondiente.
 **/
bool nuevoServicio()
{
    int id;
    bool atencion = false;

    cout << "\nDigite el codigo: ";
    cin >> id;

    for (int i = 0; i < indice; i++)
    {
        if (codigo[i] == id)
        {
            if (ubicacion[i] == "casa")
            {
                atencion = true;
                id = i;
            }
        }
    }

    if (atencion){
        cout << "\nDigite el nombre del cliente: ";
        cin >> cliente[id];

        cout << "\nDigite el servicio: ";
        cin >> servicio[id];

        cout << "\nDigite el precio: ";
        cin >> precio[id];

        ubicacion[id] = "clinica";

        return true;
    }
    
    return false;
}

// Menu de opciones
char mostrar_menu()
{
    char op;
    cout << "Menu Principal\n";
    cout << "\np. Nuevo Servicio";
    cout << "\nd. Terminar Servicio";
    cout << "\nc. Crear";
    cout << "\nl. Listar";
    cout << "\nt. Salir\n";
    do
    {
        cout << "\n\nIngrese opcion: ";
        cin >> op;
    } while (op != 'p' && op != 'd' && op != 'c' && op != 'l' && op != 't');

    system("cls");
    return op;
}

// Principal
int main()
{
    char op;

    do
    {
        system("cls");
        op = mostrar_menu();

        switch (op)
        {
        case 'p':
            if (nuevoServicio())
                    cout << "\nRegistrado con exito";
            else
                    cout << "\nNo permitido";
            break;

        case 'd':
            if (terminaServicio())
                    cout << "\nServicio culminado";
            else
                    cout << "\nNo permitido";
            break;

        case 'c':
            if (nuevaMascota())
                cout << "\nCreado con exito";
            else
                cout << "\nLimite excedido";
            break;

        case 'l':
            listaServicios();
            break;

        case 't':
            listaServicios();
            cout << "\nFIN DEL PROGRAMA";
            break;
        }
        cout << "\n\n";
        system("pause");
    } while (op != 't');
}