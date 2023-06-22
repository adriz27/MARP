// Adrián Pérez

#include <fstream>
#include <iostream>
#include "PriorityQueue.h"

using namespace std;
/*


*/
typedef struct aux {
	long long int media;
	long long int total;
	long long int part;
};

bool operator< (aux const& a, aux const& b) {
	return a.media > b.media;
}

bool resuelveCaso() {
	long long int p, n, num;
	aux x;
	cin >> p >> n;
	if (!cin) { return false; }
	PriorityQueue<aux> cola;
	for (long long int i = 0; i < n; i++) {
		cin >> num;
		cola.push({num, num, 1});
	}
	for (long long int i = 0; i < p-n; i++) {
		cola.pop(x);
		x.part++;
		if (x.total % (x.part) == 0) { cola.push({ x.total / x.part, x.total, x.part });}
		else { cola.push({ x.total / x.part + 1, x.total, x.part }); }
	}
	std::cout << cola.top().media << '\n';
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