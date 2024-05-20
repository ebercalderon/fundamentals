#include <iostream>
#include "final.h"

using namespace std;

int main()
{
    cola colaCompras, colaCaja1, colaCaja2, colaCaja3;
    int operacion, cont;
    char cliente, dato;

    cont = 0;

    do
    {
        cout << endl;
        cout << "Elija 1 para ingresar a comprar, 2 para pasar a caja, 3 para pagar todas las cajas y 0 para terminar" << endl;
        cin >> operacion;

        if (operacion == 1)
        {
            if (colaCompras.contar() <= 25)
            {
                // encolar
                cout << "Dato de la persona: ";
                cin >> dato;
                colaCompras.encolar(dato);
            }
            else 
            {
                cout << "No hay carritos disponibles";
            }
        }
        else if (operacion == 2)
        {
            // encolar
            cout << "Dato de la persona: " << colaCompras.ultimo() << endl;

            if (colaCaja3.contar() < colaCaja2.contar() && colaCaja3.contar() < colaCaja2.contar() || colaCaja3.contar() < colaCaja1.contar() && colaCaja3.contar() < colaCaja1.contar())
            {
                colaCaja3.encolar(colaCompras.ultimo());
                cout << "Caja3: " << colaCaja3.contar() << endl;
            } 
            else if (colaCaja2.contar() < colaCaja1.contar() && colaCaja2.contar() < colaCaja1.contar())
            {
                colaCaja2.encolar(colaCompras.ultimo());
                cout << "Caja3: " << colaCaja2.contar() << endl;
            }
            else
            {
                colaCaja1.encolar(colaCompras.ultimo());
                cout << "Caja3: " << colaCaja1.contar() << endl;
            }

            // desencolar compras
            if (cont < 2 && colaCompras.vacia() == false)
            {
                colaCompras.desencolar();
                cont++;
            }
            else if (colaCompras.vacia() == false)
            {
                colaCompras.desencolar();
                cont = 0;
            }
            else if (colaCompras.vacia() == true && colaCompras.vacia() == false)
            {
                cont = 0;
                colaCompras.desencolar();
            }
            else
                cout << "Las colas estan vacias" << endl;
        }
        else if (operacion == 3)
        {
            // desencolar caja 1
            if (cont < 2 && colaCaja1.vacia() == false)
            {
                colaCaja1.desencolar();
                cont++;
            }
            else if (colaCaja1.vacia() == false)
            {
                colaCaja1.desencolar();
                cont = 0;
            }
            else if (colaCaja1.vacia() == true && colaCaja1.vacia() == false)
            {
                cont = 0;
                colaCaja1.desencolar();
            }
            else
                cout << "Las colas estan vacias" << endl;

            // desencolar caja 2
            if (cont < 2 && colaCaja2.vacia() == false)
            {
                colaCaja2.desencolar();
                cont++;
            }
            else if (colaCaja2.vacia() == false)
            {
                colaCaja2.desencolar();
                cont = 0;
            }
            else if (colaCaja2.vacia() == true && colaCaja2.vacia() == false)
            {
                cont = 0;
                colaCaja2.desencolar();
            }
            else
                cout << "Las colas estan vacias" << endl;

            // desencolar caja 3
            if (cont < 2 && colaCaja3.vacia() == false)
            {
                colaCaja3.desencolar();
                cont++;
            }
            else if (colaCaja3.vacia() == false)
            {
                colaCaja3.desencolar();
                cont = 0;
            }
            else if (colaCaja3.vacia() == true && colaCaja3.vacia() == false)
            {
                cont = 0;
                colaCaja3.desencolar();
            }
            else
                cout << "Las colas estan vacias" << endl;    
        }
        

        cout << "Cola compras: ";
        colaCompras.imprimir();
        cout << endl;

        cout << "Caja 1: ";
        colaCaja1.imprimir();
        cout << endl;

        cout << "Caja 2: ";
        colaCaja2.imprimir();
        cout << endl;

        cout << "Caja 3: ";
        colaCaja3.imprimir();
        cout << endl;

    } while (operacion != 0);
}
