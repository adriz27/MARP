// Adrián Pérez

#include <fstream>
#include <iostream>
#include "PriorityQueue.h"

using namespace std;
/*
	

*/

bool resuelveCaso() {
	long long int N, x, y, tot = 0;
	cin >> N;
	if (N == 0) { return false; }
	PriorityQueue<long long int> cola;
	for (long long int i = 0; i < N; i++) {
		cin >> x;
		cola.push(x);
	}
	while (cola.size() > 1) {
		cola.pop(x);
		cola.pop(y);
		cola.push(x + y);
		tot += x + y;
	}
	cout << tot << '\n';
	return true;
}

int main() {
	
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso()) {}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	

	//while (resuelveCaso()) {}

	return 0;
}