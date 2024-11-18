#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

const int MAX_VERTICES = 100;
int graph[MAX_VERTICES][MAX_VERTICES];
int n, m;

bool isAntisymmetric() {
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (u != v && graph[u][v] == 1 && graph[v][u] == 1) {
                return false;
            }
        }
    }
    return true;
}



bool isTransitive() {
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (graph[u][v] == 1) {
                for (int w = 0; w < n; w++) {
                    if (graph[v][w] == 1 && graph[u][w] == 0) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ifstream inputFile("in.txt");

    if (!inputFile) {
        cerr << "Error opening input file!" << endl;
        return 1;
    }

    inputFile >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        inputFile >> u >> v;
        u--; v--;
        graph[u][v] = 1;
    }

    inputFile.close();

    if (isAntisymmetric()) {
        cout << "Відношення антисиметричне." << endl;
    }
    else {
        cout << "Відношення не антисиметричне." << endl;
    }

    if (isTransitive()) {
        cout << "Відношення транзитивне." << endl;
    }
    else {
        cout << "Відношення не транзитивне." << endl;
    }

    return 0;
}
