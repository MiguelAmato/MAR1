// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez MAR102

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include "PriorityQueue.h"
using namespace std;

struct Tarea {
	long long int ini;
	long long int fin;
	long long int per = 0;
};

bool operator <( const Tarea &t1, const Tarea &t2) {
    return t1.ini < t2.ini;
}

bool hayConflicto(PriorityQueue<Tarea>& pq, const int& n) {
	Tarea t;
	t = pq.top();
	pq.pop();
	if (t.per > 0)
		pq.push({t.ini + t.per, t.fin + t.per, t.per});
	while (t.ini < n && !pq.empty()) {
		if (t.fin <= pq.top().ini) {
			t = pq.top();
			pq.pop();
			if (t.per > 0)
				pq.push({t.ini + t.per, t.fin + t.per, t.per});
		}
		else 
			return true;
	}
	return false;
}

bool resuelveCaso() {
    int n, m, t;
	cin >> n >> m >> t;
    if (!cin)
        return false;
    PriorityQueue<Tarea> pq;
	Tarea tarea;
	for (int i = 0; i < n; ++i) {
		cin >> tarea.ini >> tarea.fin;
		if (tarea.ini < t)
			pq.push(tarea);
	}
	for (int i = 0 ; i < m;  ++i) {
		cin >> tarea.ini >> tarea.fin >> tarea.per;
		if (tarea.ini < t)
			pq.push(tarea);
	}
	cout << (hayConflicto(pq, t) ? "SI\n" : "NO\n");
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