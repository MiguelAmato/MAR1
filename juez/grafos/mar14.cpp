// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez MAR102

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Grafo.h"
using namespace std;

int dfs(const Grafo& grafo, vector<bool>& visitados, const int& v) {
	int ret = 1;
	visitados[v] = true;
	for (int w : grafo.ady(v)) {
		if (!visitados[w])
			ret += dfs(grafo, visitados, w);
	}
	return ret;
}

int maximo(const Grafo& grafo) {
	int max = 0;
	vector<bool> visit(grafo.V(), false);
	for (int w = 0; w < grafo.V(); ++w) {
		if (!visit[w]) {
			int act = dfs(grafo, visit, w);
			max = std::max(act, max);
		}
	}
	return max;
}


void resuelveCaso() {
	int N, M;
	cin >> N >> M;
	Grafo grafo(N);
	int a, b;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		grafo.ponArista(a - 1, b - 1);
	}
	cout << maximo(grafo) << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}