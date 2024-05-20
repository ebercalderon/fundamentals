#include <iostream>
#include <math.h>
using namespace std;

void decimal_binario()
{
    int num, D, r, d = 2; //D:dividendo, d:divisor,r:resto
    string binario = "";

    cout << "\nIngres S para salir";

    do
    {
        cout << "\nNumero decimal: ";
        cin >> num;
    } while (num < 0);

    D = num;

    while (D >= d)
    {
        r = D % d;

        if (r == 1)
            binario = "1" + binario;
        else
            binario = "0" + binario;

        D = D / d;
    }

    if (D == 1)
        binario = "1" + binario;
    else
        binario = "0" + binario;

    cout << "\nNumero binario: " << binario;
}

void binario_decimal()
{
    char arr[20] = {};
    int x, decimal = 0, tam = 0, pot = 0;
    cout << "\nIngres S para salir";
    while (arr[0] != 'S')
    {
        cout << "\nBinario: ";
        cin >> arr;
        //calculamos el tamaño del arreglo
        for (x = 0; x < 20; x++)
        {
            if (arr[x] != NULL)
                tam++;
        }
        //creamos la potencia mayor del arreglo, y le restamos 1 a tam
        pot = pow(2, tam - 1);
        //almacenamos en deicmla las potencias, y posterior dividimos en 2 pot para ir sacando las potencias
        for (x = 0; x < 20; x++)
        {
            if (arr[x] == '1')
                decimal += pot;
            pot /= 2;
        }
        cout << "Decimal: " << decimal;
        //volvemos a 0 todos los valores, para que no almacene valores nuevos y de valores erroneos
        decimal = 0;
        pot = 0;
        tam = 0;
    }
}

int main()
{
    char opcion;
    cout << "\nHola MUNDO\n";
    cout << "\n[1] Binario a decimal";
    cout << "\n[2] Decimal a binario";
    do
    {
        cout << "\nEscoga opcion: ";
        cin >> opcion;
    } while (opcion != '1' && opcion != '2');

    switch (opcion)
    {
    case '1':
        binario_decimal();
        break;

    case '2':
        decimal_binario();
        break;
    }
    system("pause");
    return 0;
}