// Adrián Pérez

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int dias(vector<int>& v) {
	long long int n = v.size(), a, b, c, k;
	vector<long long int> aux(n+1, 0);
	vector<vector<long long int>> mat(n+1, aux);
	for (long long int i = 2; i <= n; i++) {
		for (long long int j = 0; j <= n - i; j++) {
			k = i + j;
			a = mat[j + 1][k - 1];
			if (v[k - 1] == v[j] && v[j] != 0) { a += 1; }
			b = mat[j + 2][k];
			if (v[j] == v[j + 1] && v[j] != 0) { b += 1; }
			c = mat[j][k - 2];
			if (v[k - 1] == v[k - 2] && v[k - 1] != 0) { c += 1; }
			mat[j][k] = max(max(a, b), c);
		}
	}
	return mat[0][n];
}


bool resuelveCaso() {
	int l, N;
	cin >> N;
	if (!cin) { return false; }
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	l = dias(v);
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