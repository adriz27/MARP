// Adrián Pérez

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int recorridos(vector<vector<bool>>& v, long long int& N, long long int& M) {
	vector<long long int> aux(M + 1, 0);
	vector<vector<long long int>> mat(N + 1, aux);
	mat[1][1] = 1;
	long long int c;
	for (long long int i = 2; i <= N; i++) {
		for (long long int j = 1; j <= i; j++) {
			c = i - j + 1;
			if (v[j - 1][c - 1]) {
				mat[j][c] = mat[j - 1][c] + mat[j][c - 1];
			}
		}
	}
	for (long long int i = N+1; i <= M; i++) {
		for (long long int j = 1; j <= N; j++) {
			c = i - j + 1;
			if (v[j - 1][c - 1]) {
				mat[j][c] = mat[j - 1][c] + mat[j][c - 1];
			}
		}
	}
	for (long long int i = 1; i <= N; i++) {
		for (long long int j = i; j <= N; j++) {
			c = M + i - j;
			if (v[j - 1][c - 1]) {
				mat[j][c] = mat[j - 1][c] + mat[j][c - 1];
			}
		}
	}
	return mat[N][M];
}


bool resuelveCaso() {
	long long int l, N, M;
	char c;
	bool cambiado = false;
	cin >> N >> M;
	if (!cin) { return false; }
	if (N > M) {
		swap(N, M);
		cambiado = true;
	}
	vector<bool> aux(M, true);
	vector<vector<bool>> seguro(N, aux);
	if(cambiado){
		for (long long int i = 0; i < M; i++) {
			cin.get(c);
			for (long long int j = 0; j < N; j++) {
				cin.get(c);
				if (c == 'P') { seguro[j][i] = false; }
			}
		}
	}
	else {
		for (long long int i = 0; i < N; i++) {
			cin.get(c);
			for (long long int j = 0; j < M; j++) {
				cin.get(c);
				if (c == 'P') { seguro[i][j] = false; }
			}
		}
	}
	l = recorridos(seguro, N, M);
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