#include <vector>
#include <iostream>

using namespace std;

class Solution {

public:

    int coinChange(const vector<int>& coins, int amount) {
        int infinity = amount +1;
        vector<int>tabela(amount +1, infinity);

        tabela[0] = 0;

        for (int valor_atual = 1; valor_atual <= amount; valor_atual++) {
        for (int moeda : coins) {
            if (moeda <= valor_atual) {
                int solucao_com_esta_moeda = 1 + tabela[valor_atual - moeda];
                tabela[valor_atual] = min(tabela[valor_atual], solucao_com_esta_moeda);
            }
        }
    }
    if (tabela[amount] > amount) {
        return -1;
    } else {
        return tabela[amount];
    }
}

    
};

int main() {

    cout << Solution().coinChange({1, 2, 5}, 11) << endl; // res = 3
    cout << Solution().coinChange({1, 6, 7, 9, 11}, 13) << endl; // res = 2
    cout << Solution().coinChange({1, 2, 5, 10}, 16) << endl; // res = 3
    cout << Solution().coinChange({1, 2, 7, 10}, 16) << endl; // res = 3 (greedy = 4)
    cout << Solution().coinChange({1,2,5,7,8,4}, 30) << endl; // res = 4
    cout << Solution().coinChange({83, 186, 408, 419}, 6249) << endl; // res = 20

    return 0;
}