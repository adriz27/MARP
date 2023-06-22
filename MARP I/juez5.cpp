// Adrián Pérez

#include <fstream>
#include <iostream>
#include "PriorityQueue.h"

using namespace std;
/*


*/

typedef struct paciente { string nom; long long int prio; long long int pos; };

bool operator < (paciente const& a, paciente const& b) {
	return a.prio > b.prio || a.prio == b.prio && a.pos < b.pos;
}

bool resuelveCaso() {
	long long int prio, N;
	cin >> N;
	if (N == 0) { return false; }
	char c;
	string nombre;
	paciente p;
	PriorityQueue<paciente> cola;
	for (long long int i = 0; i < N; i++) {
		cin >> c;
		if (c == 'I') {
			cin >> nombre >> prio;
			cola.push({ nombre, prio, i});
		}
		else {
			cola.pop(p);
			cout << p.nom << '\n';
		}
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