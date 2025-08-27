#include "vector"
#include "graph.h"
using namespace std;

Graph montar_grafo(const vector<pair<int, int>> &pecas, int max) {
    Graph grafo(max + 1);

    // pecas sao bidirecionais
    for (auto [a, b] : pecas) {
        grafo.edge(a, b, 1);
        grafo.edge(b, a, 1);
    }

    return grafo;
}

bool is_euler(const Graph &graph) {
    if( graph.isConnected() == false){return false;}

    int contador_grau = 0;
    int num_nos = graph.size();

    for(int i =0; i < num_nos; i++){
        int grau = graph.degree(i);
        if( grau % 2 != 0){
            contador_grau++;
        }
    }
    if(contador_grau == 0 || contador_grau == 2){
        return true;
    }else{
        return false;
    } 
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