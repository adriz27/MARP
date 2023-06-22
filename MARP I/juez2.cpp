// Adrián Pérez

#include <fstream>
#include <iostream>
#include "TreeSet_AVL.h"

using namespace std;
/*
	ESTE ALGORITMO TIENE, RESPETO AL NÚMERO DE ELEMENTOS DEL CONJUNTO, COSTE LOGARÍTMICO EN EL
	CASO PEOR GRACIAS A LA ESTRUCTURA ARBÓREA. RESPECTO A LA ALTURA DE ESTE ÁRBOL SERÍA LINEAL.

*/

bool resuelveCaso() {
	int N, M, x;
	cin >> N;
	if (N == 0) { return false; }
	Set<int> a;
	for (int i = 0; i < N; i++) {
		cin >> x;
		a.insert(x);
	}
	cin >> M;
	for (int j = 0; j < M; j++) {
		cin >> x;
		try { cout << a.kesimo(x) << '\n'; }
		catch (const std::invalid_argument& e){ cout << "??" << '\n'; }
	}
	cout << "---" << '\n';
	return true;
}

int main() {
	/*
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso()) {}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif*/

	while (resuelveCaso()) {}

	return 0;
}