// Adrián Pérez

#include <fstream>
#include <iostream>
#include "PriorityQueue.h"

using namespace std;

bool resuelveCaso() {
	int N, L, x, victorias = 0;
	cin >> N;
	if (!cin) { return false; }
	PriorityQueue<long long int> defensa;
	PriorityQueue<long long int> invasores;
	for (int i = 0; i < N; i++) {
		cin >> x;
		invasores.push(x);
	}
	for (int i = 0; i < N; i++) {
		cin >> x;
		defensa.push(x);
	}
	while (!invasores.empty()) {
		x = invasores.top();
		invasores.pop();
		while (!defensa.empty() && defensa.top() < x) { defensa.pop(); }
		if (!defensa.empty()) { 
			defensa.pop(); 
			victorias++;
		}
	}

	cout << victorias << '\n';
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