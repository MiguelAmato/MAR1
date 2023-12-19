// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez MAR102

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Grafo.h"
using namespace std;


int dfs(const Grafo& grafo, vector<bool>& visitados, const int& v, const int& p) {
	int ret = 1;
	visitados[v] = true;
	for (int w : grafo.ady(v)) {
		if (!visitados[w]) {
			int aux = dfs(grafo, visitados, w, v);
			ret = (aux != -1 ? aux + ret : -1);
		}
		else if (w != p)
			return -1;			
	}
	return ret;
}

bool resuelveCaso() {
    int V;
	cin >> V;
    if (!cin)
        return false;
    int A;
	cin >> A;
	Grafo grafo(V);
	int v, w;
	for (int i = 0; i < A; ++i) {
		cin >> v >> w;
		grafo.ponArista(v, w);
	}
	vector<bool> visitados(V, false);
	cout << (dfs(grafo, visitados, 0, 0) == V ? "SI" : "NO") << "\n";
    return true;
}

int main() {
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
     #endif 
    
    while (resuelveCaso());

     #ifndef DOMJUDGE 
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif

    return 0;
}
