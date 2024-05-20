#include <iostream>
using namespace std;
void llenarmaquina(int maquinas[3][3]);
void produccion(int maquinas[3][3]);

int main()
{
    int maquinas[3][3];
    llenarmaquina(maquinas);
    produccion(maquinas);
    system("pause");
    return 0;
}
void llenarmaquina(int maquinas[3][3]){
    int filas, columnas;
    cout<< "\t\tHOLA! BIENVENIDO A TU EMBOTELLADORA FAVORITA "<<endl;
    cout << " \nTenga en cuenta lo siguiente: " << endl;
    cout << " Tipo 1 -> 300 " << endl;
    cout << " Tipo 2 -> 500 " << endl;
    cout << " Tipo 3 -> 1000 " << endl;

    for (filas=0;filas<3;filas++){
    	cout << "\nIngrese la cantidad que ha producido la maquina " <<filas+1<<" :\n";
        for (columnas=0; columnas<3; columnas++){
            cout <<"Tipo de botella " <<columnas+1<<" :";
            cin >> maquinas[filas][columnas];
        }
    }
}

void produccion(int maquinas[3][3]){
    system ("cls");
    int filas, columnas;
    float sumafilas=0, sumacolumnas=0, sumatotal=0;
    cout << "\t\tTipo 1\t\tTipo 2\t\tTipo3\t\tTotal/Maquina\n" << endl;

    for (filas=0;filas<3;filas++){
        cout << "Maquina " <<filas+1 << " :\t";
        for (columnas=0; columnas<3; columnas++){
            sumatotal += maquinas[filas][columnas];
            sumafilas += maquinas[filas][columnas];
            cout << maquinas[filas][columnas] <<"\t\t";
        }
        cout << sumafilas;
        sumafilas=0;
        cout << endl;
    }
    cout << "\nTotal/Tipo\t";

    for (filas=0; filas<3; filas++){
        for (columnas=0; columnas<3; columnas++){
            sumacolumnas+=maquinas[columnas][filas];
        }
        cout <<sumacolumnas<<"\t\t";
        sumacolumnas=0;
    }
    cout << "\n\n";
}
