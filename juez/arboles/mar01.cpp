// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez MAR102

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include "bintree_eda.h"
using namespace std;

pair<bool, int> balance(const bintree<char>& arbol) {
    if (arbol.empty())
        return { true, 0 };
    else {
        pair<bool, int> izq = balance(arbol.left());
        pair<bool, int> dch = balance(arbol.right());
        return {
            izq.first && dch.first && (abs(izq.second - dch.second) < 2),
            max(izq.second, dch.second) + 1
        };
    }
}

void resuelveCaso() {
    bintree<char> arbol = leerArbol('.');
    cout << (balance(arbol).first ? "SI\n" : "NO\n");
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