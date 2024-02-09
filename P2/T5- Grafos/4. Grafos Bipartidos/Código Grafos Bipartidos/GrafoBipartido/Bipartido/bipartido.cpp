#include <iostream>
#include <vector>
using namespace std;

bool esBipartidoUtil(vector<vector<int>>& grafo, int v, vector<int>& color, int c) {
    color[v] = c;
    for (int i = 0; i < grafo[v].size(); ++i) {
        if (color[grafo[v][i]] == -1) {
            if (!esBipartidoUtil(grafo, grafo[v][i], color, 1 - c)) {
                return false;
            }
        } else if (color[grafo[v][i]] == c) {
            return false;
        }
    }
    return true;
}

bool esBipartido(vector<vector<int>>& grafo, int V) {
    vector<int> color(V, -1);
    for (int i = 0; i < V; ++i) {
        if (color[i] == -1) {
            if (!esBipartidoUtil(grafo, i, color, 0)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int V, E;
    cout << "Ingrese el numero de vertices y aristas: ";
    cin >> V >> E;

    vector<vector<int>> grafo(V);
    cout << "Ingrese las aristas en el formato (u v): \n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }
    /*
    Ingrese numero de aristas: 4 4
    Ingrese las aristas en el formato (u v): 
    0 1
    1 2
    2 3
    3 0*/

    if (esBipartido(grafo, V)) {
        cout << "El grafo es bipartido." << endl;
    } else {
        cout << "El grafo no es bipartido." << endl;
    }

    return 0;
}
