#include <queue>
#include <set>

#include "graph.h"

// Criação da aresta src --> dst
void Graph::edge(int src, int dst, int w) {
    if (src < 0) throw std::runtime_error("Src invalido");
    if (dst < 0) throw std::runtime_error("Dst invalido");
    if (w   < 0) throw std::runtime_error("Distancia/peso invalido");

    // TO-DO

}

// Grau de saída: src -> dst
int Graph::degree(int src) const {
    if (src < 0 || src >= adj.size()) throw std::runtime_error("Src invalido");

    // TO-DO
}

list<int> Graph::neighbors(int src) const {
    if (src < 0 || src >= adj.size()) throw std::runtime_error("Src invalido");

    // TO-DO

}

int Graph::weight(int src, int dst) const {
    if (src < 0 || src >= adj.size()) throw std::runtime_error("Src invalido");
    if (dst < 0 || dst >= adj.size()) throw std::runtime_error("Dst invalido");

    // TO-DO

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
	// TO-DO

	return false;
}

// -------- PRAT 09 --------------//

// Busca em profundidade
list<int> Graph::dfs(int src) {
    if (src < 0 || src >= adj.size())
        throw std::runtime_error("Src invalido");

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

    vector<int> prev(adj.size(), -1);     // vértices anteriores
    vector<long> dist(adj.size(), 99999); // distâncias acumuladas; 99999 = INF

    dijkstra(src, prev, dist);

    list<int> result;	                  // retorno menor caminho

    path(dst, prev, result);	          // extrair caminho em result

    return result;
}


void Graph::path(int dst, const vector<int> &prev, list<int> &result) {
	// TO-DO
}


