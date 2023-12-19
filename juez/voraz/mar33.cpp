// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez MAR102

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


bool resuelveCaso() {
    int N;
	cin >> N;
    if (N == 0)
        return false;
    vector<pair<int, int>> v(N); // first = final, second = inicio
	for (int i = 0; i < N; ++i) cin >> v[i].second >> v[i].first;
	sort(v.begin(), v.end());
	int cont = 1, ult = v[0].first;
	for (int i = 1; i < N; ++i) {
		if (ult <= v[i].second) {
			ult = v[i].first;
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
