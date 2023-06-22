// Adrián Pérez Peinador
/*
Por cada maquina voy recorriendo el vector de las carreteras y voy sumando las calidades correspondientes.
Fuera del bucle for hago un resolver ya que tengo que llegar al final del vector para acomular la suma de las calidades, sin importar que en una maquina del medio no pueda limpiar ninguna carretera.
La poda la realizo con dos vectores  usadasMaq y usadasCar que van contando el numero de veces que las usa. Obvimente no puede sumas mas de 1 ninguna posicion de cada vector.
El orden será O(log(nxm)) con n y m el numero de maquina y el numero de carreteras
*/
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 2500;
typedef int tMatCal[MAX][MAX];
tMatCal matCal;



void resolver(vector<int>& listaMaq, vector<int>& listaCar, vector<int>& usadasMaq, vector<int>& usadasCar, tMatCal matCal, int numMaq, int numCar, int& sumaCal, int& max, int k) {
	if (k == numMaq) {
		if (sumaCal > max) {
			max = sumaCal;
		}
	}
	else {
		for (int i = 0; i < numCar; i++) {
			if (listaMaq[k] <= listaCar[i] && usadasMaq[k] < 1 && usadasCar[i] < 1) {
				usadasMaq[k] ++;
				usadasCar[i] ++;
				sumaCal += matCal[k][i];
				resolver(listaMaq, listaCar, usadasMaq, usadasCar, matCal, numMaq, numCar, sumaCal, max, k + 1);
				sumaCal -= matCal[k][i];
				usadasMaq[k] --;
				usadasCar[i] --;
			}
		}
		resolver(listaMaq, listaCar, usadasMaq, usadasCar, matCal, numMaq, numCar, sumaCal, max, k + 1);
	}
}



void resuelveCaso() {
	int numMaq, numCar, aux, sumaCal = 0, max = -1, k = 0;
	vector<int>usadasMaq, usadasCar;
	vector<int> listaMaq, listaCar, listaCalidades;
	cin >> numMaq >> numCar;
	for (int i = 0; i < numMaq; i++) {
		cin >> aux;
		listaMaq.push_back(aux);
		usadasMaq.push_back(0);
	}
	for (int i = 0; i < numCar; i++) {
		cin >> aux;
		listaCar.push_back(aux);
		usadasCar.push_back(0);
	}
	for (int i = 0; i < numMaq; i++) {
		for (int j = 0; j < numCar; j++) {
			cin >> matCal[i][j];
		}
	}
	resolver(listaMaq, listaCar, usadasMaq, usadasCar, matCal, numMaq, numCar, sumaCal, max, k);
	if (max == -1) {
		max = 0;
	}
	cout << max << endl;
}
int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}