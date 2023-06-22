// Adrián Pérez

#include <fstream>
#include "GrafoValorado.h"
#include "PriorityQueue.h"

using namespace std;

bool resuelveCaso() {
	int N, M, x, y, d;
	cin >> N;
	if (!cin) { return false; }
	GrafoValorado<int> g = GrafoValorado<int>(N);
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> d;
		g.ponArista({ x - 1, y - 1, d });
	}
	vector<long long int> dist(N, 4000000000);
	vector<long long int> veces(N, 0);
	PriorityQueue<pair<long long int, int>> cola;
	dist[0] = 0;
	veces[0] = 1;
	cola.push({ dist[0], 0 });
	while (!cola.empty()) {
		int v = cola.top().second;
		long long int di = cola.top().first;
		cola.pop();
		for (auto a : g.ady(v)) {
			int u = a.otro(v);
			if (dist[u] > di + a.valor()) {
				dist[u] = di + a.valor();
				veces[u] = veces[v];
				cola.push({ dist[u], u });
			}
			else if (dist[u] == di + a.valor()) {
				veces[u] += veces[v];
			}
		}
	}
	
	cout << veces[N - 1] << '\n';
	
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