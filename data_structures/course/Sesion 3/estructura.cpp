#include <iostream>
using namespace std;
int main()
{

	struct producto
	{
		// campos de la estructura producto
		string nombre;
		int cantidad;
		float peso;
	};
	typedef producto tproducto;

	int x;
	tproducto p1, p2; // las variables p1 y p2 tienen tres campos nombre, cantidad y peso.

	p1.nombre = "arroz";
	p1.cantidad = 20;
	p1.peso = 3.2;

	cout << p1.nombre << " " << p1.cantidad << " " << p1.peso << endl;

	// para p2

	cin >> p2.nombre;
	cin >> p2.cantidad;
	cin >> p2.peso;

	cout << p2.nombre << " " << p2.cantidad << " " << p2.peso << endl;

	// arreglo de estructura

	tproducto p[3];
	p[0].nombre = "fideos";
	p[1].nombre = "aceite";
	p[2].nombre = "papel";

	cout << p[0].nombre << " " << p[1].nombre << " " << p[2].nombre << endl;
}
