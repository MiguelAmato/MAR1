// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez MAR102

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

bool resuelveCaso() {
    int n = 0;
	cin >> n;
    if (n == 0)
        return false;
    unordered_map<int, queue<string>> map; // Mapa clave gravedad, valor pacientes que tengan esa gravedad
	priority_queue<int, vector<int>, less<int>> pq; // Priority queue que almacena la gravedad de los pacientes
	char accion;
	for (int i = 0; i < n; ++i) {
		cin >> accion;
		if (accion == 'I') {
			string nombre;
			int gravedad;
			cin >> nombre >> gravedad;
			if (!map.count(gravedad))
				pq.push(gravedad);
			map[gravedad].push(nombre);
		}
		else if (accion == 'A') {
			cout << map[pq.top()].front() << "\n";
			map[pq.top()].pop();
			if (map[pq.top()].empty())
				pq.pop();
		}
	}
	cout << "---\n";
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
