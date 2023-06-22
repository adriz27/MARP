// Adrián Pérez

#include <fstream>
#include <iostream>
#include "PriorityQueue.h"

using namespace std;
/*
	

*/

typedef struct user{ int id; int sig; int T; };

bool operator < (user const& a, user const& b) {
	return a.sig < b.sig || a.sig == b.sig && a.id < b.id;
}

bool resuelveCaso() {
	int N, M, id, T;
	user x;
	cin >> N;
	if (N == 0) { return false; }
	PriorityQueue<user> cola;
	for (int i = 0; i < N; i++) {
		cin >> id >> T;
		cola.push({ id, T, T });
	}
	cin >> M;
	for (int j = 0; j < M; j++) {
		cola.pop(x);
		cout << x.id << '\n';
		cola.push({ x.id, x.sig + x.T, x.T });
	}
	cout << "---" << '\n';
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