// Adrián Pérez

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

typedef struct cordel{
	int l;
	int precio;
};

typedef struct sol {
	long long int mat;
	long long int ing;
	long long int eco;
};

sol cometa(vector<cordel>& v, int& L) {
	int n = v.size();
	sol def = {0, 100000, 100000};
	vector<sol> aux(L + 1, def);
	vector<vector<sol>> mat(n + 1, aux);
	mat[0][0] = { 1, 0, 0 };
	for (int i = 1; i <= n; i++) {
		mat[i][0] = {1, 0, 0};
		for (int j = 1; j <= L; j++) {
			if (v[i - 1].l > j) { 
				mat[i][j].mat = mat[i - 1][j].mat;
				mat[i][j].ing = mat[i - 1][j].ing;
				mat[i][j].eco = mat[i - 1][j].eco;
			}
			else { 
				mat[i][j].mat = mat[i - 1][j].mat + mat[i - 1][j - v[i - 1].l].mat;
				mat[i][j].ing = min(mat[i - 1][j].ing, mat[i - 1][j - v[i - 1].l].ing + 1);
				mat[i][j].eco = min(mat[i - 1][j].eco, mat[i - 1][j - v[i - 1].l].eco + v[i-1].precio);
			}
		}
	}
	return mat[n][L];
}


bool resuelveCaso() {
	int N, L;
	sol n;
	cordel c;
	cin >> N >> L;
	vector<cordel> v, sol;
	if (!cin) { return false; }
	for (int i = 0; i < N; i++) {
		cin >> c.l >> c.precio;
		v.push_back(c);
	}
	n = cometa(v, L);
	if (n.mat == 0) { cout << "NO" << '\n'; }
	else {
		cout << "SI " << n.mat << " " << n.ing << " " << n.eco << '\n';
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