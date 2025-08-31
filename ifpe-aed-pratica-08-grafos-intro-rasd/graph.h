#include <iostream>
#include <list>
#include <vector>
#include <map>

using namespace std;

// Implementa um grafo direcionado simples.
class Graph {
private:
    // ATENCAO:
    // Esse codigo assume que todos os vertices de 0 ateh (adj.size() - 1) existem no grafo.
    // Isto eh, nao pode haver uma grafo com vertices 0, 1 e 3, 4.
    // O vertice 2 eh assumido que existe tambem nesse caso.
    // Isso tem impacto, por exemplo, em determinar se o grafo eh conexo.
	 vector<list<pair<int, int>>> adj;

public:
	Graph(int size) : adj(size) {}
	~Graph() = default;

	int size() const { return (int)adj.size(); }	// retorna n�mero de v�rtices

	// Pr�tica 08 - TO-DO
	void edge(int src, int dst, int w);	// Cria src -> dst com peso w
	int degree(int vtx) const;                // retorna grau de um v�rtice
    list<int> neighbors(int vtx) const;	    // retorna lista de vertices ligados a src
    int weight(int src, int dst) const;	    // retorna peso da aresta de src para dst
	bool isConnected() const;

	// Pr�tica 09 - TO-DO (abaixo)
	list<int> dfs(int src); // Busca em profundidade
	list<int> bfs(int src); // Busca em largura
	list<int> spf(int src, int dst); // Menor caminho entre src e dst

	bool has_cycle();			// Verifica se o grafo TEM QUALQUER ciclo
    bool has_cycle(int src);   // Verifica se há um ciclo A PARTIR de src
	bool reachable(int src, int dst); // Verifica se dst é alcançável a partir de src

	void print(); // Exibe o grafo

private:
	// Pr�tica 09 - TO DO
	void DFS(int src, vector<bool> &visited, list<int> &result); // DFS de fato
	void BFS(int src, vector<bool> &visited, list<int> &result); // BFS de fato
    void dijkstra(int src, vector<int> &prev, vector<long> &dist); // acha os menores caminhos
    void path(int src, const vector<int> &prev, list<int> &result); // extrai menor caminho de prev
	bool has_cycle(int src, vector<int> &visited); // Usaremos int para 3 estados

};




