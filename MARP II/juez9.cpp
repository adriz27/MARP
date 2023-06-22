// Adrián Pérez

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int esfuerzo(vector<long long int>& v) {
	long long int n = v.size()-1;
	vector<long long int> aux(n + 1, 0);
	vector<vector<long long int>> mat(n + 1, aux);
	for (long long int i = 2; i <= n; i++) {
		for (long long int j = 0; j <= n - i; j++) {
			long long int minim = 10000000;
			for (long long int k = j + 1; k < i + j; k++) {
				minim = min(minim, mat[i + j][k] + mat[k][j]);
			}
			mat[i + j][j] = minim + (v[i + j] - v[j]);
		}
	}
	return mat[n][0];
}


bool resuelveCaso() {
	long long int l, L, N;
	cin >> L >> N;
	if (L == 0 && N == 0) { return false; }
	vector<long long int> v(N+2);
	for (long long int i = 1; i <= N; i++) {
		cin >> v[i];
	}
	v[0] = 0;
	v[N + 1] = L;
	l = esfuerzo(v);
	cout << 2*l << '\n';
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