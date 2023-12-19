// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez MAR102

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include "PriorityQueue.h"
using namespace std;

struct users {
	string nombre;
	int gravedad;
	int tiempo;
};

bool operator >(const users& u1, const users& u2) {
	if (u1.gravedad == u2.gravedad)
		return u1.tiempo < u2.tiempo;
	return u1.gravedad > u2.gravedad;
}

bool resuelveCaso() {
    int n = 0;
	cin >> n;
    if (n == 0)
        return false;
	PriorityQueue<users, greater<users>> pq;
	char accion;
	users paciente;
	int orden = 0;
	for (int i = 0; i < n;  ++i) {
		cin >> accion;
		switch (accion)
		{
		case 'I':
			cin >> paciente.nombre >> paciente.gravedad;
			paciente.tiempo = orden++;
			pq.push(paciente);
			break;
		case 'A':
			cout << pq.top().nombre << "\n";
			pq.pop();
			break;
		default:
			break;
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
