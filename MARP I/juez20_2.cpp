// Adrián Pérez

#include <fstream>
#include "Grafo.h"
#include "ConjuntosDisjuntos.h"

using namespace std;

void cierre(Grafo const& g, int const& a, vector<bool>& ab, ConjuntosDisjuntos& cd) {
	vector<int> v = g.ady(a);
	for (int i = 0; i < v.size(); i++) {
		if (!ab[v[i]]) {
			ab[v[i]] = true;
			cd.unir(a, v[i]);
			cierre(g, v[i], ab, cd);
		}
	}
}

bool resuelveCaso() {
	int F, C, N, max = 0, x, y;
	char c;
	cin >> F >> C;
	if (!cin) { return false; }
	Grafo g = Grafo(F * C);
	ConjuntosDisjuntos cd = ConjuntosDisjuntos(F * C);
	for (int i = 0; i < F; i++) {
		for (int j = 0; j < C; j++) {
			if (j != C - 1) { g.ponArista(C * i + j, C * i + j + 1); }
			if (i != F - 1) {
				g.ponArista(C * i + j, C * i + j + C);
				if (j != 0) { g.ponArista(C * i + j, C * i + j + C - 1); }
				if (j != C - 1) { g.ponArista(C * i + j, C * i + j + C + 1); }
			}
		}
	}
	vector<bool> v, agua;
	for (int i = 0; i < F; i++) {
		cin.get(c);
		for (int j = 0; j < C; j++) {
			cin.get(c);
			if (c == ' ') { 
				v.push_back(true); 
				agua.push_back(true);
			}
			else { 
				v.push_back(false); 
				agua.push_back(false);
			}
		}
	}

	for (int i = 0; i < F * C; i++) {
		if (!v[i]) {
			v[i] = true;
			cierre(g, i, v, cd);
			int m = cd.cardinal(i);
			if (m > max) { max = m; }
		}
	}

	cout << max;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		x--;
		y--;
		agua[C * x + y] = false;
		vector<int> ady = g.ady(C * x + y);
		for (int j = 0; j < ady.size(); j++) {
			if (!agua[ady[j]]) { cd.unir(C * x + y, ady[j]); }
			int m = cd.cardinal(C * x + y);
			if (m > max) { max = m; }
		}
		cout << ' ' << max;
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