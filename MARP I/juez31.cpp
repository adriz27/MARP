// Adrián Pérez

#include <fstream>
#include <iostream>
#include "PriorityQueue.h"

using namespace std;

bool resuelveCaso() {
	long long int N, pasadizos = 0;
	long long int x, y, c = -1, f = -1;
	cin >> N;
	if (N == 0) { return false; }
	PriorityQueue<pair<long long int, long long int>> edificios;
	for (long long int i = 0; i < N; i++) {
		cin >> x >> y;
		edificios.push({ x, y });
	}
	
	for (long long int i = 0; i < N; i++) {
		x = edificios.top().first;
		y = edificios.top().second;
		if(x >= f){
			f = y;
			pasadizos++;
		}
		else if (y < f) { f = y; }
		c = x;
		edificios.pop();
	}

	cout << pasadizos << '\n';

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