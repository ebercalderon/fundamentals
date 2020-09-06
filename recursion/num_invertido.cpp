#include<iostream>
using namespace std;

void invertir ( int nro) {
    
    if (nro>0 ){
	cout << nro% 10 ; 
	invertir (nro/10 );
	}
}

int  main () {
    int nro;
    do {
        cout << " Ingrese un numero: " ;
            cin >> nro;
            if (nro<0 ) cout << " Ingrese correctamente el numero"<<endl;
    } while (nro<0 );
    cout << "Numero inicial: "<< nro;
    cout<<endl;
    cout << "Numero invertido:" ;
    invertir (nro);
    cout << endl << endl;
    
    return  0 ;
}
