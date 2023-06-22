// Adrián Pérez Peinador
/*
Realizo la poda de forma que cada vez que pase a un nuevo funcionario debo asegurarme que el tiempo minimo acomulado sea mayor o igual que el tiempo + lo minimo de los tiempos de cada trabajo podría quedar.
Con esto estoy hallando una cota inferior del tiempo que podría llegar a tener, el tiempo en el mejor de los casos.
Para ello calculo previamente un vector de minimos para cada trabajo, y en dicho vector guardo la suma de los tiempos correspondientes, asignando a la ultima posicion el valor 0.
Obviamente además de esto, aseguro que los trabajos no esten siendo usados con mi vector usados.
El orden del algoritmo sera O(num^num)
*/
#include<iostream>
#include <vector>
using namespace std;

const int MAX1 = 20;

typedef int tListaMat[MAX1][MAX1];


void resolver(tListaMat& mat, vector<bool>& usados, vector<int>& minimos, int num, int& tiempo, int& tiempomin, int p) {
	if (p == num) {
		if (tiempo < tiempomin) {
			tiempomin = tiempo;
		}
	}
	else {
		for (int i = 0; i < num; i++) {
			tiempo += mat[i][p];
			if (!usados[i] && tiempomin > tiempo + minimos[p + 1]) {
				usados[i] = true;
				resolver(mat, usados, minimos, num, tiempo, tiempomin, p + 1);
				usados[i] = false;
			}
			tiempo -= mat[i][p];
		}
	}
}



void hallarvectordeminimos(tListaMat& mat, vector<int>& minimos, int num) {
	for (int i = num - 2; i >= 0; i--) {
		minimos[i] += minimos[i + 1];
	}
}

bool resuelvecaso() {
	int num, tiempo = 0, tiempomin = 1000000000, p = 0;
	tListaMat mat;
	bool aux = false;
	vector<bool>usados;
	cin >> num;
	if (num == 0) {
		return false;
	}
	vector<int> minimos(num + 1);
	for (int i = 0; i < num; i++) {
		minimos[i] = 100000;
	}
	for (int i = 0; i < num; i++) {
		usados.push_back(aux);
		for (int j = 0; j < num; j++) {
			cin >> mat[i][j];
			if (mat[i][j] < minimos[j]) { minimos[j] = mat[i][j]; }
		}
	}
	minimos[num] = 0;
	hallarvectordeminimos(mat, minimos, num);
	resolver(mat, usados, minimos, num, tiempo, tiempomin, p);
	cout << tiempomin << endl;
	return true;
}

int main() {
	while (resuelvecaso());
	return 0;
}