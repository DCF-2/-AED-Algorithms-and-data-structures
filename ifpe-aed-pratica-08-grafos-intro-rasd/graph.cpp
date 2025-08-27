#include <queue>
#include <set>
#include <vector>

#include "graph.h"

using namespace std;

// Cria��o da aresta src --> dst
void Graph::edge(int src, int dst, int w) {
    if (src < 0) throw runtime_error("Src invalido");
    if (dst < 0) throw runtime_error("Dst invalido");
    if (w   < 0) throw runtime_error("Distancia/peso invalido");
    adj[src].push_back({dst, w});
}

// Grau de sa�da: src -> dst
int Graph::degree(int src) const {
    if (src < 0 || src >= adj.size()) throw runtime_error("Src invalido");
    return adj[src].size();
}

list<int> Graph::neighbors(int src) const {
    if (src < 0 || src >= adj.size()) throw runtime_error("Src invalido");
    list<int>result;
    for(const auto& par : adj[src]){
        result.push_back(par.first);
    }
    return result;
}

int Graph::weight(int src, int dst) const {
    if (src < 0 || src >= adj.size()) throw runtime_error("Src invalido");
    if (dst < 0 || dst >= adj.size()) throw runtime_error("Dst invalido");

    for(const auto& par: adj[src]){
        if(par.first == dst){
            return par.second;
        }
    }
    return -1;
}

void Graph::print() {
	for (int i = 0; i < this->size(); i++) {
		int d = this->degree(i);
		cout << i << "(" << d << "): ";
		list<int> nei = this->neighbors(i);
		for (int dst : nei) {
			int w = this->weight(i, dst);
			cout << dst << "[" << w << "]; ";
		}
		cout << endl;
	}
}


bool Graph::isConnected() const {
	int numero_nos = this->size();
    if (numero_nos <= 1) {return true;}
    vector<int> grupos(numero_nos);

     for (int i = 0; i < numero_nos; i++) {
        grupos[i] = i;
    }

    for (int origem = 0; origem < numero_nos; origem++) {
        for (const auto& par : adj[origem]) {
            int destino = par.first;
            int grupo_da_origem = grupos[origem];
            int grupo_do_destino = grupos[destino];
            if (grupo_da_origem != grupo_do_destino) {
                for (int j = 0; j < numero_nos; j++) {
                    if (grupos[j] == grupo_do_destino) {
                        grupos[j] = grupo_da_origem;
                    }
                }
            }
        }
    }
    int grupo_referencia = grupos[0];
    for(int i = 1; i < numero_nos; i++){
        if(grupos[i] != grupo_referencia){
            return false;
        }
    }
	return true;
}

// -------- PRAT 09 --------------//

// Busca em profundidade
list<int> Graph::dfs(int src) {
    if (src < 0 || src >= adj.size())
        throw runtime_error("Src invalido");

	list<int> result;
	vector<bool> visited(adj.size(), false);

	DFS(src, visited, result);

	return result;
}

// Busca em profundidade
void Graph::DFS(int src, vector<bool> &visited, list<int> &result) {
	// TO-DO
}

// Busca em largura
list<int> Graph::bfs(int src) {
    if (src < 0 || src >= adj.size())
        throw std::runtime_error("Src invalido");

    list<int> result;
    vector<bool> visited(adj.size(), false);

    BFS(src, visited, result);

    return result;
}

// Busca em largura
void Graph::BFS(int src, vector<bool> &visited, list<int> &result) {
     // TO-DO
}


void Graph::dijkstra(int src, vector<int> &prev, vector<long> &dist) {
     // TO-DO
}

list<int> Graph::spf(int src, int dst) {
    if (src < 0 || src >= this->size())
        throw std::runtime_error("Src invalido");

    if (dst < 0 || dst >= this->size())
        throw std::runtime_error("Dst invalido");

    vector<int> prev(adj.size(), -1);     // v�rtices anteriores
    vector<long> dist(adj.size(), 99999); // dist�ncias acumuladas; 99999 = INF

    dijkstra(src, prev, dist);

    list<int> result;	                  // retorno menor caminho

    path(dst, prev, result);	          // extrair caminho em result

    return result;
}


void Graph::path(int dst, const vector<int> &prev, list<int> &result) {
	// TO-DO
}


