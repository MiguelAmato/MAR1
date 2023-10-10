// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez MAR102

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct par {
    int tiempo;
    int caja;
};

bool operator >( const par &p1, const par &p2) {
    return p1.tiempo > p2.tiempo;
}


bool resuelveCaso() {
    int n, c;
	cin >> n >> c;
    if (n == 0 && c == 0)
        return false;
    int cajaDisponible = 1;
	int cajasOcupadas = 0;
	priority_queue<par, vector<par>, greater<par>> pq;
	int cliente;
	for (int i = 0; i < n; ++i) {
		cin >> cliente;
		if (cajasOcupadas < c) {
			pq.push({ cliente, cajaDisponible++ });
			++cajasOcupadas;
		}
		else {
			par aux = pq.top();
			pq.pop();
			pq.push({ cliente, aux.caja });
		}
	}
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
