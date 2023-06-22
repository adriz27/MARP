// Adrián Pérez

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

typedef struct cofre {
	long long int prof;
	long long int oro;
};

long long int tesoro_rec(vector<cofre> const& v, int i, int j, vector<vector<long long int>>& mat) {
	if (mat[i][j] != -1) { return mat[i][j]; }
	if (i == 0 || j == 0) { mat[i][j] = 0; }
	else if (v[i - 1].prof > j) { mat[i][j] = tesoro_rec(v, i - 1, j, mat);	}
	else { mat[i][j] = max(tesoro_rec(v, i - 1, j, mat), tesoro_rec(v, i-1, j-v[i-1].prof, mat)+ v[i-1].oro); }
	return mat[i][j];
}

long long int tesoro(vector<cofre>& v, long long int& T, vector<cofre>& sol) {
	long long int n = v.size(), p;
	vector<long long int> aux(T + 1, -1);
	vector<vector<long long int>> mat(n + 1, aux);
	long long int valor = tesoro_rec(v, n, T, mat);
	int i = n, j = T;
	while (i > 0 && j > 0) {
		if (mat[i][j] != mat[i - 1][j]) {
			sol.push_back({ v[i - 1].prof / 3, v[i-1].oro });
			j -= v[i - 1].prof;
		}
		i--;
	}
	return valor;
}


bool resuelveCaso() {
	long long int N, T, oro;
	cin >> T >> N;
	vector<cofre> v(N), sol;
	if (!cin) { return false; }
	for (int i = 0; i < N; i++) {
		cin >> v[i].prof >> v[i].oro;
		v[i].prof *= 3;
	}
	oro = tesoro(v, T, sol);
	int cofres = sol.size();
	cout << oro << '\n' << cofres << '\n';
	for (int i = cofres - 1; i >= 0; i--) {
		cout << sol[i].prof << " " << sol[i].oro << '\n';
	}
	cout << "---" << '\n';
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