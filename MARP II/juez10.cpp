// Adrián Pérez

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int minutos(vector<pair<long long int, long long int>>& v) {
	long long int n = v.size();
	vector<long long int> aux(1451, 0);
	for (long long int i = 1; i <= n; i++) {
		for (long long int j = 1450; j > 0; j--) {
			if (j >= v[i-1].first + v[i - 1].second + 10) {
				aux[j] = max(aux[j], aux[v[i-1].first] + v[i-1].second);
			}
		}
	}
	return aux[1450];
}

bool resuelveCaso() {
	long long int l, N;
	int h, m, d;
	char c;
	cin >> N;
	if (N == 0) { return false; }
	vector<pair<long long int, long long int>> v;
	for (int i = 0; i < N; i++) {
		cin >> h >> c >> m >> d;
		v.push_back({60*h+m, d});
	}
	sort(v.begin(), v.end());
	l = minutos(v);
	cout << l << '\n';
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