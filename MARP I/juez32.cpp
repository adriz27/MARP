// Adrián Pérez

#include <fstream>
#include <iostream>
#include "PriorityQueue.h"

using namespace std;

bool resuelveCaso() {
	long long int N, intervalos = 0, C, F, c, f, max = 0, t;
	bool b1 = true, b2 = true;
	cin >> C >> F >> N;
	if (N == 0 && C == 0 && F == 0) { return false; }
	PriorityQueue<pair<long long int, long long int>> interv;
	for (long long int i = 0; i < N; i++) {
		cin >> c >> f;
		interv.push({ c, f });
	}
	t = C;
	while(!interv.empty() &&  b1 && b2){
		c = interv.top().first;
		f = interv.top().second;
		if (c <= t) {
			if (f > max) { max = f; }
		}
		else if (c <= max){
			t = max;
			intervalos++;
			if (max >= F) { b2 = false; }
			if (f > max) { max = f; }
		}
		else { b1 = false; }
		interv.pop();
	}

	if (b1 && max >= F) { 
		if (b2) { intervalos++;}
		cout << intervalos << '\n';
	}
	else { cout << "Imposible" << '\n'; }

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