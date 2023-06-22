// Adrián Pérez

#include <fstream>
#include <iostream>
#include "queue_eda.h"

using namespace std;

bool resuelveCaso() {
	int N, L, x, c = 0, parches = 0;
	cin >> N;
	if (!cin) { return false; }
	cin >> L;
	queue<long long int> holes;
	for (int i = 0; i < N; i++) {
		cin >> x;
		holes.push(x);
	}
	while (!holes.empty()) {
		x = holes.front();
		holes.pop();
		if (c < x) {
			c = x + L;
			parches++;
		}
	}

	cout << parches << '\n';
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