// Adrián Pérez

#include <fstream>
#include <iostream>
#include "bintree.h"

using namespace std;
/*
	ESTE ALGORITMO TIENE, EN EL CASO PEOR(CUANDO ES AVL), COSTE LINEAL CON RESPECTO AL NÚMERO DE NODOS 
	YA QUE CADA UNO SE RECORRE EXACTAMENTE UNA VEZ Y SE LLEVAN A CABO UN NÚMERO CONSTANTE DE OPERACIONES
	DE COSTE CONSTANTE. CON RESPECTO A LA ALTURA SERÍA LOGARITMICO PUES SI FUERA DEGENERADO EL ALGORITMO 
	LO DESCARTARÍA COMO AVL SIN NECESIDAD DE RECORRERLO ENTERO.

*/

void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	if (arbol.avl()) { cout << "SI\n"; }
	else { cout << "NO\n"; }
}

int main() {

	#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

		int numCasos;
		cin >> numCasos;
		for (int i = 0; i < numCasos; i++) {
			resuelveCaso();
		}

	#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif
	/*int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}*/

	return 0;
}