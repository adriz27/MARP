// Adrián Pérez

#include <fstream>
#include "Grafo.h"

using namespace std;
/*


*/

bool cierre(Grafo const& g, int const& a, int const& ant, vector<bool>& ab) {
	vector<int> v = g.ady(a);
	for (int i = 0; i < v.size(); i++) {
		if (v[i] != ant) {
			if (ab[v[i]]) { return false; }
			ab[v[i]] = true;
			if (!cierre(g, v[i], a, ab)) { return false; }
		}
	}
	return true;
}


bool resuelveCaso() {
	long long int V, A, x, y;
	bool b;
	vector<bool> v;
	cin >> V >> A;
	if (!cin || V == 0) { return false; }
	Grafo g = Grafo(V);
	for (int i = 0; i < A; i++) {
		cin >> x >> y;
		g.ponArista(x, y);
	}
	for (int i = 0; i < V; i++) { v.push_back(false); }
	b = cierre(g, 0, -1, v);
	if (b) {
		if (v[0]) { b = false; }
		int i = 1;
		while (b && i < V) {
			if (!v[i]) { b = false; }
			i++;
		}
	}
	if (b) { cout << "SI" << '\n'; }
	else { cout << "NO" << '\n'; }
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