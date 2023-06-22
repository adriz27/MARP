// Adrián Pérez

#include <fstream>
#include "DigrafoValorado.h"
#include "PriorityQueue.h"
#include "set_eda.h"

using namespace std;


bool resuelveCaso() {
	int N = 0, M, x, y, tiempo;
	cin >> N;
	if (N == 0) { return false; }
	vector<int> t;
	for (int i = 0; i < N; i++) {
		cin >> x;
		t.push_back(x);
	}
	DigrafoValorado<int> g = DigrafoValorado<int>(N);
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> tiempo;
		g.ponArista({ x - 1, y - 1, tiempo });
	}
	vector<int> dist(N, 400000);
	PriorityQueue<pair<int, int>> cola;
	set<int> hechos;
	dist[0] = t[0];
	cola.push({dist[0], 0});
	while (!cola.empty()) {
		int v = cola.top().second;
		cola.pop();
		if (!hechos.count(v)) {
			for (auto a : g.ady(v)) {
				int u = a.desde(), w = a.hasta();
				if (dist[w] > dist[u] + a.valor() + t[w]) {
					dist[w] = dist[u] + a.valor() + t[w];
					cola.push({ dist[w], w });
				}
			}
		}
		hechos.insert(v);
	}
	if (hechos.count(N-1)) {
		cout << dist[N-1] << '\n';
	}
	else { cout << "IMPOSIBLE" << '\n'; }

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