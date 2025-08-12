
#include "graph.h"


Graph montar_grafo(const vector<pair<int, int>> &pecas, int max) {
    Graph grafo(max + 1);

    // pecas são bidirecionais
    for (auto [a, b] : pecas) {
        grafo.edge(a, b, 1);
        grafo.edge(b, a, 1);
    }

    return grafo;
}

bool is_euler(const Graph &graph) {
    // TODO
    return false;    
}

int main() {

    vector<pair<int, int>> pecas1 = {{0, 1}, {1, 2}, {1, 0}, {3, 2}, {2, 1}};
    vector<pair<int, int>> pecas2 = {{0, 1}, {1, 2}, {1, 0}, {3, 2}, {2, 3}, {0, 4}};

    Graph grafo1 = montar_grafo(pecas1, 3);
    Graph grafo2 = montar_grafo(pecas2, 4);

    cout << "Pecas 1: " << (is_euler(grafo1)?"Sim":"Nao") << endl; // Sim
    cout << "Pecas 2: " << (is_euler(grafo2)?"Sim":"Nao") << endl; // Nao

    return 0;
}