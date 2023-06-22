// Adrián Pérez

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int const M[3][3] = { {1, 1, 0}, {2, 1, 0}, {0, 2, 2} };

long long int esfuerzo(vector<long long int>& v) {
	long long int n = v.size();
	vector<bool> cero(3, false);
	vector<vector<bool>> aux(n, cero);
	vector<vector<vector<bool>>> mat(n, aux);
	for (int i = 0; i < n; i++) {
		mat[i][i][v[i]] = true;
	}
	for (long long int i = 1; i < n; i++) {
		for (long long int j = 0; j < n - i; j++) {
			for (long long int k = j; k < j + i; k++) {
				for (int p = 0; p < 3; p++) {
					for (int q = 0; q < 3; q++) {
						if (mat[i + j][k + 1][p] && mat[k][j][q]) {
							mat[i + j][j][M[q][p]] = true;
						}
					}
				}
			}
		}
	}
	return mat[n-1][0][0];
}

int trad(char& c) {
	if (c == 'a') { return 0; }
	else if (c == 'b') { return 1; }
	return 2;
}

bool resuelveCaso() {
	char c;
	cin.get(c);
	if (!cin) { return false; }
	vector<long long int> v;
	while (c != '\n') {
		v.push_back(trad(c));
		cin.get(c);
	}

	if (esfuerzo(v)) { cout << "SI" << '\n'; }
	else { cout << "NO" << '\n'; }

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