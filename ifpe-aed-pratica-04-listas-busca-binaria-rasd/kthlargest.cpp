#include <iostream>
#include <vector>
#include "lista.h" 
 
class KthLargest { 
   private:
   int k;
   ListaOrdenada<int> scores;

public: 
    KthLargest(int k, vector<int>& nums) : k(k), scores(10000) { 
       //this.k = k;
       for (int num : nums) {
            scores.adicionar(num);
        }
    }
 
    int add(int val) { 
       scores.adicionar(val);
   return scores[scores.tamanho()- k + 1];
    }
    
};
 
int main() { 
    vector<int> nums = {4, 5, 8, 2}; 
    vector<int> vals = {3, 5, 10, 9, 4}; 
    KthLargest kthLargest (3, nums); 
 
    for (int v : vals) { 
        cout << "Adicionando " << v << ", 3o maior eh " << kthLargest.add(v) 
<< endl; 
    }
    return 0;
} 

// implementado no leetcode.
/**
 #include <vector>
#include <queue> // Necessário para a priority_queue

class KthLargest {
private:
    int k;
    // Criamos uma min-heap. Em C++, isto é uma priority_queue que armazena
    // inteiros, usa um vector como container e compara com 'greater' para
    // que o menor elemento fique no topo.
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

public:
    KthLargest(int k, std::vector<int>& nums) {
        this->k = k;
        // Adiciona os números iniciais à heap
        for (int num : nums) {
            this->add(num);
        }
    }

    int add(int val) {
        // Adiciona o novo valor à heap
        min_heap.push(val);

        // Se a heap ficar maior que k, removemos o menor elemento
        // para garantir que só guardamos os k maiores.
        if (min_heap.size() > k) {
            min_heap.pop();
        }

        // O k-ésimo maior elemento é sempre o que está no topo da min-heap.
        return min_heap.top();
    }
};
 */
