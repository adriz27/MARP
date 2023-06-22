// Adrián Pérez

#include <fstream>
#include "Digrafo.h"
#include "queue_eda.h"

using namespace std;


bool resuelveCaso() {
	int N, K, S, E, x, y, solucion;
	cin >> N >> K >> S >> E; 
	if (N == 0) { return false; }
	Digrafo g = Digrafo(N * N);
	for (int i = 0; i < S + E; i++) {
		cin >> x >> y;
		g.ponArista(x - 1, y - 1);
	}
	queue<pair<int, int>> cola;
	vector<bool> v;
	for (int i = 0; i < N * N; i++) { v.push_back(false); }
	cola.push({ 0, 0 });
	bool done = false;
	while (!done) {
		pair<int, int> a = cola.front();
		cola.pop();
		for (int i = 1; i <= K; i++) {
			if (a.first + i < N*N && !v[a.first + i]) {
				v[a.first + i] = true;
				if (!g.ady(a.first + i).empty()) {
					v[g.ady(a.first + i)[0]] = true;
					cola.push({ g.ady(a.first + i)[0], a.second + 1 });
				}
				else { cola.push({ a.first + i, a.second + 1 }); }
				if (v[N * N - 1]) {
					done = true;
					solucion = a.second + 1;
				}
			}
		}
	}
	cout << solucion << '\n';
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