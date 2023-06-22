// Adrián Pérez

#include <fstream>
#include "GrafoValorado.h"
#include "ConjuntosDisjuntos.h"
#include "PriorityQueue.h"

using namespace std;


bool resuelveCaso() {
	int I, P, x, y, n = 0;
	long long int precio, coste = 0;
	cin >> I >> P;
	if (!cin) { return false; }
	GrafoValorado<long long int> g = GrafoValorado<long long int>(I);
	for (int i = 0; i < P; i++) {
		cin >> x >> y >> precio;
		g.ponArista({ x - 1, y - 1, precio });
	}
	PriorityQueue<Arista<long long int>> cola(g.aristas());
	ConjuntosDisjuntos conj(I);
	while (!cola.empty() && n < I-1) {
		Arista<long long int> a = cola.top();
		cola.pop();
		int v = a.uno(), w = a.otro(v);
		if (!conj.unidos(v, w)) {
			conj.unir(v, w);
			coste += a.valor();
			n++;
		}
	}
	if (n == I-1) {
		cout << coste << '\n';
	}
	else { cout << "No hay puentes suficientes" << '\n'; }

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
#endif
	*/
	while (resuelveCaso()) {}

	return 0;
}