// Adrián Pérez

#include <fstream>
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;



bool resuelveCaso() {
	int N, coches = 0;
	long long int V, x;
	cin >> N >> V;
	deque<long long int> volts;
	for (long long int i = 0; i < N; i++) {
		cin >> x;
		volts.push_back(x);
	}
	sort(volts.begin(), volts.end());
	while (!volts.empty()) {
		x = volts.back();
		volts.pop_back();
		while (!volts.empty() && volts.front() + x < V) { volts.pop_front(); }
		if (!volts.empty()) {
			volts.pop_front();
			coches++;
		}
	}
	cout << coches << '\n';

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
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}

	return 0;
}