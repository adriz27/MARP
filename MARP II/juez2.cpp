// Adrián Pérez

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int punt(int p, int j, vector<int>& v, vector<int>& sol) {
	int n = v.size();
	vector<int> aux(p + 1, 10000);
	vector<vector<int>> mat(n+1, aux);
	mat[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		mat[i][0] = 0;
		for (int j = 1; j <= p; j++) {
			if (v[i - 1] > j) { mat[i][j] = mat[i - 1][j]; }
			else { mat[i][j] = min(mat[i - 1][j], mat[i][j - v[i - 1]] + 1); }
		}
	}
	if (mat[n][p] != 10000) {
		int i = n, j = p;
		while (j > 0) {
			if (v[i - 1] <= j && mat[i][j] - mat[i][j - v[i-1]] == 1) {
				sol.push_back(v[i - 1]);
				j = j - v[i - 1];
			}
			else { i--; }
		}
	}

	return mat[n][p];
}


bool resuelveCaso() {
	int N, S, s, n = 0;
	cin >> N >> S;
	vector<int> v, sol;
	if (!cin) { return false; }
	for (int i = 0; i < S; i++) {
		cin >> s;
		v.push_back(s);
	}
	n = punt(N, S-1, v, sol);
	if (n == 10000) { cout << "Imposible" << '\n'; }
	else { 
		cout << n << ":"; 
		for (int i = 0; i < sol.size(); i++) {
			cout << " " << sol[i];
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