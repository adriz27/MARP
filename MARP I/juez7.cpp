// Adrián Pérez

#include <fstream>
#include <iostream>
#include "PriorityQueue.h"

using namespace std;
/*
	

*/

typedef struct tarea { long long int ini; long long int fin; long long int t; };

bool operator < (tarea const& a, tarea const& b) {
	return a.ini < b.ini;
}

bool resuelveCaso() {
	long long int N, M, T, in, fin, t;
	bool b = true;
	tarea x;
	cin >> N >> M >> T;
	if (!cin) { return false; }
	PriorityQueue<tarea> cola;
	for (long long int i = 0; i < N; i++) {
		cin >> in >> fin;
		cola.push({ in, fin, -1 });
	}
	for (long long int i = 0; i < M; i++) {
		cin >> in >> fin >> t;
		cola.push({ in, fin, t });
	}
	in = -1;
	fin = -1;
	while (b && !cola.empty() && in < T) {
		cola.pop(x);
		if (x.ini < fin && x.ini < T) {
			b = false;
		}
		else {
			fin = x.fin;
			in = x.ini;
			if (x.t != -1) { cola.push({ in + x.t, fin + x.t, x.t }); }
		}
	}
	if (b) { cout << "NO" << '\n'; }
	else { cout << "SI" << '\n'; }
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