// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez MAR102

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Grafo.h"
#include <queue>
using namespace std;

class Redes {
	public:
	Redes(const Grafo& g, int ini) : visit(g.V(), false), distancia(g.V(), -1), ini(ini) {
		bfs(g);
	}

	int getInaccesibles(int ttl) {
		int count = 0;
		for (int i : distancia) {
			if (i > ttl || i == -1)
				++count;
		}
		return count;
	}

	private:
		vector<bool> visit;
		vector<int> distancia;
		int ini;

		void bfs(const Grafo& g) {
			queue<int> q;
			visit[ini] = true;
			distancia[ini] = 0;
			q.push(ini);
			while (!q.empty()) {
				int v = q.front(); q.pop();
				for (int w : g.ady(v)) {
					if (!visit[w]) {
						visit[w] = true;
						distancia[w] = distancia[v] + 1;
						q.push(w);
					}
				}
			}
		}
};



bool resuelveCaso() {
    int N; // Nodos de la red
	cin >> N;
    if (!cin)
        return false;
    int C; // Conexiones de la red
	cin >> C;
	Grafo grafo(N);
	int v, w; 
	for (int i = 0; i < C; ++i) {
		cin >> v >> w;
		grafo.ponArista(v - 1, w - 1);
	}
	int K; // Consultas a hacerse
	cin >> K;
	int ini, ttl; // Nodo inicial y TTL
	for (int i = 0; i < K; ++i) {
		cin >> ini >> ttl;
		Redes redes(grafo, ini - 1);
		cout << redes.getInaccesibles(ttl) << "\n";
	}
	cout << "---\n";
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