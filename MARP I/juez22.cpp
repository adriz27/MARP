// Adrián Pérez

#include <fstream>
#include "GrafoValorado.h"

using namespace std;

bool done(vector<bool> const& v) {
	bool b = true;
	int i = 0;
	while (b && i < v.size()) {
		if (!v[i]) { b = false; }
		i++;
	}
	return b;
}

bool cierre(GrafoValorado<long long int> const& g, int const& a, int& min, int& total, vector<bool>& ab) {
	ab[a] = true;
	if (done(ab)) {
		if (total < min) { min = total; }
		ab[a] = false;
		return true;
	}
	else {
		vector<Arista<long long int>> v = g.ady(a);
		bool b = false;
		for (int i = 0; i < v.size(); i++) {
			int d = v[i].otro(a);
			if (!ab[d]) {
				total += v[i].valor();
				if (cierre(g, d, min, total, ab)) { b = true; }
				total -= v[i].valor();
			}
		}
		ab[a] = false;
		return b;
	}
}

bool resuelveCaso() {
	int I, P, x, y;
	long long int precio;
	cin >> I >> P;
	if (!cin) { return false; }
	GrafoValorado<long long int> g = GrafoValorado<long long int>(I);
	for (int i = 0; i < P; i++) {
		cin >> x >> y >> precio;
		g.ponArista({ x - 1, y - 1, precio });
	}
	vector<bool> v;
	for (int i = 0; i < I; i++) { v.push_back(false); }
	int total = 0, min = 32000;
	if (cierre(g, 0, min, total, v)) {
		cout << min << '\n';
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