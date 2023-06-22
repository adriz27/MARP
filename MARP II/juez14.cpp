// Adrián Pérez

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void mejora(vector<vector<long long int>>& mat) {
	long long int n = mat.size();
	for (long long int i = 2; i < n; i++) {
		for (long long int j = 0; j < n - i; j++) {
			long long int minim = mat[j][j+i];
			for (long long int k = j + 1; k < i + j; k++) {
				minim = min(minim, mat[k][i+j] + mat[j][k]);
			}
			mat[j][j+i] = minim;
		}
	}
}


bool resuelveCaso() {
	long long int N;
	cin >> N;
	if (!cin) { return false; }
	vector<long long int> aux(N, 0);
	vector<vector<long long int>> mat(N, aux);
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			cin >> mat[i][j];
		}
	}
	mejora(mat);

	for (int i = 0; i < N - 1; i++) {
		cout << mat[i][i + 1];
		for (int j = i + 2; j < N; j++) {
			cout << ' ' << mat[i][j];
		}
		cout << '\n';
	}

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