// Adrián Pérez

#include <fstream>
#include "Digrafo.h"
#include "queue_eda.h"

using namespace std;

int const M = 10000;

typedef struct nodo {
	int dis;
	int n;
};

bool operator < (nodo const& a, nodo const& b) {
	return a.dis < b.dis;
}


bool resuelveCaso() {
	int ini, obj;
	/*Digrafo g = Digrafo(M);
	for (int i = 0; i < M; i++) {
		g.ponArista(i, (i + 1) % M);
		g.ponArista(i, (i * 2) % M);
		g.ponArista(i, i/3);
	}*/
	cin >> ini >> obj;
	if (!cin) { return false; }
	while (true) {
			int distancia = 0;
			vector<bool> v;
			queue<nodo> cola;
			for (int j = 0; j < M; j++) { v.push_back(false); }
			v[ini] = true;
			cola.push({ 0, ini });
			while (distancia == 0 && !cola.empty()) {
				nodo a;
				int i = 0;
				a = cola.front();
				cola.pop();
				vector<int> b = g.ady(a.n);
				/*while(distancia == 0 && i < b.size()){
					if (b[i] == obj) { distancia = a.dis + 1; }
					else if (!v[b[i]]) {
						v[b[i]] = true;
						cola.push({ a.dis + 1, b[i] });
					}
					i++;
				}*/
				if ((a.n +1) % M == obj) { distancia = a.dis + 1; }
				else if (!v[(a.n +1) % M]) {
					v[(a.n +1) % M] = true;
					cola.push({ a.dis + 1, (a.n +1) % M });
				}
				if ((a.n * 2)%M == obj) { distancia = a.dis + 1; }
				else if (!v[(a.n * 2) % M]) {
					v[(a.n * 2) % M] = true;
					cola.push({ a.dis + 1, (a.n * 2) % M });
				}
				if (a.n /3 == obj) { distancia = a.dis + 1; }
				else if (!v[a.n / 3]) {
					v[a.n / 3] = true;
					cola.push({ a.dis + 1, a.n / 3 });
				}
			}
			if (ini == obj) { distancia = 0; }
			cout << distancia << '\n';
		cin >> ini >> obj;
		if (!cin) { return false; }
	}
	return false;
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