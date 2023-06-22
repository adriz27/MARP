// Adrián Pérez

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int esfuerzo(vector<pair<int, int>>& v, int& P) {
	long long int n = v.size(), maximo  = 0;
	vector<long long int> aux(P + 1, 0);
	vector<vector<long long int>> mat(n + 1, aux);
	for (long long int i = 1; i <= n; i++) {
		for (long long int j = 0; j <= P; j++) {
			if (j >= v[i - 1].second) {
				mat[i][j] = max(mat[i - 1][j], mat[i - 1][j - v[i - 1].second] + v[i - 1].first);
			}
			else {
				mat[i][j] = mat[i - 1][j];
			}
		}
	}
	for (int j = 0; j <= P; j++) {
		maximo = max(maximo, mat[n][j]);
	}
	return maximo;
}


bool resuelveCaso() {
	int l, P, N;
	cin >> P >> N;
	if (!cin) { return false; }
	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
	}
	l = esfuerzo(v, P);
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