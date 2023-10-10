// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez MAR102

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool resuelveCaso() {
    int n;
	cin >> n;
    if (n == 0)
        return false;
    priority_queue<int, vector<int>, greater<int>> pq;
	int e;
	for (int i = 0; i < n; ++i) {
		cin >> e;
		pq.push(e);
	}
	int total = 0, suma1 = 0, suma2 = 0;
	if (n > 1) {
		while (!pq.empty()) {
			suma1 = pq.top();
			pq.pop();
			suma2 = pq.top();
			pq.pop();
			total += suma1 + suma2;
			if (!pq.empty())
				pq.push(suma1 + suma2);
		}
	}
	cout << total << "\n";
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
