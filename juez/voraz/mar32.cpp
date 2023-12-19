// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez MAR102

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;


bool resuelveCaso() {
    int N;
	cin >> N;
    if (N == 0)
        return false;
    vector<pair<int, int>> intervalos(N); // first = hora de fin, second = hora de inicio
	int horas, minutos;
	char aux;
	for (int i = 0; i < N; ++i) {
		cin >> horas >> aux >> minutos;
		intervalos[i].second = horas * 60 + minutos;
		cin >> intervalos[i].first;
		intervalos[i].first += intervalos[i].second;
	}
	sort(intervalos.begin(), intervalos.end());
	int cont = 1;
	int ult = intervalos[0].first + 10;
	for (int i = 1; i < N; ++i) {
		if (ult <= intervalos[i].second) {
			ult = intervalos[i].first + 10;
			++cont;
		}
	}
	cout << cont << "\n";
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    while (resuelveCaso());
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}
