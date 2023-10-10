// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez MAR102

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>
#include "bintree_eda.h"
using namespace std;

struct tSol {
	int min = INT_MAX;
	int max = -1;
	int altura = 0;
	bool esAVL = true;
};

tSol esAVL(const bintree<int>& arbol) {
    if (arbol.empty())
        return { INT_MAX, -1, 0, true };
    else {
        auto izq = esAVL(arbol.left());
        auto dch = esAVL(arbol.right());
        return {
            min(arbol.root(), min(izq.min, dch.min)),
            max(arbol.root(), max(izq.max, dch.max)),
            max(izq.altura, dch.altura) + 1,
            izq.esAVL && dch.esAVL && izq.max < arbol.root() && dch.min > arbol.root() && abs(izq.altura - dch.altura) < 2
        };
    }
}

void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	cout << (esAVL(arbol).esAVL ? "SI\n" : "NO\n");
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