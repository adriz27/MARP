// Adrián Pérez

#include <fstream>
#include "Grafo.h"

using namespace std;
/*


*/

bool adya(Grafo const& g, int const& a, vector<bool>& ab) {
	vector<int> v = g.ady(a);
	for (int i = 0; i < v.size(); i++) {
		ab[v[i]] = true;
	}
	return v.size() != 0;
}


bool resuelveCaso() {
	int N, C, x, y, m = 0, min = 1000000000;
	vector<bool> v;
	cin >> N >> C;
	if (!cin) { return false; }
	Grafo g = Grafo(N);
	for (int i = 0; i < C; i++) {
		cin >> x >> y;
		g.ponArista(x - 1, y - 1);
	}
	for (int i = 0; i < N; i++) {v.push_back(false);}
	for (int j = 0; j < N; j++) {
		for (int i = j; i < N + j; i++) {
			if (!v[i%N]) {
				v[i%N] = true;
				if (adya(g, i % N, v)) { m++; }
			}
		}
		if (m < min) { min = m; }
	}
	cout << min << '\n';
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