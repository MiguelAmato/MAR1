// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez MAR102


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

const int MAX = 10000;


int adyacente(int v, int i) {
	switch(i) {
		case 0:
			return (v + 1) % MAX;
		case 1:
			return (v * 2) % MAX;
		case 2:
			return (v / 3);
	}
}

int bfs(int ini, int fin) {
	if (ini == fin)
		return 0;
	queue<int> q;
	vector<int> distancias
	
	q.push(ini);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int i = 0; i < 3; ++i) {
			int w = adyacente(v, i);

		}
	}
}


bool resuelveCaso() {
    int ini;
	cin >> ini;
    if (!cin)
        return false;
	int fin;
    cin >> fin;
	cout << bfs(ini, fin) << "\n";
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