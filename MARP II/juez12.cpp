// Adrián Pérez

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int esfuerzo(vector<pair<long long int, long long int>>& v, long long int& P) {
	long long int n = v.size(), minim, x;
	vector<long long int> aux(P + 1, 100000);
	vector<vector<long long int>> mat(n + 1, aux);
	for (long long int i = 0; i <= n; i++) { mat[i][0] = 0; }
	for (long long int i = 1; i <= n; i++) {
		for (long long int j = 0; j <= P; j++) {
			minim = mat[i-1][j];
			for (long long int k = 1; k <= v[i - 1].second && k*v[i-1].first <= j; k++) {
				x = j - k * v[i - 1].first;
				minim = min(minim, mat[i - 1][x] + k);
			}
			mat[i][j] = minim;
		}
	}
	return mat[n][P];
}


bool resuelveCaso() {
	long long int l, P, N;
	cin >> N;
	if (!cin) { return false; }
	vector<pair<long long int, long long int>> v(N);
	for (long long int i = 0; i < N; i++) {
		cin >> v[i].first;
	}
	for (long long int i = 0; i < N; i++) {
		cin >> v[i].second;
	}
	cin >> P;

	l = esfuerzo(v, P);

	if (l != 100000) { cout << "SI " << l << '\n'; }
	else { cout << "NO" << '\n'; }

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