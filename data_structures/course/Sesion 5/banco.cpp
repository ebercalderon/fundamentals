// cola en un Banco
// Existen dos tipos de colas para la atenci�n
// 1. Clientes
// 2. Visitantes
// Se atiende a dos de la cola clientes por un de la cola de visitantes.
#include <iostream>
#include "banco.h"
using namespace std;
int main()
{
	cola colaVisitante, colaCliente;
	int operacion, cont;
	char tipoCliente, dato;
	cont = 0;
	do
	{
		cout << endl;
		cout << "Elija 1 para ingresar a la cola, 2 para atender y 0 para terminar" << endl;
		cin >> operacion;

		if (operacion == 1)
		{
			// encolar
			cout << "Escriba c para cliente  y escriba v para visitante" << endl;
			cin >> tipoCliente;
			cout << "Dato de la persona" << endl;
			cin >> dato;
			if (tipoCliente == 'c')
				colaCliente.encolar(dato);
			if (tipoCliente == 'v')
				colaVisitante.encolar(dato);
		}
		else if (operacion == 2)
		{
			// desencolar
			if (cont < 2 && colaCliente.vacia() == false)
			{
				colaCliente.desencolar();
				cont++;
			}
			else if (colaVisitante.vacia() == false)
			{
				colaVisitante.desencolar();
				cont = 0;
			}
			else if (colaVisitante.vacia() == true && colaCliente.vacia() == false)
			{
				cont = 0;
				colaCliente.desencolar();
			}
			else
				cout << "Las colas estan vacias" << endl;
		}
		colaCliente.imprimir();
		cout << endl;
		colaVisitante.imprimir();
	} while (operacion != 0);
}
