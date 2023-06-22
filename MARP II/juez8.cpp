// Adrián Pérez

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "hashmap_eda.h"
#include "Grafo.h"


using namespace std;



/*long long int subse(vector<char>& v, vector<char>& w, vector<char>& sol) {
	long long int n = v.size(), m = w.size();
	vector<long long int> aux(m + 1, 0);
	vector<vector<long long int>> mat(n + 1, aux);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (v[i - 1] == w[j - 1]) { mat[i][j] = mat[i - 1][j - 1] + 1; }
			else {
				mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
			}
		}
	}
	int p = mat[n][m], i = n - 1, j = m - 1;
	while (p > 0) {
		if (mat[i + 1][j + 1] > mat[i][j + 1]) {
			sol.push_back(v[i]);
			while (w[j] != v[i]) { j--; }
			i--;
			j--;
			p--;
		}
		else { i--; }
	}
	return mat[n][m];
}*/


bool resuelveCaso() {
	long long int l, P, R;
	string nom1, nom2;
	unordered_map<string, int> nombres;
	cin >> P >> R;
	if (!cin) { return false; }
	Grafo g = Grafo(P);
	for (int i = 0; i < R; i++) {
		cin >> nom1 >> nom2;
		if (nombres.count(nom1) == 0) {
			nombres.insert({ nom2, nombres.size() + 1 });
		}
		if (nombres.count(nom2) == 0) {
			nombres.insert({ nom2, nombres.size() + 1 });
		}
		g.ponArista(nombres.at(nom1), nombres.at(nom2));
	}
	
	/*for (int i = l - 1; i >= 0; i--) {
		
	}*/
	cout << '\n';
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