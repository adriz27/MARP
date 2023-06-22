// Adrián Pérez Peinador

#include<iostream>
#include <vector>

using namespace std;

const int MAX = 20;
typedef int tListaMat[MAX][3 * MAX];

void creaMinimosParciales(vector<int>& minimos, int numprod) {
	for (int i = numprod - 2; i >= 0; i--) {
		minimos[i] += minimos[i + 1];
	}
}

void resolver(vector<int>& C, vector<int>& minimos, tListaMat& mat, int& numSuper, int& numProduct, int p, int& coste, int& costemin) {
	if (p == numProduct) {
		if (coste < costemin) {
			costemin = coste;
		}
	}
	else {
		for (int j = 0; j < numSuper; j++) {
			C[j]++;
			coste += mat[j][p];
			if (C[j] < 4 && coste + minimos[p + 1] < costemin) {
				resolver(C, minimos, mat, numSuper, numProduct, p + 1, coste, costemin);
			}
			coste -= mat[j][p];
			C[j]--;
		}
	}
}

void resuelveCaso() {
	tListaMat mat;
	int costemin = 100000000;
	int numprod, numSuper, coste = 0, c = 0, aux;
	std::cin >> numSuper >> numprod;
	vector<int> C(numSuper), minimos(numprod + 1);
	for (int j = 0; j < numprod; j++) { minimos[j] = 1000000; }
	for (int i = 0; i < numSuper; i++) {
		C[i] = 0;
		for (int j = 0; j < numprod; j++) {
			cin >> aux;
			mat[i][j] = aux;
			if (aux < minimos[j]) { minimos[j] = aux; }
		}
	}
	minimos[numprod] = 0;
	creaMinimosParciales(minimos, numprod);
	resolver(C, minimos, mat, numSuper, numprod, c, coste, costemin);
	cout << costemin << endl;
}

int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}
	return 0;
}