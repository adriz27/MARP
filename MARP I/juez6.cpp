// Adrián Pérez

#include <fstream>
#include <iostream>
#include "PriorityQueue.h"

using namespace std;
/*


*/


bool resuelveCaso() {
	int N, C, t;
	cin >> N >> C;
	if (N == 0 && C == 0) { return false; }
	PriorityQueue<pair<int, int>> cola;
	pair<int, int> x;
	if (C < N) { 
		for (int i = 0; i < C; i++) { cin >> t; }
		cout << C + 1 << '\n'; 
	}
	else {
		for (int i = 0; i < N; i++) {
			cin >> t;
			cola.push({ t, i + 1 });
		}
		for (int i = N; i < C; i++) {
			cola.pop(x);
			cin >> t;
			cola.push({ t + x.first, x.second });
		}
		cout << cola.top().second << '\n';
	}
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