// Adrián Pérez

#include <fstream>
#include "Grafo.h"

using namespace std;
/*


*/

void cierre(Grafo const& g, int const& a, int const& ant, int& n, vector<bool>& ab) {
	vector<int> v = g.ady(a);
	for (int i = 0; i < v.size(); i++) {
		if (v[i] != ant && !ab[v[i]]) {
			ab[v[i]] = true;
			n++;
			cierre(g, v[i], a, n, ab);
		}
	}
}


void resuelveCaso() {
	int V, A, x, y, max = 0;
	bool b;
	vector<bool> v;
	cin >> V >> A;
	Grafo g = Grafo(V);
	for (int i = 0; i < A; i++) {
		cin >> x >> y;
		g.ponArista(x-1, y-1);
	}
	for (int i = 0; i < V; i++) { v.push_back(false); }
	for (int i = 0; i < V; i++) {
		int n = 1;
		if (!v[i]) { 
			v[i] = true;
			cierre(g, i, -1, n, v); 
			if (n > max) { max = n; }
		}
	}

	cout << max << '\n';
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
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) { resuelveCaso(); }

	return 0;
}