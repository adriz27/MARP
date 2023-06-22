// Adrián Pérez

#include <fstream>
#include <iostream>
#include "PriorityQueue.h"

using namespace std;

bool resuelveCaso() {
	int N, x, y, suma = 0;
	cin >> N;
	if (N == 0) { return false; }
	PriorityQueue<long long int> personas;
	PriorityQueue<long long int> esquis;
	for (int i = 0; i < N; i++) {
		cin >> x;
		personas.push(x);
	}
	for (int i = 0; i < N; i++) {
		cin >> x;
		esquis.push(x);
	}
	for (int i = 0; i < N; i++) {
		x = personas.top();
		y = esquis.top();
		personas.pop();
		esquis.pop();
		suma += abs(x - y);
	}

	cout << suma << '\n';

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