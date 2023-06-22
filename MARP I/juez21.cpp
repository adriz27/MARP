// Adrián Pérez

#include <fstream>
#include "GrafoValorado.h"

using namespace std;

bool cierre(GrafoValorado<int> const& g, int const& a, int const& obj, int& ancho, vector<bool>& ab) {
	vector<Arista<int>> v = g.ady(a);
	bool b = false;
	int i = 0;
	while (i < v.size() && !b) {
		int d = v[i].otro(a);
		if (!ab[d] && v[i].valor() >= ancho) {
			ab[d] = true;
			if (d == obj || cierre(g, d, obj, ancho, ab)) { b = true; }
		}
		i++;
	}
	return b;
}

bool resuelveCaso() {
	int V, K, x, y, ancho;
	long long int E;
	char c;
	cin >> V >> E;
	if (!cin) { return false; }
	GrafoValorado<int> g = GrafoValorado<int> (V);
	for (long long int i = 0; i < E; i++) {
		cin >> x >> y >> ancho;
		g.ponArista({ x - 1, y - 1, ancho });
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		vector<bool> v;
		for (int i = 0; i < V; i++) { v.push_back(false); }
		cin >> x >> y >> ancho;
		v[x-1] = true;
		if (cierre(g, x - 1, y - 1, ancho, v)) {
			cout << "SI" <<'\n';
		}
		else{ cout << "NO" << '\n'; }
	}
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