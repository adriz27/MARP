// Adrián Pérez

#include <fstream>
#include "Digrafo.h"

using namespace std;

bool fin(vector<bool> const& v) {
	bool b = true;
	int i = 0;
	while (b && i < v.size()) {
		if (!v[i]) { b = false; }
		i++;
	}
	return b;
}

bool resuelveCaso() {
	int N, M, x, y;
	cin >> N >> M;
	if (!cin) { return false; }
	Digrafo g = Digrafo(N);
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		g.ponArista(x - 1, y - 1);
	}
	Digrafo inv = g.inverso();
	vector<bool> v;
	vector<int> sol;
	for (int j = 0; j < N; j++) { v.push_back(false); }

	while (!fin(v)) {
		bool b = true;
		int i = 0;
		while (i < N && b) {
			if (!v[i]) {
				vector<int> ady = inv.ady(i);
				bool libre = true;
				for (int j = 0; j < ady.size(); j++) {
					if (!v[ady[j]]) { libre = false; }
				}
				if (libre) {
					v[i] = true;
					sol.push_back(i + 1);
					b = false;
				}
			}
			i++;
		}
		if (b) {
			cout << "Imposible" << '\n';
			return true;
		}
	}
	if (!sol.empty()) { cout << sol[0]; }
	for (int i = 1; i < sol.size(); i++) {
		cout << " " << sol[i];
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