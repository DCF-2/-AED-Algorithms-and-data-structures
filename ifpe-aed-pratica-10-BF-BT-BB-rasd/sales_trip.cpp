#include <vector>
#include <iostream>
#include <ranges>

using namespace std;

int max_profit(const vector<int> &costs, const vector<int> &sales)
{
    vector<int> lucro_diario;

    for (int i = 0; i < costs.size(); i++)
    {
        lucro_diario.push_back(sales[i] - costs[i]);
    }

    int maior_lucro = INT_MIN;
    for (int i = 0; i < lucro_diario.size(); i++)
    {
        for (int j = i; j < lucro_diario.size(); j++)
        {
            int lucro_atual = 0;
            for (int k = i; k <= j; k++)
            {
                lucro_atual = lucro_atual + lucro_diario[k];
            }
            if (lucro_atual > maior_lucro)
            {
                maior_lucro = lucro_atual;
            }
        }
    }
    return maior_lucro;
}

int main()
{
    vector<int> costs = {10, 22, 15, 20, 18, 16, 14, 12, 10};
    vector<int> sales = {17, 12, 21, 15, 25, 40, 34, 20, 5};

    cout << "Max profit = " << max_profit(costs, sales) << endl; // 60

    return 0;
}