#include <iostream>

using namespace std;

struct nodo
{
    char dato;
    nodo *sig;
};

typedef nodo *pcola;

class cola
{
private:
    pcola pfrente, pfinal;
    int ct;

public:
    cola();  // constructor
    ~cola(); // para eliminar la memoria utilizada

    void encolar(char);
    void desencolar();
    char ultimo();

    void imprimir();
    bool vacia();
    int contar();
};

cola::cola()
{
    pfrente = NULL;
    pfinal = NULL;

    ct = 0;
}

cola::~cola()
{
    pcola p, q;
    p = pfrente;
    while (p != NULL)
    {
        q = p;
        p = p->sig;
        delete q;
    }
}

void cola::encolar(char c)
{
    pcola p;
    p = new nodo;
    p->dato = c;
    p->sig = NULL;
    if (pfrente == NULL)
        pfrente = p;
    else
        pfinal->sig = p;
    pfinal = p;
}

void cola::desencolar()
{
    pcola p;
    p = pfrente;
    if (p != NULL)
    {
        pfrente = p->sig;
        delete p;
        if (pfrente == NULL)
            pfinal = NULL;
    }
}

char cola::ultimo()
{
    pcola p;
    p = pfrente;
    if (p != NULL)
        return p->dato;
    
    return 'f';
}

void cola::imprimir()
{
    pcola p;
    p = pfrente;
    if (p == NULL)
        cout << "cola vacia" << endl;
    else
        do
        {
            cout << p->dato << "->";
            p = p->sig;
        } while (p != NULL);
}

bool cola::vacia()
{
    if (pfrente == NULL)
        return true;
    else
        return false;
}

int cola::contar()
{
    ct = 0;
    pcola temp = pfrente;
    while (temp != NULL)
    {
        ct++;
        temp = temp->sig;
    }
    return ct;
}