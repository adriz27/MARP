// Adrián Pérez

#include <fstream>
#include "Grafo.h"

using namespace std;

void cierre(Grafo const& g, int const& a, int const& man, int& n, vector<bool>& ab, vector<int>& mancha) {
	vector<int> v = g.ady(a);
	for (int i = 0; i < v.size(); i++) {
		if (!ab[v[i]]) {
			ab[v[i]] = true;
			mancha[v[i]] = man;
			n++;
			cierre(g, v[i], man, n, ab, mancha);
		}
	}
}

bool resuelveCaso() {
	int F, C, N, num = 0, max = 0, x ,y;
	char c;
	cin >> F >> C;
	if (!cin) { return false; }
	Grafo g = Grafo(F*C);
	for (int i = 0; i < F; i++) {
		for (int j = 0; j < C; j++) {
			if (j != C - 1) { g.ponArista(C * i + j, C * i + j + 1); }
			if (i != F - 1) { 
				g.ponArista(C * i + j, C * i + j + C);
				if (j != 0){ g.ponArista(C * i + j, C * i + j + C - 1); }
				if (j != C-1) { g.ponArista(C * i + j, C * i + j + C + 1); }
			}
		}
	}
	vector<bool> v;
	vector<int> mancha, tam, equiv;

	tam.push_back(0);
	equiv.push_back(0);
	for (int i = 0; i < F; i++) {
		cin.get(c);
		for (int j = 0; j < C; j++) {
			mancha.push_back(0);
			cin.get(c);
			if (c == ' ') { v.push_back(true); }
			else { v.push_back(false); }
		}
	}

	for (int i = 0; i < F * C; i++) {
		int n = 1;
		if (!v[i]) {
			v[i] = true;
			num++;
			mancha[i] = num;
			cierre(g, i, num, n, v, mancha);
			tam.push_back(n);
			equiv.push_back(num);
			if (n > max) { max = n; }
		}
	}
	
	cout << max;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		x--;
		y--;
		vector<int> ady = g.ady(C*x + y);
		num = 0;
		for (int j = 0; j < ady.size(); j++) {
			int m = mancha[ady[j]];
			if (m != 0) {
				if (equiv[m] != equiv[num] && num != 0) {
					tam[num] += tam[m];
					equiv[m] = num;
				}
				else { 
					num = equiv[m];
					mancha[C * x + y] = equiv[num];
				}
			}
		}
		if (num != 0) { tam[num]++; }
		else {
			num = tam.size();
			mancha[C * x + y] = num;
			equiv.push_back(num);
			tam.push_back(1);
		}
		if (tam[num] > max) { max = tam[num]; }
		cout << ' ' << max;
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