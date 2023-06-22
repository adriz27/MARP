// Adrián Pérez

#include <fstream>
#include <iostream>
#include "PriorityQueue.h"

using namespace std;

bool resuelveCaso() {
	int N, t = 0, x, y, pelis = 0;
	char c;
	cin >> N;
	if (N == 0) { return false; }
	PriorityQueue<pair<int, int>> horas;
	for (int i = 0; i < N; i++) {
		cin >> x >> c >> y;
		x = 60 * x + y;
		cin >> y;
		horas.push({x+y, x});
	}
	while (!horas.empty()) {
		pair<int, int> p = horas.top();
		if (p.second >= t) {
			pelis++;
			t = p.first + 10;
		}
		horas.pop();
	}

	cout << pelis << '\n';
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