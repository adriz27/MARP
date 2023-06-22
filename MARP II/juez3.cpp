// Adrián Pérez

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int camino(vector<vector<int>>& M, int& pos) {
	int n = M.size(), maximo = 0;
	vector<int> aux(n, 0);
	vector<vector<int>> mat(n + 1, aux);
	//mat[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		//mat[i][0] = 0;
		for (int j = 0; j < n; j++) {
			if (j == 0) {
				mat[i][j] = max(mat[i - 1][j], mat[i - 1][j + 1]) + M[i-1][j];
			}
			else if (j == n - 1) {
				mat[i][j] = max(mat[i - 1][j], mat[i - 1][j - 1]) + M[i-1][j];
			}
			else {
				mat[i][j] = max(max(mat[i - 1][j], mat[i - 1][j + 1]), mat[i - 1][j - 1]) + M[i-1][j];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (mat[n][i] > maximo) {
			maximo = mat[n][i];
			pos = i;
		}
	}
	return maximo;
}


bool resuelveCaso() {
	int N, x, pos;
	cin >> N;
	vector<int> aux(N, 0);
	vector<vector<int>> mat(N, aux);
	if (!cin) { return false; }
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mat[i][j];
		}
	}
	x = camino(mat, pos);
	cout << x << " " << pos+1 << '\n';
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