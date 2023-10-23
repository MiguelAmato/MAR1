// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez MAR102

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include "PriorityQueue.h"
using namespace std;

struct users {
    int id;
    long long int per;
    long long int perActual;
};

bool operator <(const users& u1, const users& u2) {
    if (u1.perActual == u2.perActual) 
        return u1.id < u2.id;
    return u1.perActual < u2.perActual;
}

bool resuelveCaso() {
    int n;
	cin >> n;
    if (n == 0)
        return false;
	PriorityQueue<users> pq;
    users u;
    for (int i = 0; i < n; ++i) {
        cin >> u.id >> u.per;
        u.perActual = u.per;
        pq.push(u);
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << pq.top().id << "\n";
        pq.push( {pq.top().id, pq.top().per, pq.top().perActual + pq.top().per});
        pq.pop();
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
