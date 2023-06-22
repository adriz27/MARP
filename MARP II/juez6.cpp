// Adrián Pérez

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>


using namespace std;



long long int aibo(vector<char>& v, vector<char>& sol) {
	long long int n = v.size(), p;
	stack<char> pila;
	vector<long long int> aux(n, 0);
	vector<vector<long long int>> mat(n, aux);
	for (int i = n-1; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			if (v[i] == v[j]) { mat[i][j] = mat[i + 1][j - 1]; }
			else {
				mat[i][j] = min(mat[i + 1][j], mat[i][j - 1]) + 1;
			}
		}
	}
	int i = 0, j = n - 1;
	while (i <= j) {
		if (i == j) {
			sol.push_back(v[i]);
			i++;
		}
		else if (v[i] == v[j]) {
			sol.push_back(v[i]);
			pila.push(v[i]);
			i++;
			j--;
		}
		else if(mat[i][j] == mat[i][j - 1] + 1){
			sol.push_back(v[j]);
			pila.push(v[j]);
			j--;
		}
		else if(mat[i][j] == mat[i + 1][j] + 1){
			sol.push_back(v[i]);
			pila.push(v[i]);
			i++;
		}
	}

	while (!pila.empty()) {
		sol.push_back(pila.top());
		pila.pop();
	}

	return mat[0][n-1];
}


bool resuelveCaso() {
	long long int l;
	vector<char> v, sol;
	string s;
	char c = ' ';
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		v.push_back(s[i]);
	}
	if (!cin) { return false; }
	l = aibo(v, sol);
	
	cout << l << ' ';
	for (int i = 0; i < sol.size(); i++) {
		cout << sol[i];
	}
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