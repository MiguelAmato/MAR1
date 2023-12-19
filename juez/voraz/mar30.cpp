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
    int L;
	cin >> L;
	vector<int> v(N);
	for (int i = 0; i < N; ++i) cin >> v[i];

	int cont = 1, ult = v[0];
	for (int i = 1; i < v.size(); ++i) {
		if (ult + L < v[i]) {
			++cont;
			ult = v[i];
		}
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