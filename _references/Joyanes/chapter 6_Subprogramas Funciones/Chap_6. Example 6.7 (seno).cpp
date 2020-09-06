/*	Ejemplo 6.7
	Supuesto que nuestro compilador no tiene la función seno. Podríamos calcular el seno de x mediante la siguiente
	serie:
	sen(x) = x – x^3/3! + x^5/5! – x^7/7! + ... (hasta 17 términos)
	x (ángulo en radianes)	*/
	
#include <iostream>
using namespace std;

float factorial (int n);
float potencia (float x, int n);
float seno (float gr);

int main(){
	float gr, sen;
	char rpta;
	
	do{
		cout << "Digite angulo en grados: ";
		cin >> gr;
		sen = seno(gr);
		cout << "Seno(" << gr << "): " << sen << '\n';
		cout << "Otro angulo? (Y/N): ";
		cin >> rpta;
	}while (rpta != 'N' && rpta != 'n');
	
	return 0;
}

float factorial(int n){
	float fact;
	int i;
	
	fact = 1;
	
	for (i=1; i <= n; i++){
		fact = fact * i;
	}
	return fact;
}

float potencia (float x, int n){
	float pot;
	int i;
	
	pot = 1;
	
	for (i=0; i<=n; i++){
		pot = pot * x;
	}
	return pot;
}

float seno (float gr){
	float x, s;
	int i, n;
	
	x = gr * 3.141592 / 180;
	s = x;
	
	for (i=2; i<=17; i++){
		n = 2 * i - 1;
		if (i % 2 != 0)
			s = s + potencia(x, n) / factorial(n);
		else
			s = s -potencia(x, n) / factorial(n);
	}
	
	return s;
}
/*	Solución
	El programa nos tiene que permitir el cálculo del seno de ángulos en grados mediante el diseño de una 
	función seno(x), que utilizará, a su vez, las funciones potencia(x,n) y factorial(n), que también 
	deberán ser implementadas en el algoritmo.
	Se terminará cuando respondamos N (no) a la petición de otro ángulo.
*/
