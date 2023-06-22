// Adrián Pérez

#include <fstream>
#include "Digrafo.h"

using namespace std;


bool resuelveCaso() {
	int N, M, x, y;
	cin >> N >> M;
	if (!cin) { return false; }
	Digrafo g = Digrafo(N);
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		g.ponArista(x, y);
	}
	Digrafo inv = g.inverso();
	bool b = true;
	int i = 0;
	while (i < N && b) {
		if (g.ady(i).empty() && inv.ady(i).size() == N - 1) {
			b = false; 
		}
		i++;
	}
	if (b) { cout << "NO" << '\n'; }
	else { cout << "SI " << i - 1 << '\n';	}

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