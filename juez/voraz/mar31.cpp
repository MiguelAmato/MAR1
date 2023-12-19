// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez MAR102

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


bool resuelveCaso() {
	int N;
	cin >> N;
	if (!cin)
		return false;
	vector<int> enemigos(N), defensas(N);
	for (int i = 0; i < N; ++i) cin >> enemigos[i];
	for (int i = 0; i < N; ++i) cin >> defensas[i];
	sort(enemigos.begin(), enemigos.end(), greater<int>());
	sort(defensas.begin(), defensas.end(), greater<int>());

	int e = 0, d = 0, cont = 0;
	while (d < N && e < N) {
		if (defensas[d] >= enemigos[e]) 
			++d, ++e, ++cont;
		else 
			++e;
	}
	cout << cont << "\n";
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