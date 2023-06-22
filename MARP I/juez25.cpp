// Adrián Pérez

#include <fstream>
#include "GrafoValorado.h"
#include "PriorityQueue.h"

using namespace std;

bool resuelveCaso() {
	int N, C, K, x, y, d;
	cin >> N;
	if (!cin) { return false; }
	GrafoValorado<int> g = GrafoValorado<int>(N);
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> x >> y >> d;
		g.ponArista({ x - 1, y - 1, d });
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> x >> y;
		x--;
		y--;
		vector<long long int> dist(N, 4000000000);
		vector<long long int> calles(N, 4000000000);
		vector<long long int> camino(N, 0);
		PriorityQueue<pair<long long int, int>> cola;
		dist[x] = 0;
		calles[x] = 0;
		cola.push({ dist[x], x });
		while (!cola.empty()) {
			int v = cola.top().second;
			long long int di = cola.top().first;
			cola.pop();
			for (auto a : g.ady(v)) {
				int u = a.otro(v);
				if (dist[u] > di + a.valor()) {
					dist[u] = di + a.valor();
					camino[u] = camino[v] + 1;
					cola.push({ dist[u], u });
				}
				if (calles[u] > calles[v] + 1) {
					calles[u] = calles[v] + 1;
				}
			}
		}

		if (calles[y] == 4000000000) {
			cout << "SIN CAMINO" << '\n';
		}
		else {
			cout << dist[y];
			if (calles[y] == camino[y]) {
				cout << " SI" << '\n';
			}
			else{ cout << " NO" << '\n'; }
		}
	}
	cout << "---" << '\n';
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