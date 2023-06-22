// Adrián Pérez

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

typedef struct bombilla {
	int pot;
	int cost;
};

int iluminacion(vector<bombilla>& v, long long int& coste, int& m, int& M) {
	int n = v.size(), power = m;
	vector<long long int> aux(M + 1, 1000000);
	vector<vector<long long int>> mat(n + 1, aux);
	mat[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		mat[i][0] = 0;
		for (int j = 1; j <= M; j++) {
			if (v[i - 1].pot > j) { mat[i][j] = mat[i - 1][j]; }
			else { mat[i][j] = min(mat[i - 1][j], mat[i][j - v[i - 1].pot] + v[i-1].cost); }
		}
	}
	for (int i = m; i <= M; i++) {
		if (mat[n][i] < coste) {
			coste = mat[n][i];
			power = i;
		}
	}
	return power;
}


bool resuelveCaso() {
	int N, Min, Max, potencia;
	long long int coste = 1000000;
	cin >> N >> Max >> Min;
	vector<bombilla> v(N);
	if (!cin) { return false; }
	for (int i = 0; i < N; i++) {
		cin >> v[i].pot;
	}
	for (int i = 0; i < N; i++) {
		cin >> v[i].cost;
	}
	potencia = iluminacion(v, coste, Min, Max);
	if (coste == 1000000) { cout << "IMPOSIBLE" << '\n'; }
	else {
		cout << coste << " " << potencia << '\n';
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