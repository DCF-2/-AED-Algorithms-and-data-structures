#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item
    {
       int peso;
       int preco;
       double razao;
    };

float solve(const vector<int> &price, const vector<int> &weight, int k) {
    int n = price.size();
    vector<Item> itens(n);

    for(int i = 0; i < n; i++){
        itens[i].peso = weight[i];
        itens[i].preco = price[i];
        itens[i].razao = (double)price[i] / weight[i];
    }

    sort(itens.begin(), itens.end(), [](const Item& a, const Item& b){
        return a.razao > b.razao;
    });

    int capacidade_rest = k;
    double valor_total = 0.0;

    for(int i = 0 ; i <n; i++){
        if(capacidade_rest == 0){
            break;
        }
        int quantidade__a_pegar = min(itens[i].peso, capacidade_rest);
        int valor_ganho = quantidade__a_pegar * itens[i].razao;
        valor_total = valor_total + valor_ganho;
        capacidade_rest -= quantidade__a_pegar;
    }
    return valor_total;
}

int main() {
    vector<int> precos = {100, 10 , 10, 100, 50};
    vector<int> pesos  = {50, 50, 100, 20, 10};
    int K = 100;

    float res = solve(precos, pesos, K);

    cout << res << endl; // 254

    return 0;
    }


