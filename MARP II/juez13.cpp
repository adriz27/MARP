// Adrián Pérez

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


long long int pienso(vector<long long int>& v) {
	long long int n = v.size();
	vector<long long int> aux(n, 0);
	vector<vector<long long int>> mat(n, aux);
	for (int i = 0; i < n; i++) {
		mat[i][i] = v[i];
	}
	for (long long int k = 1; k < n; k++) {
		for (long long int l = 0; l < n - k; l++) {
			long long int i = l, j = k + l;
			if (i + 1 < j) {
				long long int m1, m2;
				if (v[j] > v[i + 1]) { m1 = mat[i + 1][j - 1]; }
				else { m1 = mat[i + 2][j]; }
				if (v[j - 1] > v[i]) { m2 = mat[i][j - 2]; }
				else { m2 = mat[i + 1][j - 1]; }
				mat[i][j] = max(v[i] + m1, v[j] + m2);
			}
			else {
				mat[i][j] = max(mat[i+1][j], mat[i][j-1]);
			}
		}
	}
	return mat[0][n-1];
}


bool resuelveCaso() {
	int N;
	cin >> N;
	if (N == 0) { return false; }
	vector<long long int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	cout << pienso(v) << '\n';
	
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