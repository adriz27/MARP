// Adrián Pérez

#include <fstream>
#include "Grafo.h"

using namespace std;
/*


*/

void cierre(Grafo const& g, long long int const& a, long long int const& ant, long long int& n, vector<bool>& ab, long long int const& N) {
	vector<int> v = g.ady(a);
	for (long long int i = 0; i < v.size(); i++) {
		if (v[i] != ant && !ab[v[i]]) {
			ab[v[i]] = true;
			if (v[i] < N) { n++; }
			cierre(g, v[i], a, n, ab, N);
		}
	}
}


bool resuelveCaso() {
	long long int N, M, m, x;
	vector<bool> v;
	vector<int> mm;
	cin >> N >> M;
	if (!cin) { return false; }
	Grafo g = Grafo(N+M);
	for (long long int i = 0; i < M; i++) {
		cin >> m;
		for (long long int j = 0; j < m; j++) {
			cin >> x;
			g.ponArista(N+i, x-1);
		}
	}
	for (long long int j = 0; j < N + M; j++) { v.push_back(false); }
	for (long long int j = 0; j < N; j++) { mm.push_back(0); }

	for (long long int i = 0; i < N; i++) {
		if (mm[i] == 0) {
			for (int j = 0; j < N + M; j++) { v[j] = false; }
			m = 1;
			v[i] = true;
			cierre(g, i, -1, m, v, N);
			for (long long int j = 0; j < N; j++) { 
				if (v[j] == true) { mm[j] = m; }
			}
		}
		if (i != 0) { cout << ' '; }
		cout << mm[i];
	}
	cout << '\n';
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