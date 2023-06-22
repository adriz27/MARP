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


bool resuelveCaso() {
	int F, C, num = 0, max = 0;
	bool b;
	char c;
	vector<bool> v;
	cin >> F >> C;
	if (!cin) { return false; }
	Grafo g = Grafo(F*C);
	for (int i = 0; i < F; i++) {
		for (int j = 0; j < C; j++) {
			if (j != C-1) { g.ponArista(C * i + j, C * i + j + 1); }
			if (i != F-1) { g.ponArista(C * i + j, C * i + j + C); }
		}
	}
	for (int i = 0; i < F*C; i++) {
		cin >> c;
		if(c == '-'){ v.push_back(true); }
		else { v.push_back(false); }
	}
	for (int i = 0; i < F*C; i++) {
		int n = 1;
		if (!v[i]) {
			v[i] = true;
			num++;
			cierre(g, i, -1, n, v);
			if (n > max) { max = n; }
		}
	}

	cout << num << ' ' << max << '\n';
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
	while(resuelveCaso()){ }

	return 0;
}