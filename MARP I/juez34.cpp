// Adrián Pérez

#include <fstream>
#include <iostream>
#include <queue>
#include <algorithm>
#include "PriorityQueue.h"

using namespace std;

bool resuelveCaso() {
	long long int N, c, f, compas = 0;
	cin >> N;
	if (N == 0) { return false; }
	vector<pair<long long int, long long int>> act;
	PriorityQueue<long long int> hasta;
	hasta.push(0);
	for (long long int i = 0; i < N; i++) {
		cin >> c >> f;
		act.push_back({ c, f });
	}
	sort(act.begin(), act.end());
	for(long long int i = 0; i < N; i++) {
		c = act[i].first;
		f = act[i].second;
		if(hasta.top() <= c){
			hasta.pop();
			hasta.push(f);
		}
		else {
			compas++;
			hasta.push(f);
		}
	}

	cout << compas << '\n';

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