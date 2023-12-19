// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez MAR102

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Grafo.h"
using namespace std;

class ManchasNegras {
	public:
		ManchasNegras(vector<vector<char>> matriz, int F, int C) : _row(F), _col(C), visit(F, vector<bool>(C, false)) {
			for (int i = 0; i < _row; ++i) {
				for (int j = 0; j < _col; ++j) {
					if (!visit[i][j] && matriz[i][j] == '#') {
						int act = dfs(matriz, i, j);
						_max = std::max(act, _max);
						++_num;
					}
				}
			}
		}

		int num() {
			return _num;
		}

		int max() {
			return _max;
		}

	private:

		int _row, _col, _num = 0, _max = 0;
		const vector<pair<int, int>> movimientos = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
		vector<vector<bool>> visit;

		bool esCorrecta(int i, int j) {
			return (i >= 0 && i < _row && j >= 0 && j < _col);
		}

		int dfs(const vector<vector<char>>& matriz, const int& i, const int& j) {
			int ret = 1;
			visit[i][j] = true;
			for (pair<int, int> p : movimientos) {
				int ni = i + p.first, nj = j + p.second;
				if (esCorrecta(ni, nj) && matriz[ni][nj] == '#' && !visit[ni][nj]) {
					ret += dfs(matriz, ni, nj);
				}
			}
			return ret;
		}
};

bool resuelveCaso() {
    int row;
	cin >> row;
    if (!cin)
        return false;
	int col;
	cin >> col;
	vector<vector<char>> matriz(row, vector<char>(col));
	char c;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; j++) 
			cin >> matriz[i][j];
	}
	ManchasNegras mn(matriz, row, col);
	cout << mn.num() << " " << mn.max() << "\n";
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