#include <iostream>

using namespace std;

int sum = 0;
int buscar = 0;

/* ARBOL AVL
------------------------------------------------------------------------*/
class Nodo
{
public:
    int carnet;      // carnet que se almacenan en cada nodo
    string nombre;   // nombre que se almacenan en cada nodo
    string telefono; // telefono que se almacenan en cada nodo
    Nodo *izq;       // puntero al hijo izquierdo de ese nodo
    Nodo *der;       // puntero al hijo derecho de ese nodo
    int peso;        // peso of the node
};

/** Fx max
 * devuelve el maximo de dos numeros
 * se utiliza como funcion de ayuda para calcular el factor de equilibrio de un nodo
 */
int max(int a, int b)
{
    return (a > b) ? a : b;
}

/** Fx peso
 * devuelve el peso del nodo
 */
int peso(Nodo *n)
{
    if (n == NULL)
        return 0;
    return n->peso;
}

/** Fx minValorNodo
 * devuelve el nodo con el elemento de datos mas pequeño del arbol AVl
 * lo hace devolviendo el nodo mas izq de todo el arbol.
 */
Nodo *minValorNodo(Nodo *n)
{
    while (n->izq != NULL)
        n = n->izq;
    return n;
}

/** Fx nuevoNodo
 * crea un nuevo nodo que almacena los datos dados (entero y cadena),
 * e inicializa los punteros hijos a NULL y el peso a 1
 */
Nodo *nuevoNodo(int dataCarnet, string dataNombre, string dataTelefono)
{
    Nodo *nodo = new Nodo();

    nodo->carnet = dataCarnet;
    nodo->nombre = dataNombre;
    nodo->telefono = dataTelefono;
    nodo->izq = NULL;
    nodo->der = NULL;
    nodo->peso = 1;

    return (nodo);
}

// Fx rotacionDer
Nodo *rotacionDer(Nodo *x)
{
    Nodo *y = x->izq;
    Nodo *T2 = y->der;

    // Rotacion
    y->der = x;
    x->izq = T2;

    x->peso = max(peso(x->izq), peso(x->der)) + 1;
    y->peso = max(peso(y->izq), peso(y->der)) + 1;

    return y;
}

// Fx rotacionIzq
Nodo *rotacionIzq(Nodo *x)
{
    Nodo *y = x->der;
    Nodo *T2 = y->izq;

    // Rotacion
    y->izq = x;
    x->der = T2;

    x->peso = max(peso(x->izq), peso(x->der)) + 1;
    y->peso = max(peso(y->izq), peso(y->der)) + 1;

    return y;
}

/** Fx obtenerBalance
 * devuelve el factor de equilibrio del nodo
 */
int obtenerBalance(Nodo *N)
{
    if (N == NULL)
        return 0;
    return peso(N->izq) - peso(N->der);
}

/* INSERTAR NODO
------------------------------------------------------------------------*/
Nodo *insertarNodo(Nodo *nodo, int dataCarnet, string dataNombre, string dataTelefono)
{

    if (nodo == NULL)
        return (nuevoNodo(dataCarnet, dataNombre, dataTelefono));

    if (dataCarnet < nodo->carnet)
        nodo->izq = insertarNodo(nodo->izq, dataCarnet, dataNombre, dataTelefono);

    else if (dataCarnet > nodo->carnet)
        nodo->der = insertarNodo(nodo->der, dataCarnet, dataNombre, dataTelefono);

    nodo->peso = 1 + max(peso(nodo->izq), peso(nodo->der));
    int balance = obtenerBalance(nodo);

    // Caso Izquierdo Izquierdo
    if (balance > 1 && dataCarnet < nodo->izq->carnet)
        return rotacionDer(nodo);

    // Caso derecho derecho
    if (balance < -1 && dataCarnet > nodo->der->carnet)
        return rotacionIzq(nodo);

    // Caso izquierdo derecho
    if (balance > 1 && dataCarnet > nodo->izq->carnet)
    {
        nodo->izq = rotacionIzq(nodo->izq);
        return rotacionDer(nodo);
    }

    // Caja derecha izquierda
    if (balance < -1 && dataCarnet < nodo->der->carnet)
    {
        nodo->der = rotacionDer(nodo->der);
        return rotacionIzq(nodo);
    }

    return nodo;
}

/* ELIMINAR NODO
------------------------------------------------------------------------*/
Nodo *eliminarNodo(Nodo *raiz, int key)
{

    // caso base
    if (raiz == NULL)
    {
        return raiz;
    }

    // si la clave a eliminar es menor que los datos de la raiz, entonces se encuentra en el subarbol izquierdo
    if (key < raiz->carnet)
    {
        raiz->izq = eliminarNodo(raiz->izq, key);
    }

    // si la clave a eliminar es mayor que los datos de la raiz, entonces se encuentra en el subarbol derecho
    else if (key > raiz->carnet)
    {
        raiz->der = eliminarNodo(raiz->der, key);
    }

    // si la clave es la misma que los datos de la raiz, entonces este es el nodo que se va a eliminar
    else
    {
        // el nodo no tiene ningun hijo
        if (raiz->izq == NULL && raiz->der == NULL)
        {
            delete raiz;
            raiz = NULL;
        }

        // nodo con un solo hijo

        // hijo derecho
        else if (raiz->izq == NULL)
        {
            Nodo *temp = raiz;
            raiz = raiz->der;
            delete temp;
        }

        // hijo izquierdo
        else if (raiz->der == NULL)
        {
            Nodo *temp = raiz;
            raiz = raiz->izq;
            delete temp;
        }

        // nodo con dos hijos
        else
        {
            Nodo *temp = minValorNodo(raiz->der);
            raiz->carnet = temp->carnet;
            raiz->der = eliminarNodo(raiz->der, temp->carnet);
        }
    }
    return raiz;
}

// Fx buscarNodo
Nodo *buscarNodo(Nodo *n)
{
    bool encontrado = false;

    // caso base
    if (n == NULL)
    {
        if (!encontrado)
            cout << "No encontrado";
        return n;
    }

    // si la clave a buscar es menor que los datos de la raiz, entonces se encuentra en el subarbol izquierdo
    if (buscar < n->carnet)
    {
        n->izq = buscarNodo(n->izq);
    }

    // si la clave a buscar es mayor que los datos de la raiz, entonces se encuentra en el subarbol derecho
    else if (buscar > n->carnet)
    {
        n->der = buscarNodo(n->der);
    }

    // si la clave es la misma que los datos de la raiz, entonces este es el nodo buscado
    else
    {
        encontrado = true;
        cout << to_string(n->carnet) + " - " + n->nombre + " - " + n->telefono;
    }

    return n;
}

// Fx obtenerSuma
void obtenerSuma(Nodo *n)
{
    if (n != NULL)
    {
        obtenerSuma(n->izq);
        sum += n->carnet;
        obtenerSuma(n->der);
    }
}

/* EN ORDEN
 * se recorre desde el subarbol izquierdo hasta la raiz y luego hasta el subarbol derecho
------------------------------------------------------------------------*/
void orden(Nodo *n)
{
    if (n != NULL)
    {
        orden(n->izq);
        cout << n->carnet << " - ";
        cout << n->nombre << " - ";
        cout << n->telefono << "\n";
        orden(n->der);
    }
}

/* PREORDEN
 * se recorre desde la raiz hasta el subarbol izquierdo y luego hacia el subarbol derecho
------------------------------------------------------------------------*/
void preorden(Nodo *n)
{
    if (n != NULL)
    {
        cout << n->carnet << " - ";
        cout << n->nombre << " - ";
        cout << n->telefono << "\n";
        preorden(n->izq);
        preorden(n->der);
    }
}

/* POST ORDEN
 * se recorre desde el subarbol izquierdo hasta el subarbol derecho y luego hasta la raiz
------------------------------------------------------------------------*/
void postorden(Nodo *n)
{
    if (n != NULL)
    {
        postorden(n->izq);
        postorden(n->der);
        cout << n->carnet << " - ";
        cout << n->nombre << " - ";
        cout << n->telefono << "\n";
    }
}

// Fx contarNodosInternos
int contarNodosInternos(Nodo *raiz)
{
    if (raiz == NULL)
        return 0;

    if (raiz->izq == NULL && raiz->der == NULL)
        return 0;

    return 1 + contarNodosInternos(raiz->izq) + contarNodosInternos(raiz->der);
}

/* MOSTRAR
------------------------------------------------------------------------*/
void mostrar(string c, Nodo *n, bool esIzq)
{

    if (n != NULL)
    {
        cout << c;
        cout << (esIzq ? "├──" : "└──");

        cout << n->carnet << " - ";
        cout << n->nombre << " \n";

        mostrar(c + (esIzq ? "│   " : "    "), n->izq, true);
        mostrar(c + (esIzq ? "│   " : "    "), n->der, false);
    }
}

/* MAIN
------------------------------------------------------------------------*/
int main()
{

    Nodo *raiz = NULL;

    int opcion, a, b, contador;
    string c = "1", d = "1";

    // Datos por default (Opcional)
    raiz = insertarNodo(raiz, 1, "A", "101");
    raiz = insertarNodo(raiz, 2, "B", "102");
    raiz = insertarNodo(raiz, 3, "C", "103");
    raiz = insertarNodo(raiz, 4, "D", "104");
    raiz = insertarNodo(raiz, 5, "E", "105");
    raiz = insertarNodo(raiz, 6, "F", "106");
    raiz = insertarNodo(raiz, 7, "G", "107");

    cout << "\n==========================="
         << "\n....:::: Arbol AVL ::::...."
         << "\n===========================\n"
         << "\n-Datos-\t-ID-\n";

    cout << "1 -> Insertar un Nodo \n"
         << "2 -> Eliminar un Nodo \n"
         << "3 -> Recorrido: En orden \n"
         << "4 -> Recorrido : Preorden \n"
         << "5 -> Recorrido : Postorden  \n"
         << "6 -> Numero de Nodos Internos \n"
         << "7 -> Suma de Nodos \n"
         << "8 -> Buscar Nodo \n"
         << "9 -> Mostrar Arbol \n"
         << "10 -> Altura del arbol AVL \n"
         << "11 -> Salir \n\n";

    do
    {
        cout << "\nIngrese su eleccion : ";
        cin >> opcion;

        switch (opcion)
        {

        case (1):
            cout << "Ingrese el carnet a insertar en el arbol : ";
            cin >> a;
            cout << "Ingrese su nombre : ";
            cin >> c;
            cout << "Ingrese su telefono : ";
            cin >> d;
            raiz = insertarNodo(raiz, a, c, d);
            break;

        case (2):
            cout << "Ingrese el elemento a ser eliminado del arbol : ";
            cin >> b;
            eliminarNodo(raiz, b);
            break;

        case (3):
            orden(raiz);
            cout << endl;
            break;

        case (4):
            preorden(raiz);
            cout << endl;
            break;

        case (5):
            postorden(raiz);
            cout << endl;
            break;

        case (6):
            contador = contarNodosInternos(raiz);
            cout << "Numero de nodos internos : " << contador << endl;
            break;

        case (7):
            obtenerSuma(raiz);
            cout << "Suma de nodos : " << sum << endl;
            break;

        case (8):
            cout << "Ingrese el elemento a buscar del arbol : ";
            cin >> buscar;
            cout << "Nodo " + to_string(buscar) + " : ";
            buscarNodo(raiz);
            cout << endl;
            buscar = 0;
            break;

        case (9):
            mostrar("", raiz, false);
            break;

        case (10):
            cout << "Altura del arbol AVL : " << raiz->peso - 1 << endl;
            break;

        case (11):
            break;

        default:
            cout << "Introduzca un valor entre 1 y 11";
        }
    } while (opcion != 10);

    return 0;
}