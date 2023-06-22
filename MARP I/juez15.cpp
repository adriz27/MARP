// Adrián Pérez

#include <fstream>
#include "Grafo.h"
#include "PriorityQueue.h"

using namespace std;
/*


*/

typedef struct nodo {
	int ttl;
	int n;
};

bool operator < (nodo const&  a, nodo const& b) {
	return a.ttl > b.ttl;
}

/*void cierre(Grafo const& g, long long int const& a, long long int const& ant, long long int& n, vector<bool>& ab, long long int ttl) {
	vector<int> v = g.ady(a);
	for (long long int i = 0; i < v.size(); i++) {
		if (v[i] != ant && ttl > 0) {
			if (!ab[v[i]]) {
				ab[v[i]] = true;
				n--;
			}
			cierre(g, v[i], a, n, ab, ttl -1);
		}
	}
}*/


bool resuelveCaso() {
	long long int N, C, K;
	cin >> N >> C;
	if (!cin) { return false; }
	Grafo g = Grafo(N);
	for (long long int i = 0; i < C; i++) {
		long long int x, y;
		cin >> x >> y;
		g.ponArista(x -1, y-1);
	}
	cin >> K;
	for (long long int i = 0; i < K; i++) {
		int n, ttl, aux = -1, inalcanzables = N - 1;
		vector<bool> v;
		PriorityQueue<nodo> cola;
		cin >> n >> ttl;
		for (long long int j = 0; j < N; j++) { v.push_back(false); }
		v[n - 1] = true;
		cola.push({ ttl, n - 1 });
		while (!cola.empty()) {
			nodo a;
			cola.pop(a);
			vector<int> b = g.ady(a.n);
			for (long long int i = 0; i < b.size(); i++) {
				if (!v[b[i]] && a.ttl > 0) {
					v[b[i]] = true;
					inalcanzables--;
					//if (a.ttl > 1) {
						cola.push({ a.ttl - 1, b[i] });
					//}
				}
			}
		}
		//cierre(g, n - 1, aux, inalcanzables, v, ttl);
		cout << inalcanzables << '\n';
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